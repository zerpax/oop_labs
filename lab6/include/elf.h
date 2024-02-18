#pragma once

#include "npc.h"

class Elf : public NPC {
    public:
    Elf();
    void accept(FightVisitor& visitor, NPC* defender) override;
    void print(std::ostream& os) const;
    void print(std::ofstream& os) const;
};

class elf_factory : public factory{
    Elf* create() override;
    Elf* create(int x, int y) override;
};