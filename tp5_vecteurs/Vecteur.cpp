#include "Vecteur.hpp"
#include <iostream>

Vecteur::Vecteur(): capacite(10), nbElements(0) {

    try {
        tab = new double[10];
    } catch(std::bad_alloc &e) {
        e.what();
        delete[] tab;
        tab = nullptr;
        capacite = -1;
        throw;
    }
}

Vecteur::Vecteur(int cap): capacite(cap), nbElements(0) {

    try {
        tab = new double[cap];
    } catch(std::bad_alloc &e) {
        e.what();
        delete[] tab;
        tab = nullptr;
        capacite = -1;
        throw;
    }
}

Vecteur::~Vecteur() {
    delete[] tab;
}


void Vecteur::push_back(double element) {
    double * tmp = nullptr;
    if(nbElements == capacite) {
        try {
            tmp = new double[2*capacite];
            std::copy(tab, tab+nbElements, tmp);
            delete[] tab;
            tab = tmp;
            capacite = 2*capacite;
        } catch(std::bad_alloc &e) {
            e.what();
            delete[] tmp;
            throw;
        }
    }
    tab[nbElements] = element;
    nbElements = nbElements + 1;
}





double & Vecteur::operator[](int id) {
    if(id < 0 || id > nbElements) {
        throw OutOfRangeException();
    } 
    return tab[id];
}

double const & Vecteur::operator[](int id) const {
    if(id < 0 || id > nbElements) {
        throw OutOfRangeException();
    } 
    return tab[id];
}

const char * Vecteur::OutOfRangeException::what() const noexcept {
    const char * err = "out of range exception";
    return err;
}


int Vecteur::capacity() const {
    return capacite;
}

int Vecteur::size() const {
    return nbElements;
}