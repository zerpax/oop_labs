#pragma once

#include "npc.h"

class Knight : public NPC {
    public:
        Knight();
        void accept(FightVisitor& visitor,NPC* defender) override;
        void print(std::ostream& os) const;
        void print(std::ofstream& os) const;
};

class knight_factory : public factory{
    Knight* create() override;
    Knight* create(int x, int y) override;
};