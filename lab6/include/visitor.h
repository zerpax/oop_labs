#pragma once

class NPC;
class Knight;
class Dragon;
class Elf;


class FightVisitor{
    public:
        FightVisitor() = default;
        virtual void fight(NPC* attacker, NPC* defender) = 0;
        virtual void fight(Dragon* attacker, NPC* defender) = 0;
        virtual void fight(Knight* attacker, NPC* defender) = 0;
        virtual void fight(Elf* attacker, NPC* defender) = 0;
};