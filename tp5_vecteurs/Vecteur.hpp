#pragma once
#include <exception>

class Vecteur {
    private:
        int capacite{-1};
        int nbElements{0};
        double * tab{nullptr};
    public:
        Vecteur();
        Vecteur(int capacity);
        Vecteur(Vecteur const & vectToCopy);

        int capacity() const;
        int size() const;
        void push_back(double element);

        //operators
        double & operator[](int id);
        double const & operator[](int id) const;

        //exception
        class OutOfRangeException : public std::exception {
            const char * what() const noexcept;
        };

        const double * begin() const;
        const double * end() const;

        ~Vecteur();

};

