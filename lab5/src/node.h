#pragma once

template<class T>
class Node{
    public:
    T value;
    Node* next;

    Node();

    Node(T value);

    ~Node();

};


template<class T>
Node<T>::Node(){
    next = nullptr;
}

template<class T>
Node<T>::Node(T value){
    this->value = value;
}

template<class T>
Node<T>::~Node(){
    next = nullptr;
}
