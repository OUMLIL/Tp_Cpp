#include "Forme.hpp"

int Forme::nbFormes = 0;

//constructeur
Forme::Forme(Point p, Couleurs c, int w, int h): p(p), color(c), w(w), h(h) {
    id = nbFormes;
    nbFormes = nbFormes + 1;
    ordre = id;
}

Forme::Forme(){
    id = nbFormes;
    nbFormes = nbFormes + 1;
    ordre = id;
}

Point & Forme::getPoint() {
    return p;
}

Couleurs Forme::getCouleur() {
    return color;
}

void Forme::setCouleur(Couleurs c) {
    color = c;
} 

void Forme::setX(int x) {
    p.setX(x);
}

void Forme::setY(int y) {
    p.setY(y);
}

int Forme::getId() {
    return id;
}

int Forme::getHauteur() {
    return h;
}

int Forme::getLargeur() {
    return w;
}

int Forme::getOrdre() {
    return ordre;
}

void Forme::setOrdre(int o) {
    ordre = o;
}

//static variables and methods
int Forme::getNbForme() {
    return nbFormes;
}

int Forme::prochainId() {
    return nbFormes;
}


//destructeur
Forme::~Forme() {
}

