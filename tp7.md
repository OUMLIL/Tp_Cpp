## templates
---------------------
    - is typename used only for function template or can be used for both class and function templates ?
    - class vs typename any difference ?
    
```
class et typename considère que c'est la même chose. Même si en fonction du standard tu es parfois obligé d'utilisé un des deux et pas l'autre. Mais le cas ne devrait pas se présenter. Et à partir du C++17 je pense qu'il y a osef total. Cfy serait plus calé que moi pour ça, parce qu'en gros le besoin se présentait quand on commence à imbriquer les templates.
(Il sont identiques que dans le cadre template, pas ailleurs)
Il y a moyen qu'il y ai une différence dans le cadre de type fondamentaux mais je ne suis pas certain non plus
```
```cpp
    template<typename T>
    class PileGen {
        //...
    };
    //vs
    template<class T>
    class PileGen {
        //...
    }
```

    - complex template parameters, this the line bellow means that C3 has another generic type "C1" that is himself a template of type T ?

```
On a la classe C3 paramétrée par T et C. On dit que la valeur par défaut de C est C1<T>. C1 est bien une classe template et est ici instancié avec le type T par défaut.
```
```cpp
    template <typename T, typename C = C1<T> >
    class C3 {
        //...
    };
```
    - why C = C1<T> ? why not just :
```cpp 
    template <typename T, typename C = C1<T> > // is it just the syntax ?
```


## Jeremy review:

Pour le code y a quelques trucs à dire :
 - La gestion de l'exception de new ne sert à rien je pense (le e.what() principalement). Mais aussi le delete parce qu'ici si l'allocation à échouée y a vraiment aucune ressource à libérer.

 - empty est un mauvais nom de fonction (même si le standard utilise empty. Utilise plutôt isEmpty ou bien hasXXX pour des getters bool.

 - full sert à rien je pense. Une méthode qui throw c'est étrange. Surtout quelle est publique. 

 - tail = tail + 1  ????!!!! why why

 - Rajoute un test "Copie de pile" et admire le problème

 - Ca manque de fonction const il me semble.

 - capacity sert à représenter le nombre d'élément max que tu peux contenir, pas le nombre actuellement contenu. Je pense que t'as confondu les deux. (stacklen devrait être égal à capacity). D'ailleurs ça devrait être const comme jamais modifié.

 - Dommage de pas avoir mis de valeur par défaut pour la taille de la pile.

 - push devrait rien retourner. A quoi ça sert de renvoyer un entier pour code d'erreur en C++ ?? Surtout que tu throw une exception si il y en a eu une. Si t'as envie de gérer ton erreur avec un code, utilise simplement une enum class. si t'as envie de renvoyer ou non une valeur sans spécifier la raison du "non", utilise std::optional (c++17)

 - Arrête avec this pour l'amour de dieu xD

 - Pourquoi pop renvoie un entier ? même chose que push ici. D'ailleurs usuellement un pop renvoie l'élément top si il y en a un. Ca évite de devoir faire : top(); pop() à chaque fois.

 - Si t'as envie de forcer un peu le bon C++17, tu peux rajouter des [no_discards] (voir même paramétré en C++20),

 - Tu devrais aussi proposer des manières d'accéder au type stocké dans la pile. (value_type est le nom utilisé courament pour ça. (pour le tester fait ça : 
```cpp
TEST() {
    using PileF = Pile<float>;
    REQUIRE (typeid(PileF::value_type) == typeid(float))
}
```
[8:07 PM]
- L'exception je l'aurais faite comme ça : 
```cpp
    struct fullStackException : public std::exception {};
```

D'ailleurs pas sûr que ce soit une bonne chose de la faire en classe imbriquée parce que du coup tu as ça :
```cpp
    Pile<float>::fullStackException != Pile<int>::fullStackException
    //Je ne suis pas sûr que ça soit pratique pour les catch ;)
```  