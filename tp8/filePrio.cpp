#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <string>
#include <queue>

class ZZ {
    public :
        std::string nom, prenom;
        double note;
  
    ZZ(std::string firstn, std::string lastn, double grade): nom(firstn), prenom(lastn), note(grade) {

    }
};

bool operator<(const ZZ & one, const ZZ & other) {
    return one.note > other.note;
}

std::ostream & operator<<(std::ostream & ss, ZZ const & inZZ) {
    ss << inZZ.nom << " " << inZZ.prenom << ": " << inZZ.note;
    return ss;
}


int main() {
    typedef std::vector<ZZ>  vzz;

    typedef std::vector<ZZ *> pvzz; //? contains ZZ pointers
    // OU en C++ 2011
    // using vzz = std::vector<ZZ> ;

    vzz zz;
    pvzz zzp;
    // il faut mettre des elements
    // zz.push_back(ZZ(...));

    zz.push_back(ZZ("hamid", "kabala", 22));
    zz.push_back(ZZ("cisco", "switch", 18));
    zz.push_back(ZZ("blockchain", "solana", 10));

    std::priority_queue<ZZ> tri;

    for(vzz::iterator it = zz.begin(); it!=zz.end(); ++it) {
        tri.push(*it);
    }

    while(!tri.empty()) {
        std::cout << tri.top() << " " << std::endl;
        tri.pop();
    }

    ZZ * zz1 = new ZZ("hamid", "kabala", 22);
    ZZ * zz2 = new ZZ("cisco", "switch", 18);

    zzp.push_back(zz1);
    zzp.push_back(zz2);
    zzp.push_back(new ZZ("blockchain", "solana", 10));

    for(auto & c: zzp) {
        delete(c);
    }
    zzp.clear();
}