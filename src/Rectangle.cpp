#include "Rectangle.hpp"


Rectangle::Rectangle(Point p, Couleurs c, int width, int height): Forme(p, c, width, height){

}

Rectangle::Rectangle(): Forme(){

}

std::string Rectangle::toString() {

    std::ostringstream oss;
    int x = this->getPoint().getX();
    int y = this->getPoint().getY();
    int w = this->getLargeur();
    int h = this->getHauteur();
    int o = this->getOrdre();

    oss << "RECTANGLE " << o << " " << x << " " << y << " " << w << " " << h;
    std::string s{oss.str()};

    return s;
}