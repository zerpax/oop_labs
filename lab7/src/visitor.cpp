#include "../include/concrete_visitor.h"

void ConcreteVisitor::fight(NPC* attacker, NPC* defender){
    std::cout << "someone fought\n";
}
void ConcreteVisitor::fight(Dragon* attacker, NPC* defender){
    defender->die();
}

void ConcreteVisitor::fight(Knight* attacker, NPC* defender){  
    if(defender->type() == DRAGON){
        defender->die();
    }  
} 

void ConcreteVisitor::fight(Elf* attacker, NPC* defender){
    if(defender->type() == KNIGHT){
        defender->die();
    } 
}

