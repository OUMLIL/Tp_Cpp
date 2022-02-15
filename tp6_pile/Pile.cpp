#include "pile.hpp"

//constructeurs
Pile::Pile(int stacklen): stack_len(stacklen) {
    
    if(stack_len <= 0) throw std::invalid_argument("invalid args : capacity must be >= 0");
    try {
        tab = new int[stack_len];
    } catch (std::bad_alloc & e) {
        e.what();
        delete[] tab;
        tab = nullptr;
        throw;
    }
}

//destructeur
Pile::~Pile() {
    delete[] tab;
}

//methods
bool Pile::empty() {
    //if(!stack_len) throw std::invalid_argument("empty stack");
    return tail == -1;
}

void Pile::full() {
    if(tail == (stack_len - 1) ) {
        throw fullStackException{};
    }
}

int Pile::push(int element) {
    //exception if stack full
    this->full();
    tail = tail + 1;
    capacity++;
    tab[tail] = element;
    return 0; //push ok
}

int Pile::pop() {
    if(this->empty()) {
        throw std::invalid_argument("empty stack");
    }
    tail--;
    capacity--;
    return 0; //pop ok
}


int Pile::top() {
    if(this->empty()) throw std::invalid_argument("empty stack");
    return tab[tail];
}

//getters, setters

int Pile::size() {
    return capacity;
}