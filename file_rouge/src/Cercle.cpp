#include "Cercle.hpp"

Cercle::Cercle(Point p, Couleurs c, int width, int height):
                Forme(p, c, width, height) {

}

Cercle::Cercle():Forme() {

}



std::string Cercle::toString() {

    std::ostringstream oss;
    int x = this->getPoint().getX();
    int y = this->getPoint().getY();
    int w = this->getLargeur();
    int h = this->getHauteur();
    int o = this->getOrdre();
    oss << "CERCLE " << o << " " << x << " " << y << " " << w << " " << h;
    std::string s{oss.str()};

    return s;
}


Cercle * Cercle::clone() {

    Cercle * cercle_copy = new Cercle(*this);
    return cercle_copy;
}