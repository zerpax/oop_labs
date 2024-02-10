#include <iostream>
#include <map>

#include "src/allocator.h"
#include "src/node.h"
#include "src/iterator.h"
#include "src/stack.h"


int main()
{
    
    const size_t block_size = 1000; 
    std::map<int, int, std::less<int>,Allocator<std::pair<const int,int>, block_size>> my_map;

    for(int i = 0; i < 1000; i++){
        my_map[i] = i;
    }

    my_map[44] = 0;

    for(int i = 494; i < 603; i++){
        my_map.erase(i);
    }
    
    for(int i = 500; i < 550; i++){
        my_map[i] = i / 2;
    }




    Stack<int> stack;
    stack.push(2);
    stack.push(45);
    stack.push(11);


    for(auto elem : stack){
        std::cout << elem << ' ';
    }

    
    
   
}