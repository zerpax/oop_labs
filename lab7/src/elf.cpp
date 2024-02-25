#include "../include/elf.h"

Elf::Elf(){
    _type = ELF;
    _move_dist = 10;
    _attack_dist = 50;
}

Elf* elf_factory::create(){
    return new Elf;
}

void Elf::accept(FightVisitor& visitor, NPC* defender){
    visitor.fight(this, defender);
}

Elf* elf_factory::create(int x, int y){
    Elf* elf = new Elf;
    elf->set_position(x, y);
    return elf;
}

void Elf::print(std::ostream& os) const{
    os << "Elf";
}

void Elf::print(std::ofstream& os) const{
    os << "Elf";
}


