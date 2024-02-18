#include "../include/knight.h"

Knight::Knight(){
    _type = KNIGHT;
}

Knight* knight_factory::create(){
    return new Knight;
}

void Knight::accept(FightVisitor& visitor, NPC* defender){
    visitor.fight(this, defender);
}

Knight* knight_factory::create(int x, int y){
    Knight* knight = new Knight;
    knight->set_position(x, y);
    return knight;
}

void Knight::print(std::ostream& os) const{
    os << "Knight";
}

void Knight::print(std::ofstream& os) const{
    os << "Knight";
}
