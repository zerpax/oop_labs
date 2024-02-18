#pragma once

#include <vector>
#include <list>
#include <iostream>
#include <string>

#include "concrete_visitor.h"
#include "dragon.h"
#include "elf.h"
#include "knight.h"
#include "observer.h"




class Board{
    private:
        std::list<NPC*> npc_list;
        std::list<Observer*> observer_list;
    public:
        Board();
        ~Board();
        void add_npc(int type, int x, int y);
        void fight(int distance);
        void print();
        void file_save(const char* filename);
        void file_load(const char* filename);

        void attach(Observer* observer);
        void detach(Observer* observer);
        void notify(const NPC* attacker, const NPC* defender);

};

