#pragma once

#include <stdexcept>

#include "allocator.h"
#include "iterator.h"

template<class T, class Allocator = Allocator<Node<T>, 50000>>
class Stack{
    private:
        Node<T>* _top;
        Node<T>* _bottom; //to make the application of iterators possible
        Allocator allocator;
        size_t _size;
    public:
        

        Stack();
        ~Stack();
        T top();
        void pop();
        void push(T element);
        size_t size();
        bool empty();
        Iterator<T> begin();
        Iterator<T> end();
};


template<class T, class Allocator>
Stack<T, Allocator>::Stack(){
    _size = 0;
    
    _bottom = nullptr;
    _top = _bottom;
}

template<class T, class Allocator>
Stack<T, Allocator>::~Stack(){
    while(_top != nullptr){
        pop();
    }
}

template<class T, class Allocator>
T Stack<T, Allocator>::top(){
    if(empty()){
        throw std::out_of_range("can not get the top element from an empty stack\n");
    }
    return _top->value;
}

template<class T, class Allocator>
void Stack<T, Allocator>::pop(){
    if(empty()){
        throw std::out_of_range("can not remove elements from an empty stack\n");
    }
    else{
        Node<T>* temp = _top;
        _top = _top->next;
        allocator.destroy(temp);
        allocator.deallocate(temp, 1);
        _size--;
    }
    
}

template<class T, class Allocator>
void Stack<T, Allocator>::push(T element){
    Node<T>* new_node = allocator.allocate(1);
    allocator.construct(new_node, element);
    new_node->next = _top;
    _top = new_node;
    _size++;
}

template<class T, class Allocator>
size_t Stack<T, Allocator>::size(){
    return _size;
}
 
template<class T, class Allocator>
bool Stack<T, Allocator>::empty(){
    if(_size == 0){
        return true;
    }
    return false;
}

template<class T, class Allocator>
Iterator<T> Stack<T, Allocator>::end(){
    return _bottom;
}


template<class T, class Allocator>
Iterator<T> Stack<T, Allocator>::begin(){
    return _top;
}