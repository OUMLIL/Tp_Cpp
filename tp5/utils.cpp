#include "utils.hpp"
#include "cstring"


void afficherParValeur(Chaine c) {
    c.afficher();
}
void afficherParReference(Chaine const & c) {
    c.afficher();
}

// std::ostream & operator<<(std::ostream & ss, Chaine const & inCs) {
//     inCs.afficher(ss);
//     return ss;
// }

std::ostream & operator<<(std::ostream & ss, Chaine const & inCs) {
    int len = inCs.getCapacite();
    for(int i = 0; i < len; ++i) {
        ss << inCs[i] << std::endl;
    }
    return ss;
}

Chaine operator+(Chaine const & st1, Chaine const & st2) {

    Chaine ss(st1.capacite + st2.capacite);
    strcpy(ss.tab, st1.tab);
    strcat(ss.tab, st2.tab);

    return ss;
}

//? why std::ostream and type passed is std::stringstream
//? difference fstream and sstream
//? difference stringstream and ostringstream
//? operator+ s3 = s1 + s2 why doesn't it call copy constructor ??