#include "Point.hpp"

Point::Point(int xp, int yp): x(xp), y(yp) {

}

Point::Point() {

}

void Point::setX(int xp) {
    x = xp;
}

void Point::setY(int yp) {
    y = yp;
}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

Point ORIGINE;