#pragma once

#include <iostream>
#include <sstream>
#include "Forme.hpp"

class Cercle : public Forme {

    private:
        int r {0};
        int ordre{0};
    public:
        Cercle(Point p, Couleurs c, int width, int height);
        Cercle();
        std::string toString();
        void setRayon(int r);
        int getRayon();
        Cercle * clone() override; 
};