#include "include/board.h"

int main(){
    
    Board board;
    board.add_npc(ELF, 1, 2);
    board.add_npc(DRAGON, 1, 3);
    board.add_npc(DRAGON, 1, 2);
    board.file_save("cock");
    //cout << boars
    board.print();
    board.fight(100);
    board.print();
    board.file_load("cock");
    board.print();
    board.file_load("cock");
    board.print();

/*
   std::vector<NPC*> vector {new Dragon, new Elf};
   for(NPC* npc : vector){
    std::cout << npc << '\n';
   }
   */
}