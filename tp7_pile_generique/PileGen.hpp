#pragma once

#include <iostream>

template <typename T>
class PileGen {
    private:
        int stack_len{0};
        int capacity{0};
        T * tab{nullptr};
        int tail{-1};
    public:
        PileGen() = default;

        PileGen(int stacklen): stack_len(stacklen) {
            if(stack_len <= 0) throw std::invalid_argument("invalid args : capacity must be >= 0");
            try {
                tab = new T[stack_len];
            } catch (std::bad_alloc & e) {
                tab = nullptr;
                throw;
            }
        }

        PileGen(const PileGen & p) {
            
            stack_len = p.stack_len;
            capacity = p.capacity;
            try {
                tab = new T[stack_len];
            } catch (std::bad_alloc & e) {
                tab = nullptr;
                throw;
            }
            std::copy(p.tab, p.tab+stack_len, tab);
        }

        ~PileGen(){
            delete[] tab;
        }

        bool isEmpty(){
            //if(!stack_len) throw std::invalid_argument("empty stack");
            return tail == -1;
        }

        void full(){
            if(tail == (stack_len - 1) ) {
                throw fullStackException{};
            }
        }

        void push(const T & element) {
    
            this->full(); //throws exception if stack full
            tail = tail + 1;
            capacity++;
            tab[tail] = element;
        }

        const T & top() {
            if(this->isEmpty()) throw std::invalid_argument("empty stack");
            return tab[tail];
        }

        void pop() {
            if(this->isEmpty()) {
                throw std::invalid_argument("empty stack");
            }
            tail--;
            capacity--;
        }
        

        
        //getters
        int size() {
            return capacity;
        }

        //exceptions
        class fullStackException : public std::exception {
            public:
                fullStackException() = default;
        };
};

