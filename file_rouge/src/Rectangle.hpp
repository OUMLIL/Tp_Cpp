#pragma once

#include <iostream>
#include <sstream>
#include "Forme.hpp"

class Rectangle : public Forme {

    private:
        int ordre{0};
    public:
        Rectangle(Point p, Couleurs c, int width, int height);
        Rectangle();
        std::string toString() override;
        Rectangle * clone() override;
};