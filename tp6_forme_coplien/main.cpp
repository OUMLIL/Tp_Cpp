#include <iostream>

class M {
 public:  
  M() {
    std::cout << "M::M()" << std::endl;
  }
   ~M() {
    std::cout << "M::~M()" << std::endl;
  }
    M(const M&) {
    std::cout << "M::M(const M&)" << std::endl;
  }
  M & operator=(const M & m) {
    std::cout << "lol" << std::endl;
    return *this;
  }
  
};

class A {
  M m;
 public:  
  A() {
    std::cout << "A::A()" << std::endl;
  }
   ~A() {
    std::cout << "A::~A()" << std::endl;
  }
  A(const A& a) {
    M x(a.m);
    m = x;
    this->t();
    std::cout << "A::A(const A&)" << std::endl;
  }
  A & operator=(const A & a) {
    std::cout << "AAA" << std::endl;
    return *this;
  }
  void t() {
    std::cout << &m << std::endl;
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

int main(int, char**) {
  /*
  F f1; //construction
  F f2 = f1;
  f1 = f2;
  */
  A a;
  A a1 = a;
  a1.t();
  a.t();
  return 0;
}