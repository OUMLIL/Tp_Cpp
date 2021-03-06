#pragma once 

#include "string"
#include "Forme.hpp"
#include "Cercle.hpp"
#include "Rectangle.hpp"

class Groupe : public Forme{
    private:
        static constexpr std::size_t size{255};
        Forme * formes[size];
        int nb_c{0};
        int nb_r{0};
        static int compteur;

    public:
        Groupe(const Point & p, Couleurs c, int w, int h);
        Groupe();
        ~Groupe();
        std::string toString();
        void ajouterCercle(Cercle c);
        void ajouterRectangle(Rectangle r);
        int  getNbElements();
        
        Groupe * clone() override;

        static int getCompteur();

};