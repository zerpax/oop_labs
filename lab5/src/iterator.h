#pragma once

#include "node.h"

template<class T>
class Iterator{
    private:
        Node<T>* elem;
    public:
        Iterator();
        ~Iterator();
        Iterator(const Iterator<T>& other);
        Iterator(Node<T>* ptr);

        Iterator<T> operator++(int);

        bool operator==(const Iterator<T>& other);

        bool operator!=(const Iterator<T>& other);

        void operator=(const Iterator<T>& other);

        template<class Type>
        friend Iterator<Type> operator++(Iterator<Type>& iterator);

        template<class Type>
        friend Type operator*(const Iterator<Type>& iterator);
};


template<class T>
Iterator<T>::Iterator(){
    elem = nullptr;
}

template<class T>
Iterator<T>::~Iterator(){
    elem = nullptr;
}

template<class T>
Iterator<T>::Iterator(const Iterator<T>& other){
    elem = other.elem;
}

template<class T>
Iterator<T>::Iterator(Node<T>* ptr){
    elem = ptr;
}

template<class T>
Iterator<T> Iterator<T>::operator++(int){
    elem = elem->next;
    return *this;
}

template<class T>
bool Iterator<T>::operator!=(const Iterator<T>& other){
    return elem != other.elem;
}

template<class T>
bool Iterator<T>::operator==(const Iterator<T>& other){
    return elem == other.elem;
}

template<class T>
void Iterator<T>::operator=(const Iterator<T>& other){
    elem = other.elem;
}

template<class T>
Iterator<T> operator++(Iterator<T>& iterator){
    iterator.elem = iterator.elem->next;
    return iterator;
}

template<class T>
T operator*(const Iterator<T>& iterator){
    if(iterator.elem == nullptr){
        throw std::out_of_range("Iterator out of range");
    }
    return iterator.elem->value;
}