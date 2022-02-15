#pragma once

#include <iostream>
#include <string>

class Pile {

    private:
        int stack_len{0};
        int capacity{0};
        int * tab{nullptr};
        int tail{-1};
    public:
        Pile() = default;
        Pile(int stack_len);
        ~Pile();

        //methods
        bool empty();
        void full();
        int push(int element);
        int pop();
        int top();

        
        //getters
        int size();

        //exceptions
        class fullStackException : public std::exception {
            public:
                fullStackException() = default;
        };

};