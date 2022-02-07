#include "Groupe.hpp"
#include "sstream"
//static Attributes
int Groupe::compteur = 0;

Groupe::Groupe(Point p, Couleurs c, int w, int h): Forme(p, c, w, h) {
    std::cout << "Groupe constructing" << std::endl;
}

Groupe::Groupe():Forme() {

}


std::string Groupe::toString() {

    // int id_c = 0, id_r = 0, o_c = 0, o_r = 0;
    
    int total_elements = nb_c + nb_r;
    std::ostringstream oss;
    for(int i = 0; i < total_elements; ++i) {   

         oss << formes[i]->toString() << std::endl;

        //! old without inheritance
        // o_c = formes[id_c]->getOrdre();
        // std::cout << "oc: " << o_c << std::endl;
        // if(o_c == i) {
        //     oss << formes[id_c]->toString() << std::endl;
        //     id_c++;
        //     if(i + 1 == total_elements) {
        //         break;
        //     }
        // }
    
        // o_r = formes[id_r]->getOrdre();
        // std::cout << "or: " << o_r << std::endl;
        // if(o_r == i) {
        //     oss << formes[id_r]->toString() << std::endl;
        //     id_r++;
        //     if(i + 1 == total_elements) {
        //         break;
        //     }
        // }
    }

    return oss.str();
}


void Groupe::ajouterCercle(Cercle c) {
    int tot = nb_c + nb_r;
    formes[tot] = new Cercle(c);
    formes[tot]->setOrdre(nb_c + nb_r);
    nb_c = nb_c + 1;
}

void Groupe::ajouterRectangle(Rectangle r) {
    int tot = nb_c + nb_r;
    formes[tot] = new Rectangle(r);
    formes[tot]->setOrdre(nb_c + nb_r);
    nb_r = nb_r + 1;
}


int Groupe::getNbElements() {
    return nb_c + nb_r;
}

Groupe::~Groupe() {
    for(int i = 0; i < nb_c + nb_r; ++i) {
        delete formes[i];
    }
}

//static methods
int Groupe::getCompteur() {
    return compteur;
}