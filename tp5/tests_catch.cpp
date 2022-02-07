#include "catch.hpp"
#include <cstring>
#include <sstream> // a mettre en commentaire 
#include "Chaine.hpp"
#include "utils.hpp"

TEST_CASE("Constructeur par defaut") {
   Chaine c;
   CHECK( -1 == c.getCapacite());
   CHECK(  nullptr == c.c_str()); // 0, NULL, ou nullptr
}


TEST_CASE("Verification des const sur les accesseurs") {
   const Chaine c;
   CHECK( -1 == c.getCapacite());
   CHECK(  0 == c.c_str()); // 0, NULL, ou nullptr
} 


TEST_CASE("Constructeur par chaine C") {
	char  source []= "rien";
    Chaine c1(source);
    CHECK( (signed)strlen(source) == c1.getCapacite() );
    CHECK( 0 == strcmp(source, c1.c_str()) ); 

    Chaine c2 = "";
    CHECK( 0 == c2.getCapacite() );
    CHECK( 0 == strcmp("", c2.c_str())); 

    // Verifier que la liberation memoire est bien faite
} 


TEST_CASE("Constructeur avec capacite") {
    Chaine c1(6);
    CHECK( 6 == c1.getCapacite());
    int t = 0;
    t = strlen(c1.c_str());
    CHECK( 0 == t); 

    // Verifier que la liberation memoire est bien faite
}


TEST_CASE("Constructeur de copie") {
    Chaine s1(10);   // une chaine vide
    Chaine s2 = s1;  // une autre chaine vide
    
    CHECK( s1.getCapacite() == s2.getCapacite());
    // tous les problemes vont venir de la
    // j'ai converti en void * uniquement pour l'affichage de catch
    CHECK( (void *)s1.c_str() != (void *)s2.c_str() );
    CHECK( 0 == strcmp(s1.c_str(), s2.c_str() ));
}


TEST_CASE("methode afficher") {
	const char * original = "une chaine a tester\n";
    const Chaine c1(original);
    std::stringstream ss;
    
    c1.afficher(); // on verifie juste que ca compile
    c1.afficher(ss);
    afficherParReference(c1);
    afficherParValeur(c1);
    CHECK( ss.str() == original); // test de std::string :-)
}


TEST_CASE("operateur d'affectation") {
	Chaine s1("une premiere chaine");
    Chaine s2("une deuxieme chaine plus longue que la premiere");
    
    s1 = s2;

    CHECK( s1.getCapacite() == s2.getCapacite()); 
    CHECK( (void *)s1.c_str() != (void *)s2.c_str() );
    CHECK( 0 == strcmp(s1.c_str(), s2.c_str() ));

    s1 = s1; // est ce que cela va survivre a l execution ?
}


// TEST_CASE("Surcharge <<") {
// 	const char * chaine = "une nouvelle surcharge";
//     const char * chaine2 = "I am testing ok\n";
//     std::stringstream ss;

// 	Chaine s(chaine);
//     Chaine s2("I am ");
//     Chaine s3("testing ");
//     Chaine s4("ok\n");
    
//     ss << s;  // :-)
//     CHECK( ss.str() == chaine );//  test de std::string, again :-))

//     ss.str("");
//     ss << s2 << s3 << s4;
     
//     CHECK( ss.str() == chaine2 );

//     s[0] = 'O';
//     CHECK (strcmp(s.c_str(), "One nouvelle surcharge") == 0);
// }

TEST_CASE("Operateur[]") {

    const char * chaine = "une nouvelle surcharge";
    Chaine s(chaine);
    s[s.getCapacite() - 1] = 'O';
    s[0] = 'Z';
    CHECK (strcmp(s.c_str(), "Zne nouvelle surchargO") == 0);
}

TEST_CASE("<< ligne par ligne [] const") {

    const char * chaine = "toto";
    Chaine s(chaine);
    std::stringstream ss;
    ss << s;
    CHECK (ss.str() == "t\no\nt\no\n");
}

TEST_CASE("Concatenation chaine vide") {

    const char * c1 = "";
    const char * c2 = "";
    Chaine s1(c1);
    Chaine s2(c2);
    Chaine s3 = s1 + s2;

    CHECK(strcmp(s3.c_str(), "") == 0);
}

TEST_CASE("Concatenation chaine non vide") {

    const char * c1 = "what";
    const char * c2 = "ISLOVE";
    Chaine s1(c1);
    Chaine s2(c2);
    Chaine s3 = s1 + s2;

    CHECK(strcmp(s3.c_str(), "whatISLOVE") == 0);
}