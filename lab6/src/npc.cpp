#include "../include/npc.h"

NPC::NPC(){
    _position = std::make_pair(0,0);
}

NPC::NPC(int x, int y){
    _position = std::make_pair(x, y);
}

void NPC::set_position(int x, int y){
    _position = std::make_pair(x, y);
}

std::pair<int, int> NPC::position() const{
    return _position;
}



void NPC::die(){
    _alive = false;
}

NPC_type NPC::type() const{
    return _type;
}

bool NPC::alive() const{
    return _alive;
}

std::ostream& operator<<(std::ostream& os, const NPC* npc){
    npc->print(os);
    return os;
}
std::ofstream& operator<<(std::ofstream& os, const NPC* npc){
    npc->print(os);
    return os;
}