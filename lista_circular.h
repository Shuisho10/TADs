#ifndef LISTA_DINAMICA_H_INCLUDED
#define LISTA_DINAMICA_H_INCLUDED

//Lista cicular de nodos con doble enlazamiento
#define POS_NULA nullptr
template <typename T>
struct ListaCir
{
public:


    struct posicion
    {
        T e;
        posicion* ant,*sig;
        posicion(posicion* a,posicion* s,T r): ant(a), sig(s), e(r) {}
    };


    ListaCir(); //Constructor

    bool vacia() const; //Observador de vacio
    posicion inipos(); //Observador del puntero L
    const T& elemento(posicion p) const; //Observador de elemento en esa posicion
    posicion siguiente(posicion p) const; //Observador a la siguiente posicion
    posicion anterior(posicion p) const; //Observador a la posicion anterior

    void insertar(const T& x, posicion p); //Modificador de insercion
    void eliminar(posicion p); //Modificador de eliminacion

    ~ListaCir(); //Destructor
private:
    posicion* L_;
};

template <typename T>
ListaCir<T>::ListaCir():L_(nullptr) {}

template <typename T>
bool ListaCir<T>::vacia() const
{
    return (L_==nullptr);
}


template <typename T>
typename ListaCir<T>::posicion ListaCir<T>::inipos()
{
    return (L_);
}

template <typename T>
const T& ListaCir<T>::elemento(posicion p) const
{
    return (p.e);
}

template <typename T>
typename ListaCir<T>::posicion ListaCir<T>::siguiente(posicion p) const
{
    assert(!vacia());
    return(p->sig);
}

template <typename T>
typename ListaCir<T>::posicion ListaCir<T>::anterior(posicion p) const
{
    assert(!vacia());
    return(p->ant);
}

template <typename T>
void ListaCir<T>::insertar(const T& x, posicion p)
{
    if(vacia())
    {
        L_=new posicion(L_,L_,x);
    }
    else
    {
        posicion n = new posicion(p.anterior(),p,x);
        p.anterior().sig=n;
        p.ant=n;
    }
}

template <typename T>
void ListaCir<T>::eliminar(posicion p)
{
    assert(p!=nullptr);
    p.anterior().sig=p.siguiente();
    p.siguiente().ant=p.anterior();
    if(L_==p) L_=p.siguiente();
    delete p;
}

template <typename T>
ListaCir<T>::~ListaCir()
{
    posicion q=L_;
    while (q!=q)
    {
        q=q.siguiente();
        delete q.anterior();
    }
}

#endif // LISTA_DINAMICA_H_INCLUDED
