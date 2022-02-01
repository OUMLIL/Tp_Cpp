#include "Groupe.hpp"

//static Attributes
int Liste::compteur = 0;

Liste::Liste() {
    std::cout << "Liste constructing" << std::endl;
}


void Liste::toString() {

    int total_elements = nb_c + nb_r;
    int id_c = 0, id_r = 0, o_c = 0, o_r = 0;

    std::ostringstream oss;
    for(int i = 0; i < total_elements; ++i) {   

        //make it cleaner
        o_c = cercles[id_c]->getOrdre();
        std::cout << "oc: " << o_c << std::endl;
        if(o_c == i) {
            std::cout << cercles[id_c]->toString() << std::endl;
            id_c++;
            if(i + 1 == total_elements) {
                break;
            }
        }
    
        o_r = rectangles[id_r]->getOrdre();
        std::cout << "or: " << o_r << std::endl;
        if(o_r == i) {
            std::cout << rectangles[id_r]->toString() << std::endl;
            id_r++;
            if(i + 1 == total_elements) {
                break;
            }
        }
    }
}


void Liste::ajouterCercle(Cercle c) {
    cercles[nb_c] = new Cercle(c);
    cercles[nb_c]->setOrdre(nb_c + nb_r);
    nb_c = nb_c + 1;
}

void Liste::ajouterRectangle(Rectangle r) {
    rectangles[nb_r] = new Rectangle(r);
    rectangles[nb_r]->setOrdre(nb_c + nb_r);
    nb_r = nb_r + 1;
}

Liste::~Liste() {
    for(int i = 0; i < nb_c; ++i) {
        delete cercles[i];
    }

    for(int i = 0; i < nb_r; ++i) {
        delete rectangles[i];
    }
}

//static methods
int Liste::getCompteur() {
    return compteur;
}