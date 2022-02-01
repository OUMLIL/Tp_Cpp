#pragma once

#include "Point.hpp"
#include "string"

// enum Couleurs { BLANC, NOIR};
enum class Couleurs { BLANC, NOIR, BLEU, JAUNE, VERT, ROUGE};
//! check doc sur cppref
//! can specify which type is stored
class Forme{

    private:
        Point p{};
        Couleurs color{Couleurs::BLEU};
        int w{}, h{};
        static int nbFormes;
        int ordre{0};

    public:
        int id{0};

        Forme(Point p, Couleurs c, int w = 0, int h = 0);
        Forme();

        Point & getPoint();
        int getId();
        virtual void setX(int x);
        virtual void setY(int y);

        virtual int getHauteur();
        virtual int getLargeur();
        
        virtual int getOrdre();
        virtual void setOrdre(int o);

        virtual Couleurs getCouleur();
        virtual void setCouleur(Couleurs c);

        virtual std::string toString() = 0;
        
        //static functions
        static int getNbForme();
        static int prochainId();

        virtual ~Forme();
};
/* 
class Forme {

    Point getPoint() {
        return 
    }


}
*/