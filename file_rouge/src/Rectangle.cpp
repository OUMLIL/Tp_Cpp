#include "Rectangle.hpp"


Rectangle::Rectangle(Point p, Couleurs c, int width, int height): Forme(p, c, width, height){

}

Rectangle::Rectangle(): Forme(){

}

std::string Rectangle::toString() {

    std::ostringstream oss;
    const int x = getPoint().getX();
    const int y = getPoint().getY();
    const int w = getLargeur();
    const int h = getHauteur();
    const int o = getOrdre();

    oss << "RECTANGLE " << o << " " << x << " " << y << " " << w << " " << h;
    std::string s{oss.str()};

    return s;
}