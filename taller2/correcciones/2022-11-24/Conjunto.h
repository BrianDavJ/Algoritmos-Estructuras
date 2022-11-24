#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include <assert.h>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class Conjunto
{
    public:

        // Constructor. Genera un conjunto vacío.
        Conjunto();

        // Destructor. Debe dejar limpia la memoria.
        ~Conjunto();

        // Inserta un elemento en el conjunto. Si este ya existe,
        // el conjunto no se modifica.
        void insertar(const T&);

        // Decide si un elemento pertenece al conjunto o no.
        bool pertenece(const T&) const;

        // Borra un elemento del conjunto. Si este no existe,
        // el conjunto no se modifica.
        void remover(const T&);

        // Siguiente elemento al recibido por párametro, en orden.
        // Pre: el elemento está en el conjunto y no es el máximo del conjunto.
        const T& siguiente(const T& elem);

        // Devuelve el mínimo elemento del conjunto según <.
        const T& minimo() const;

        // Devuelve el máximo elemento del conjunto según <.
        const T& maximo() const;

        // Devuelve la cantidad de elementos que tiene el conjunto.
        unsigned int cardinal() const;

        // Muestra el conjunto.
        void mostrar(std::ostream&) const;

    private:

        /**
         * Completar con lo que sea necesario...
         **/

        struct Nodo {
            // El constructor toma el elemento al que representa el nodo.

            // El elemento al que representa el nodo.
            T valor;
            // Puntero a la raíz del subárbol izquierdo.
            Nodo *izq;
            // Puntero a la raíz del subárbol derecho.
            Nodo *der;
            Nodo *padre;
            Nodo(Nodo *izq, const T &v, Nodo *der, Nodo *padre) : valor(v), izq(nullptr), der(nullptr),padre(nullptr) {};
            Nodo* buscarNodo(Nodo* x, T clave) {
                if (x == nullptr or clave ==x->valor ){
                    return x;
                }else if( clave < x->valor) {
                    return buscarNodo(x->izq, clave);
                }else if(clave>x->valor){
                    return buscarNodo(x->der,clave);
                }else{

                }
            }
            Nodo* buscarRaiz(Nodo* x){
                if (x == nullptr or x->padre==nullptr ){
                    return x;
                }else{
                    buscarRaiz(x->padre);
                }
            }
        };
        // Puntero a la raíz de nuestro árbol.
        Nodo* _raiz;

        //destructor
        void destructor();
        unsigned int _cardinal;
        void transplant(Nodo* elem, Nodo* elem2);
        Nodo* buscar(Nodo* x, T clave){
            return x->buscarNodo(x,clave);
        };
        const T& min(Nodo* x){
            Nodo *actual = x;
            while (actual->izq!= nullptr) {
                Nodo *i = actual->izq;
                while (i != nullptr) {
                    actual = i;
                    i = actual->izq;
                }
            }
            return actual->valor;
        };
    Nodo* buscarR(){
        return _raiz->buscarRaiz(_raiz);
    }
};




template<class T>
std::ostream& operator<<(std::ostream& os, const Conjunto<T>& c) {
	 c.mostrar(os);
	 return os;
}

#include "Conjunto.hpp"

#endif // CONJUNTO_H_
