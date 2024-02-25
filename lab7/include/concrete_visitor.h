#pragma once

#include "../include/visitor.h"
#include "../include/dragon.h"
#include "../include/elf.h"
#include "../include/knight.h"

class ConcreteVisitor : public FightVisitor{
    public:
        void fight(NPC* attacker, NPC* defender) override;
        void fight(Dragon* attacker, NPC* defender) override;
        void fight(Knight* attacker, NPC* defender) override;
        void fight(Elf* attacker, NPC* defender) override;
};