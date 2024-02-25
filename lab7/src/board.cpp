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
        if(elem->alive())
        std::cout << elem << ' ' << elem->position().first << ' ' << elem->position().second << '\n';
    }
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

void Board::place_rand(){
    for(int i = 0; i < 50;  i++){
        this->add_npc(rand()%3, rand()%MAX_X,rand()%MAX_Y);
    }
}

void Board::fight(){
    std::mutex print_mutex;
    
    std::cout << "fight started\n";

    std::thread fight_thread(std::ref(FightManager::get()));
    
    ConcreteVisitor visitor;

    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
    std::chrono::seconds duration(FIGHT_TIME);
    bool stop = true;

    std::thread move_thread([this, &stop]()
                            {
        while (stop)
        {
            // move phase
            for (auto npc : npc_list)
            {
                    if(npc->alive()){
                        int shift_x = std::rand() % (2*npc->move_dist()) - npc->move_dist();
                        int shift_y = std::rand() % (2*npc->move_dist()) - npc->move_dist();
                        npc->move(shift_x, shift_y, MAX_X, MAX_Y);
                    }
            }
            // lets fight
            for (auto npc : npc_list)
                for (auto other : npc_list)
                    if (other != npc)
                        if (npc->alive())
                        if (other->alive())
                        if (npc->is_close(other))
                            FightManager::get().add_event({npc, other});

            std::this_thread::sleep_for(50ms);
        } });


    

    while (std::chrono::steady_clock::now() - start_time < duration){
        const int grid{20}, step_x{MAX_X / grid}, step_y{MAX_Y / grid};
        {
            std::array<char, grid * grid> fields{0};
            for (auto npc : npc_list)
            {
                auto [x, y] = npc->position();
                int i = x / step_x;
                int j = y / step_y;

                if (npc->alive())
                {
                    switch (npc->type())
                    {
                    case DRAGON:
                        fields[i + grid * j] = 'D';
                        break;
                    case KNIGHT:
                        fields[i + grid * j] = 'K';
                        break;
                    case ELF:
                        fields[i + grid * j] = 'E';
                        break;

                    default:
                        break;
                    }
                }
                else
                    fields[i + grid * j] = '.';
            }

            std::lock_guard<std::mutex> lck(print_mutex);
            for (int j = 0; j < grid; ++j)
            {
                for (int i = 0; i < grid; ++i)
                {
                    char c = fields[i + j * grid];
                    if (c != 0)
                        std::cout << "[" << c << "]";
                    else
                        std::cout << "[ ]";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        std::this_thread::sleep_for(1s);
    }
    stop = false;
    move_thread.join();
    fight_thread.join();    
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

FightManager& FightManager::get()
    {
        static FightManager instance;
        return instance;
    }

void FightManager::add_event(FightEvent &&event)
    {
        std::lock_guard<std::shared_mutex> lock(mtx);
        events.push(event);
    }

void FightManager::operator()()
    {
    ConcreteVisitor visitor;
    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
    std::chrono::seconds duration(FIGHT_TIME+1);

    while (std::chrono::steady_clock::now() - start_time < duration)
        {
            {
                std::optional<FightEvent> event;

                {
                    std::lock_guard<std::shared_mutex> lock(mtx);
                    if (!events.empty())
                    {
                        event = events.back();
                        events.pop();
                    }
                }

                if (event)
                {
                    if (event->attacker->alive()){     // no zombie fighting!
                        if (event->defender->alive()){ // already dead!
                                int atk = std::rand() % 6;
                                int def = std::rand() % 6;
                                if(atk > def){
                                    event->attacker->accept(visitor, event->defender);
                                }
                        }
                    }
                }
                else
                    std::this_thread::sleep_for(100ms);
            }
        }
    }