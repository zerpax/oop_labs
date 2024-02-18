#include "../include/observer.h"

FileObserver::FileObserver(){
    log.open("log.txt");
}

FileObserver::~FileObserver(){
    log.close();
}

void FileObserver::update(const NPC* attacker, const NPC* defender){
    log << attacker << " killed " << defender << " at " << defender->position().first << ' ' << defender->position().second << '\n';
}

void ConsoleObserver::update(const NPC* attacker, const NPC* defender){
    std::cout << attacker << " killed " << defender << " at " << defender->position().first << ' ' << defender->position().second << '\n';
}