#include "../include/board.h"

Board::Board(){
    this->attach(new ConsoleObserver);

    FileObserver* fo = new FileObserver;
    this->attach(fo);
}

Board::~Board(){
    for(auto elem : observer_list){
        delete elem;
    }
}



void Board::add_npc(int type, int x, int y){
    factory* factory;
    switch(type){
        case KNIGHT:
            factory = new knight_factory;
            break;
        case ELF:
            factory = new elf_factory;
            break;
        case DRAGON:
            factory = new dragon_factory;  
            break;
        default:
            throw std::invalid_argument("invalid npc type");
    }
    NPC* new_npc = factory->create(x, y);
    npc_list.push_back(new_npc);
}

void Board::print(){
    for (auto elem : npc_list){
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

void Board::file_save(const char* filename){
    std::ofstream file(filename);
    for(auto elem : npc_list){
        file << elem->type() << ' ' << elem->position().first << ' ' << elem->position().second << '\n';
    }
    file.close();
}

void Board::file_load(const char* filename){
    npc_list.clear();
    std::ifstream file(filename);
    int type;
    int x, y;
    while(true){
        file >> type >> x >> y;
        if(file.eof()) break;
        this->add_npc(type, x, y);
    }
}

void Board::fight(int distance){
    ConcreteVisitor visitor;
    for(auto attacker = npc_list.begin(); attacker != npc_list.end(); attacker++){
        for(auto defender = npc_list.begin(); defender != npc_list.end(); defender++){

            std::pair<int, int> attacker_position = (*attacker)->position();
            std::pair<int, int> defender_position = (*attacker)->position();
            int x_dif = attacker_position.first - defender_position.first;
            int y_dif = attacker_position.second - defender_position.second;

            if(attacker != defender && x_dif <= distance && y_dif <= distance && (*defender)->alive()){
               (*attacker)->accept(visitor, *defender);
                if(!(*defender)->alive()){
                    notify(*attacker, *defender);
                }   
            }
        }
    }

    npc_list.remove_if([](NPC* npc){return !npc->alive();});
    
}

void Board::attach(Observer* observer){
    observer_list.push_back(observer);
}

void Board::detach(Observer* observer){
    observer_list.remove(observer);
}

void Board::notify(const NPC* attacker, const NPC* defender){
    for(auto elem : observer_list){
        elem->update(attacker, defender);
    }
}
