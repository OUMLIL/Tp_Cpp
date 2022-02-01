#pragma once 

#include "Cercle.hpp"
#include "Rectangle.hpp"
#include "string"


class Groupe {
    private:
        static constexpr std::size_t size{255};
        Cercle * cercles[size];
        int nb_c{0};
        Rectangle * rectangles[size];
        int nb_r{0};
        static int compteur;

    public:
        Groupe();
        ~Groupe();
        void toString();
        void ajouterCercle(Cercle c);
        void ajouterRectangle(Rectangle r);
        static int getCompteur();

};