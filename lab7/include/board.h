#pragma once

#include <list>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <thread>
#include <shared_mutex>
#include <memory>
#include <optional>
#include <chrono>

#include "concrete_visitor.h"
#include "dragon.h"
#include "elf.h"
#include "knight.h"
#include "observer.h"

const int MAX_X{100};
const int MAX_Y{100};
const int FIGHT_TIME{30};


using namespace std::chrono_literals;

class Board{
    private:
        std::list<NPC*> npc_list;
        std::list<Observer*> observer_list;
    public:
        Board();
        ~Board();

        void add_npc(int type, int x, int y);
        void place_rand();
        void fight();
        void print();

        void file_save(const char* filename);
        void file_load(const char* filename);

        void attach(Observer* observer);
        void detach(Observer* observer);
        void notify(const NPC* attacker, const NPC* defender);

};

struct FightEvent
{
    NPC* attacker;
    NPC* defender;
};

class FightManager
{
private:
    std::queue<FightEvent> events;
    std::shared_mutex mtx;

    FightManager() {}

public:
    static FightManager &get();

    void add_event(FightEvent &&event);

    void operator()();
};