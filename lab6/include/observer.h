#include <iostream>
#include <fstream>
#include <string>

#include "dragon.h"
#include "elf.h"
#include "knight.h"

class Observer{
    public:
        virtual ~Observer() = default;
        virtual void update(const NPC* attacker, const NPC* defender) = 0;
};

class FileObserver : public Observer{
    private:
        std::ofstream log;
    public:
        FileObserver();
        ~FileObserver();
        void update(const NPC* attacker, const NPC* defender) override;
};

class ConsoleObserver : public Observer{
    public:
        ~ConsoleObserver() = default;
        void update(const NPC* attacker, const NPC* defender) override;
};