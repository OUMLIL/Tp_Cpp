#include <iostream>
#include <vector>

class M {
  public:  
  int i{};
  //A a;
  M() {
    //std::cout << "M::M()" << std::endl;
  }
  M(int c): i(c) {
    //std::cout << "M::M()" << std::endl;
  }
   ~M() {
    //std::cout << "M::~M()" << std::endl;
  }

  M(const M & m): i(m.i) {
     std::cout << "M::M(const M&)" << std::endl;
  }
  
  M & operator=(const M & m) {
    i = m.i;
    //a = m.a; //affectation we can't use a(m.a) -> this is an initialization list
     std::cout << "lol" << std::endl;
    return *this;
  }
};

class F : public M {
 public:
  F() {
    std::cout << "F::F()" << std::endl;
  }  
~F() {
    std::cout << "F::~F()" << std::endl;
  }
  
  //! appel explicite du constructeur par copie de la classe mère
  F(const F& f):M(f) {
    std::cout << "F::F(const F&)" << std::endl;
  } 

  F & operator=(const F & f) {
    M::operator=(f);
    std::cout << "fff" << std::endl;
    return *this;
  }

};


class A {
  public:
    std::vector<M> ms;
    A() {
      //std::cout << "A::A()" << std::endl;
    }
    ~A() {
      //std::cout << "A::~A()" << std::endl;
    }

    //A(A const & a) = default;

    A(A const & a) {

      ms.reserve(a.ms.size());
      std::cout << "ms size" << ms.size() << std::endl; // --> 0

      //call copy constructor of M
      std::copy(a.ms.begin(), a.ms.end(), std::back_inserter(ms));
      //std::copy(a.ms.begin(), a.ms.end(), ms.begin());
    }
};

int main(int, char**) {
  /*
  F f1; //construction
  F f2 = f1;
  f1 = f2;
  */
  //A a;
  //A a1 = a;
  M m{1};
  M m1{2};
  M m2{3};
  M m3{4};

  A a;
  a.ms.push_back(m);a.ms.push_back(m1);a.ms.push_back(m2);a.ms.push_back(m3);

  A b(a); 

  std::cout << b.ms.size() << std::endl; // 4 with std::backinserter and 0 
  std::cout << a.ms.size() << std::endl; // 4

  for(auto const & c : b.ms) {
    std::cout << c.i << std::endl;
  }

  return 0;
}