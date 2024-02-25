#include "../include/dragon.h"

Dragon::Dragon(){
    _type = DRAGON;
    _move_dist = 50;
    _attack_dist = 30;
}

Dragon* dragon_factory::create(){
    return new Dragon;
}

void Dragon::accept(FightVisitor& visitor, NPC* defender){
    visitor.fight(this, defender);
}

Dragon* dragon_factory::create(int x, int y){
    Dragon* dragon = new Dragon;
    dragon->set_position(x, y);
    return dragon;
}

void Dragon::print(std::ostream& os) const{
    os << "Dragon";
}

void Dragon::print(std::ofstream& os) const{
    os << "Dragon";
}

