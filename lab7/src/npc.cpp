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
    std::lock_guard<std::mutex> lck(mtx);
    _alive = false;
}

NPC_type NPC::type() const{
    return _type;
}

bool NPC::alive() {
    std::lock_guard<std::mutex> lck(mtx);
    return _alive;
}

bool NPC::is_close(NPC* other){
    std::lock_guard<std::mutex> lck(mtx);

    int x_dif = abs(this->position().first - other->position().first);
    int y_dif = abs(this->position().second - other->position().second);
    return (x_dif < this->_attack_dist) && (y_dif < this->_attack_dist);
}

int NPC::move_dist() const{
    return _move_dist;
}

int NPC::attack_dist() const{
    return _attack_dist;
}

void NPC::move(int shift_x, int shift_y, int max_x, int max_y){
    std::lock_guard<std::mutex> lck(mtx);

    int x = this->position().first;
    int y = this->position().second;
    if ((x + shift_x >= 0) && (x + shift_x <= max_x))
        x += shift_x;
    if ((y + shift_y >= 0) && (y + shift_y <= max_y))
        y += shift_y;
    this->set_position(x, y);
}


std::ostream& operator<<(std::ostream& os, const NPC* npc){
    npc->print(os);
    return os;
}
std::ofstream& operator<<(std::ofstream& os, const NPC* npc){
    npc->print(os);
    return os;
}

