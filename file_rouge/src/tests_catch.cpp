#include <fstream>
#include <iostream>

#include "catch.hpp"
#include "Point.hpp"
#include "Rectangle.hpp"
#include "Forme.hpp"
#include "Cercle.hpp"
#include "Groupe.hpp"

// NOTE : ce test utilise des enum "class"
// il faut donc utiliser un compilateur g++ >= 6.1
// ou activer l'option c++11 du compilateur
// -std=c++11 ou -std=c++0x sur les tres vieux compilateurs

// Les tests ne sont pas exhaustifs, loin de là

/*
TEST_CASE("Instanciation", "[Point]") {
	Point p1;
	REQUIRE(p1.getX() == 0);
	REQUIRE(p1.getY() == 0);
	
    p1.setX(11);
    p1.setY(21);

    REQUIRE(p1.getX() == 11);
	REQUIRE(p1.getY() == 21);

	Point p2(12, 22);

	REQUIRE(p2.getX() == 12);
	REQUIRE(p2.getY() == 22);  // :-)
}

TEST_CASE("Origine", "[Point]") {
	REQUIRE(ORIGINE.getX() == 0);
	REQUIRE(ORIGINE.getY() == 0);
}

TEST_CASE("Compteur", "[Forme]") {
   // Pour être correct, ce test doit etre le premier sur Forme
   REQUIRE(0 == Forme::prochainId());
   Forme f1;
   REQUIRE(0 == f1.getId());

   REQUIRE(1 ==  Forme::prochainId());	
   
   // Verification que la valeur n'est pas decrementee accidentellement.
   Forme *p = new Forme;
   REQUIRE(1 == p->getId());
   delete p;
   REQUIRE(2 == Forme::prochainId());	
}


TEST_CASE("Instanciation1", "[Forme]") {
	Forme f1;
	REQUIRE(f1.getPoint().getX() == 0);
	REQUIRE(f1.getPoint().getY() == 0);
	REQUIRE(f1.getCouleur() ==  Couleurs::BLEU);
}


TEST_CASE("Instanciation2", "[Forme]") {
	Forme f2;
	
	f2.setX(15);
	f2.setY(25);
	f2.setCouleur(Couleurs::VERT);
	REQUIRE (f2.getPoint().getX() == 15);
	REQUIRE (f2.getPoint().getY() == 25);
	REQUIRE (f2.getCouleur() == Couleurs::VERT);
	REQUIRE_FALSE (f2.getCouleur() == Couleurs::BLEU);
	REQUIRE_FALSE (f2.getCouleur() == Couleurs::ROUGE);
	REQUIRE_FALSE (f2.getCouleur() == Couleurs::JAUNE);
}


TEST_CASE("Instanciation3", "[Forme]") {
    //! IL N'Y A PAS D'ERREUR DANS LE TEST, CELA DOIT MARCHER	
	Forme f2(Point(10,20), Couleurs::ROUGE);
	REQUIRE (f2.getPoint().getX() == 10);
	REQUIRE (f2.getPoint().getY() == 20);
	REQUIRE (f2.getCouleur() == Couleurs::ROUGE);
	REQUIRE_FALSE (f2.getCouleur() == Couleurs::BLEU);

	f2.getPoint().setX(15);
	f2.getPoint().setY(25);
	f2.setCouleur(Couleurs::JAUNE);
	REQUIRE (f2.getPoint().getX() == 15);
	REQUIRE (f2.getPoint().getY() == 25);
	REQUIRE (f2.getCouleur() == Couleurs::JAUNE);
	REQUIRE_FALSE (f2.getCouleur() == Couleurs::BLEU);
	REQUIRE_FALSE (f2.getCouleur() == Couleurs::ROUGE);
}


TEST_CASE("BoiteEnglobante", "[Forme]") {
	Forme f;
	REQUIRE (f.getLargeur() == 0);
	REQUIRE (f.getHauteur() == 0);
}

*/

TEST_CASE("Cercle", "[Cercle]") {
   int compteur = Forme::prochainId();
   Cercle c1;
   Cercle c2{}; 
   Rectangle r1{};
   Cercle c3{};
   Rectangle r2{};
   
   REQUIRE(c1.toString() == "CERCLE 0 0 0 0 0");
   REQUIRE(c2.toString() == "CERCLE 1 0 0 0 0");
   REQUIRE(r1.toString() == "RECTANGLE 2 0 0 0 0");
   REQUIRE(c3.toString() == "CERCLE 3 0 0 0 0");
   REQUIRE(r2.toString() == "RECTANGLE 4 0 0 0 0");

//    c2.setRayon(...);
//    REQUIRE(c2.getRayon()   == "..."  );
//    REQUIRE(c2.toString()   == ".....");
//    REQUIRE(c2.getLargeur() == ".....");
//    REQUIRE(c2.getHauteur() == ".....");  

   REQUIRE(Forme::prochainId() == (compteur+5) ); 
}


TEST_CASE("Polymorphisme", "[Forme]") {

   	Forme * f1 = new Cercle();
   	Forme * f2 = new Rectangle();

   	REQUIRE(f1->toString() == "CERCLE 5 0 0 0 0");
   	REQUIRE(f2->toString() == "RECTANGLE 6 0 0 0 0");

   	delete f1;
   	delete f2;
}


TEST_CASE("Liste de formes", "[Groupe]") {

	Groupe l{}; 
    Cercle c_tab[10]; 
    Rectangle r_tab[10];
	Forme & f = l;


    l.ajouterCercle(c_tab[0]); //c ordre 0
    l.ajouterCercle(c_tab[1]); //c ordre 1

    l.ajouterRectangle(r_tab[1]); //r ordre 2
    l.ajouterCercle(c_tab[2]); //c ordre 3
	
	Point p{1,1};
	Couleurs c{Couleurs::BLEU};
	Cercle c1{p,c,10,20};
	l.ajouterCercle(c1);

	std::cout << l.getNbElements() << std::endl;
    std::cout << l.toString();
    std::cout << "next id " << Forme::prochainId() << std::endl;
}


TEST_CASE("cloning cercle", "[Cercle]") {
	Groupe l{}; 
    Cercle c_tab[10]; 
    Rectangle r_tab[10];

	l.ajouterCercle(c_tab[0]); //c ordre 0
    l.ajouterCercle(c_tab[1]); //c ordre 1

    l.ajouterRectangle(r_tab[1]); //r ordre 2
    l.ajouterCercle(c_tab[2]); //c ordre 3
	Point p{1,1};
	Couleurs c{Couleurs::BLEU};
	Cercle c1{p,c,10,20};
	l.ajouterCercle(c1);

	Groupe * grp = l.clone();
	std::cout << grp->toString() << std::endl;

	delete grp;
}

