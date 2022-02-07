#pragma once
//fonctions et surcharge des opérateurs

#include "Chaine.hpp"
#include <fstream>


void afficherParValeur(Chaine c);
void afficherParReference(Chaine const & c);
std::ostream & operator<<(std::ostream & ss, Chaine const & inCs);
Chaine operator+(Chaine const & st1, Chaine const & st2);
