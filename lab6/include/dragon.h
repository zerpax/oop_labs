#pragma once

#include "npc.h"


class Dragon : public NPC {
    public:
        Dragon();
        void accept(FightVisitor& visitor, NPC* defender) override;
        void print(std::ostream& os) const;
        void print(std::ofstream& os) const;
        
};

class dragon_factory : public factory{
    Dragon* create() override;
    Dragon* create(int x, int y) override;
};

