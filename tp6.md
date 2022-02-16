# construction par copie
## scenario 1:
---------------------
```cpp
    class A {
        M m;
        
        //best way initialization list
        A(A const & a):m(a.m) {
            
        }
        //or with deplacement
        A(A const & a) {
            m = M(a.m) //ici operator = fait un deplacement
        }
    }
```
## scenario 2 agrégation:
--------------------
```cpp
    class B {
        std::vector<A> as;

        B(B const & b) {
            std::reserve(as.size)
            //voir algorithm cpp ref
            std::copy(b.as.begin(), b.as.end(), as.begin());
            //as.begin() can raise SIGSEGV if b.as and as have different sizes we can force copy by using std::back_inserter(as.begin())

            std::generate(std::back_inserter(as.begin()), lambdafunc)
            std::transform()
        }
    }
```

## scenario 3 vector with default copy constructor
-------------
```cpp
    class A {
        public:
            std::vector<M> ms;
            A() = default;
            A(A const & a) = default;
    };
    int main(int, char**) {
        M m{1}; M m1{2}; M m2{3}; M m3{4};
        A a;
        a.ms.push_back(m);a.ms.push_back(m1);a.ms.push_back(m2);a.ms.push_back(m3);
        A b(a); //calls default constructor of vector
        std::cout << b.ms.size() << std::endl; //prints 4
        std::cout << a.ms.size() << std::endl; //prints 4
        for(auto const & c : b.ms) {
            std::cout << c.i << std::endl; //prints 0 0 0 0
        }
        //default constructor of vector copies only the size (4) of the original vector it doens't copy elements
    }
```
## scenario 4 vector with custom copy constructor
-------------
```cpp
    class M {
        public:  
            int i{};
            //A a;
            M(int c): i(c) {}

            //do not define it only if we want a particular behavior 
            M(const M & m): i(m.i) {
                std::cout << "M::M(const M&)" << std::endl;
            }

            
            //same here either define the 5 elements of coplien or not
            //high maintainability cost (adding things leads to modifying the 5 coplien elements)
            M & operator=(const M & m) {
                i = m.i;
                //a = m.a; 
                    //affectation we can't use a(m.a) because its an initialization list we're not in a constructor
                std::cout << "lol" << std::endl;
                return *this;
            }
    };

    class A {
        public:
            std::vector<M> ms;

            A(A const & a) {
                ms.reserve(a.ms.size());
                std::cout << "ms size" << ms.size() << std::endl; // --> 0 capacity != size no elements yet in ms
                std::copy(a.ms.begin(), a.ms.end(), std::back_inserter(ms)); //calls copy constructor of M for each element
            }
    };


    int main(int, char**) {
        M m{1}; M m1{2}; M m2{3}; M m3{4};
        
        A a;
        a.ms.push_back(m);a.ms.push_back(m1);a.ms.push_back(m2);a.ms.push_back(m3); //copy constructor of M is called each pushback
        A b(a); //custom copy constructor

        std::cout << b.ms.size() << std::endl; //prints 4
        std::cout << a.ms.size() << std::endl; //prints 4

        for(auto const & c : b.ms) {
            std::cout << c.i << std::endl; //prints 1 2 3 4
        }
    }

```