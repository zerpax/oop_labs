#include "include/board.h"

int main(){
    
    Board board;
    board.place_rand();
    board.fight();
    board.print();
/*
   std::vector<NPC*> vector {new Dragon, new Elf};
   for(NPC* npc : vector){
    std::cout << npc << '\n';
   }
   */
}