##### templates
---------------------
    - is typename used only for function template or can be used for both class and function templates ?
    - class vs typename any difference ?
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

