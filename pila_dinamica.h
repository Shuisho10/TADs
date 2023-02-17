#ifndef PILA_DINAMICA_H_INCLUDED
#define PILA_DINAMICA_H_INCLUDED
#include <cassert>
template <typename T>
class PilaD
{
public:
    //Funciones constructoras
    PilaD();                            //Constructor por defecto
    PilaD(const PilaD<T>& P);           //Constructor de copia
    //Funciones observadoras
    const T& tope() const;              //Elemento del primer nodo
    bool vacia() const;                 //Verifica que la pila esta vacia
    //Funciones modificadoras
    T pop();                            //Saca un elemento de la pila y devuelve el valor del tope
    void push(const T& n);              //Mete un elemento a la pila
    void copia(const PilaD<T>& P);      //Funcion de copia
    //Operadores
    PilaD<T>& operator =(const PilaD<T>& P);
    //Destructor
    ~PilaD();
private:
    //struct nodo: enlazar un elemento con otro de forma dinamica.
    struct nodo
        {
            T data;                                                 //elemento almacenado
            nodo* siguiente;                                        //puntero al siguiente nodo
            nodo(T r, nodo* p = nullptr): data(r), siguiente(p) {}  //constructor del nodo
        };
    nodo* p;    //puntero cabecera de la pila (apunta ultimo nodo que se creo o al siguiente que vaya a salir)
};

//Constructor por defecto
template <typename T>
PilaD<T>::PilaD() : p(nullptr) {}

//Constructor de copia
template <typename T>
PilaD<T>::PilaD(const PilaD<T>& P) : p(nullptr)
{
    copia(P);
}

//Copia
template <typename T>
void PilaD<T>::copia(const PilaD<T>& P)
{
    p=new nodo(P.tope());                       //Crea el primer nodo
    nodo* j=p;                                  //Puntero j hacia la cabecera
    nodo* k=P.p->siguiente;                     //Puntero k hacia el siguiente nodo
    while(k)                                    //Mientras haya mas nodos
        {
            j->siguiente=new nodo(k->data);     //Crea el nuevo nodo
            j=j->siguiente;                     //Entra al nuevo nodo
            k=k->siguiente;                     //Avanza en la pila
        }
}



//Vacia
template <typename T>
bool PilaD<T>::vacia() const
{
    return(p==nullptr); //Si p no apunta a nada, es porque esta vacia
}

//Push
template <typename T>
void PilaD<T>::push(const T& n)
{
    p = new nodo(n,p); //Crea un nuevo nodo generado con el elemento al que apunta al que esta apuntando p y p apunte a este.
}

//Tope
template <typename T>
const T& PilaD<T>::tope() const
{
    return p->data;     //Obtenemos el elemento al que apunta p
}

//Pop
template <typename T>
T PilaD<T>::pop()
{
    assert(!vacia());   //No debe estar vacia para realizar esta funcion
    T store = tope();   //Guarda el elemento para el return
    nodo* q=p;          //Guarda el puntero del nodo que queremos eliminar
    p = p->siguiente;   //El puntero salta al siguiente nodo
    delete q;           //El nodo anterior es eliminado
    return store;       //Devuelve el valor correspondiente
}

//Operador =
template <typename T>
PilaD<T>& PilaD<T>::operator =(const PilaD<T>& P)
{
    if (this != &P)     //Evitar autoasignación
    {
        this->~PilaD(); // Vaciar la pila actual
        copia(P);       //Copia
    }
    return *this;       //Devuelve la referencia
}


//Destructor
template <typename T>
PilaD<T>::~PilaD()
{
    nodo* d;                //Puntero del siguiente nodo para eliminar los anteriores
    while (p)               //Miramos si la cabecera apunta a un nodo
    {
        d=p->siguiente;     //d al siguiente nodo de p
        delete p;           //Se elimina el anterior
        p=d;                //p apunta al nodo guardado en d
    }
}

#endif // PILA_DINAMICA_H_INCLUDED
