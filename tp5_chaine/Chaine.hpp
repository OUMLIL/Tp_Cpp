#ifndef CPP5__CHAINE_HPP
#define CPP5__CHAINE_HPP

#include <iostream>
#include <fstream>

class Chaine  {
    private:
        int capacite{-1};
        char * tab{nullptr};
        void alloc(int capacite = 0);
    public:
        class OutOfRangeException : public std::out_of_range {
            public:
                OutOfRangeException(std::string s);
        };

        class null_pointer : public std::logic_error {
            public:
                null_pointer();
                null_pointer(std::string s);
        };

        //constructeurs
        Chaine();
        Chaine(const char * inCS);
        Chaine(int cap);
        Chaine(Chaine const & ObjtoCopy);

        //surcharge operateurs
        Chaine & operator=(Chaine const & inCs);
        char & operator[](int id);
        char const & operator[](int id) const;

        //methodes
        void afficher(std::ostream & stream = std::cout) const;
        const char * c_str() const;
        int getCapacite() const;

        //friendship is everything
        friend Chaine operator+(Chaine const & st1, Chaine const & st2);
        
        //destructeur
        ~Chaine();
};

#endif
