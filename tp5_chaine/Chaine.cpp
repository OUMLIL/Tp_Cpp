#include "Chaine.hpp"
#include <cstring>


Chaine::Chaine(): capacite(-1), tab(nullptr) {

}

Chaine::Chaine(const char * inCS) {
    capacite = strlen(inCS);
    alloc(capacite + 1);
    strcpy(tab, inCS);
}


Chaine::Chaine(int cap): capacite(cap) {
    if(capacite >= 0) {
        alloc(capacite + 1);
        tab[0] = 0;
    }
}

Chaine::Chaine(Chaine const & ObjtoCopy) {
    std::cout << "calling copy constructor" << std::endl;
    capacite = ObjtoCopy.capacite;
    alloc(capacite + 1);
    strcpy(tab, ObjtoCopy.tab);
}

Chaine::OutOfRangeException::OutOfRangeException(std::string s): std::out_of_range(s) {
}

Chaine::null_pointer::null_pointer(std::string s): std::logic_error(s) {
    
}

Chaine::null_pointer::null_pointer():std::logic_error("null ptr error") {

}

void Chaine::alloc(int capacite) {
    if(capacite) {
        try {
        tab = new char[capacite];
        } catch(std::bad_alloc &e) {
            e.what();
            delete[] tab;
            tab = nullptr;
            throw;
        }
    }
}

Chaine & Chaine::operator=(Chaine const & inCs) {

    if(&inCs != this) {
        delete[] tab;
        capacite = inCs.capacite;
        alloc(inCs.capacite + 1);
        strcpy(tab, inCs.tab);
    }

    return *this;
}

char & Chaine::operator[](int id) {
    if(tab == nullptr) {
        throw null_pointer{};
    }
    if(id < 0 || id >= capacite) {
        throw OutOfRangeException{"invalid index"};
    }
    return tab[id];
}

char const & Chaine::operator[](int id) const{
    if(tab == nullptr) {
        throw null_pointer{};
    }
    if(id < 0 || id >= capacite) {
        throw OutOfRangeException{"invalid index"};
    }
    return tab[id];
}

const char * Chaine::c_str() const {
    return tab;
}

int Chaine::getCapacite() const {
    return capacite;
}

void Chaine::afficher(std::ostream & stream) const { 
    stream << tab;
}


Chaine::~Chaine() {
    delete[] tab;
}