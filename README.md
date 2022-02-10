# C++ TPs 


- ? why std::ostream and type passed is std::stringstream -> Héritage
- ? difference fstream and sstream -> File / string. L'un permet de mapper du flux "externe" et l'autre des std::string
- ? difference stringstream and ostringstream : l'un est bidirectionnel
- ? operator+ s3 = s1 + s2 why doesn't it call copy constructor : Copy ellision je suppose
- ? \<new> vs \<iostream> for **std::bad_alloc** : J'aurais dit `<stdexcept>` mais si cppref dit `<new>` alors `<new>`
- ? coplien form: is rewriting =operator necessary when the copy constructor is implemented : YUP cette forme contient 4 trucs : Default Ctor, Dtor, CopyCtor, AffectOperator


## Remarques :

### Point
    Si tu veux générer un Default ctor : utilise `T() = default`;


### Chaine 
- Liste d'init pour les ctors
- Attention aux constructeurs qui ne s'appellent pas mutuellement
- Alloc est clacos :
    - c'est bien d'avoir vu l'exception -> en pratique tu laisses tomber
- Operator= pourrait faire un if(cond) return ---> [guard clause](https://deviq.com/design-patterns/guard-clause)
- eviter les const & sur des types primitifs -> https://stackoverflow.com/questions/67541800/benefits-of-passing-const-reference-vs-values-in-function-in-c-for-primitive-t?rq=1
- Choisis `const T &` ou `T const &` (idem ptr)
- private facultatif dans une class
- Chaine operator+(Chaine const & st1, Chaine const & st2); déclaré 2 fois (étrange mais correcte)


### Vector
- Déplacer le bout de code qui realloc dans une fonction dédiée

### Améliorations:

itérateurs
les getter/setter simples devraient être fais dans les header
