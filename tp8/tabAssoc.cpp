#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <stack>
#include <map>
#include <utility>
#include <sstream>


const std::string& first(const std::pair<std::string,std::string>& p) { return p.first; }

const std::string pair(const std::pair<std::string, std::string>& p) {
    return p.first + " " + p.second; 
}


int main(int, char**) {
    std::map<std::string, std::string> liste;
    std::map<std::string, std::string> liste_c;

    liste.insert(std::make_pair("pierre", "405033"));
    liste.insert(std::make_pair("SOS C++ 24/7", "407662"));

    std::map<std::string, std::string>::const_iterator it 
        = liste.begin();
    while(it!=liste.end()) {  
        std::cout << it->first  << " " 
            << it->second << std::endl;
        ++it;
    }

    transform(liste.begin(), liste.end(), 
    std::ostream_iterator<std::string>(std::cout, "\n"), first);

    //!copy
    std::cout << "THE COPY" << std::endl;
    std::copy(liste.begin(), liste.end(), std::inserter(liste_c, liste_c.end()));
    transform(liste_c.begin(), liste_c.end(), 
        std::ostream_iterator<std::string>(std::cout, "\n"), pair);
    
    return 0;
}