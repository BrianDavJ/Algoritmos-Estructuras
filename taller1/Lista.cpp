#include "Lista.h"

Lista::Lista(): prim(nullptr),ult(nullptr){
    // Completar
}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    // Completar
    destructor();
}

Lista& Lista::operator=(const Lista& aCopiar) {
    // Completar
    destructor();
    copiarNodos(aCopiar);
    return *this;
}

void Lista::copiarNodos(const Lista &p) {
    Nodo* actual= p.prim;
    while (actual!= nullptr){
        agregarAtras(actual->valor);
        actual=actual->sig;
    }
}
void Lista::agregarAdelante(const int& elem) {
    // Completar
    Nodo *nuevo = new Nodo(nullptr, elem, nullptr);
    if (prim == nullptr) {
        prim = nuevo;
        ult = nuevo;
    } else {
        Nodo *actual = ult;
        while (actual->ant != nullptr) {
            actual = actual->ant;
        }
        actual->ant = nuevo;
        nuevo->sig = actual;
        prim=nuevo;
        /*
        while (actual->sig != nullptr) {
            actual = actual->sig;
        }
         ult = actual;
         */
    }
}
void Lista::agregarAtras(const int& elem) {
    // Completar
    Nodo* nuevo= new Nodo(nullptr,elem, nullptr);
    if (prim== nullptr&&ult== nullptr){
        prim = nuevo;
        ult=nuevo;
    }else {
        Nodo *actual = ult;
        while (actual->sig != nullptr) {
            actual = actual->sig;
        }
        actual->sig = nuevo;
        nuevo->ant = actual;
        ult=nuevo;
    }
}


void Lista::eliminar(Nat i) {
    // Completar
    Nodo* actual=prim;
    if(longitud()==1){
        prim= nullptr;
        ult= nullptr;
        delete actual;
        return;
    }
    for (Nat j=0; j<i;j++){
        actual=actual->sig;
    }
    Nodo* siguiente=actual->sig;
    Nodo* anterior=actual->ant;
    if (siguiente== nullptr){
        anterior->sig=siguiente;
        ult=anterior;
        delete actual;
        return;
    }
    if(anterior== nullptr){
        siguiente->ant=anterior;
        prim=siguiente;
        delete actual;
        return;
    }
    siguiente->ant=anterior;
    anterior->sig=siguiente;
    delete actual;
}

int Lista::longitud() const {
    // Completar
    int contador=0;
    Nodo* actual=prim;
    while (actual!=nullptr){
        contador++;
        actual=actual->sig;
    }
    return contador;
}

const int& Lista::iesimo(Nat i) const {
    // Completar
    Nodo* actual=prim;
    for (Nat j=0; j<i;j++){
        actual=actual->sig;
    }
    return actual->valor;
    //assert(false);
}

int& Lista::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    //assert(false);
    Nodo* actual=prim;
    for (Nat j=0; j<i;j++){
        actual=actual->sig;
    }
    return actual->valor;
}

void Lista::mostrar(ostream& o) {
    // Completar
}
void Lista::destructor() {
    Nodo* actual=prim;
    while (actual!= nullptr){
        Nodo* siguiente=actual->sig;
        delete actual;
        actual=siguiente;
    }
    prim= nullptr;
    ult= nullptr;
}