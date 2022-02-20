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
                e.what();
                delete[] tab;
                tab = nullptr;
                throw;
            }
        }

        ~PileGen(){
            delete[] tab;
        }

        bool empty(){
            //if(!stack_len) throw std::invalid_argument("empty stack");
            return tail == -1;
        }

        void full(){
            if(tail == (stack_len - 1) ) {
                throw fullStackException{};
            }
        }

        int push(const T & element) {
    
            this->full(); //throws exception if stack full
            tail = tail + 1;
            capacity++;
            tab[tail] = element;
            return 0; //push ok
        }

        const T & top() {
            if(this->empty()) throw std::invalid_argument("empty stack");
            return tab[tail];
        }

        int pop() {
            if(this->empty()) {
                throw std::invalid_argument("empty stack");
            }
            tail--;
            capacity--;
            return 0; //pop ok
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

