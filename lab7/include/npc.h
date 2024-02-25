#pragma once

#include <utility>
#include <string>
#include <iostream>
#include <fstream>
#include <mutex>

#include "visitor.h"

enum NPC_type {KNIGHT = 0, ELF = 1, DRAGON = 2};

class NPC{
    private:
        std::mutex mtx;

        std::pair<int, int> _position;
        bool _alive = 1;
    protected:
        NPC_type _type;  
        int _move_dist;
        int _attack_dist;   
    public:
        NPC();
        NPC(int x, int y);

        void set_position(int x, int y);
        std::pair<int, int> position() const;
        virtual void print(std::ostream& os) const = 0;
        virtual void print(std::ofstream& os) const = 0;
        virtual void accept(FightVisitor& visitor, NPC* defender) = 0;
        void die();
        NPC_type type() const;
        bool alive();
        bool is_close(NPC* other);
        int move_dist() const;
        int attack_dist() const;
        void move(int shift_x, int shift_y, int max_x, int max_y);

        friend std::ostream& operator<<(std::ostream& os, const NPC* npc);
        friend std::ofstream& operator<<(std::ofstream& os, const NPC* npc);
};

class factory{
    public:
        virtual NPC* create() = 0;
        virtual NPC* create(int x, int y) = 0;
};