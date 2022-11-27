
template <class T>
Conjunto<T>::Conjunto():_raiz(nullptr),_cardinal(0){
    // Completar
}

template <class T>
Conjunto<T>::~Conjunto() { 
  destructor(); //
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Nodo* actual=_raiz;
    while (actual!=nullptr){
        if (actual->valor==clave){
            return true;
        }else{
            if (actual->valor > clave){
                actual=actual->izq;
            }else{
                actual=actual->der;
            }
        }
    }
    return false;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    Nodo *actual = _raiz;
    Nodo* pivot= nullptr;
    while (actual != nullptr) {
        pivot = actual;
        if (actual->valor < clave) {
            actual = actual->der;
        } else if (actual->valor>clave){
            actual = actual->izq;
        }else{
            break;
        }
    }
    if (actual== nullptr || actual->valor!=clave) {
        Nodo *nuevo = new Nodo(nullptr, clave, nullptr, nullptr);
        if (pivot == nullptr) {
            _raiz = nuevo;
            _cardinal++;
        } else if (pivot->valor < nuevo->valor) {
            pivot->der = nuevo;
            _cardinal++;
            nuevo->padre = pivot;
        } else if (pivot->valor != clave) {
            pivot->izq = nuevo;
            _cardinal++;
            nuevo->padre = pivot;
        } else {
            pivot->izq = nuevo;
            nuevo->padre = pivot;
        }
    }
}
template <class T>
void Conjunto<T>::remover(const T& e) {
    Nodo* actual= _raiz;
    while (actual!= nullptr) {
         if (actual->valor == e) {
           if (actual->izq== nullptr){
               transplant(actual,actual->der);
               _cardinal--;
               delete actual;
               break;
           } else if (actual->der== nullptr){
               transplant(actual,actual->izq);
               _cardinal--;
               delete actual;
               break;
           }else{
                T s=siguiente(actual->valor);
                Nodo* i = actual->izq;
                Nodo* d = actual->der;
                Nodo* reemplazo= buscar(actual,s);
                if (reemplazo->padre!=actual){
                    transplant(reemplazo,reemplazo->der);
                    reemplazo->der=d;
                    reemplazo->der->padre=reemplazo;
                }
                transplant(actual,reemplazo);
                delete actual;
                reemplazo->izq=i;
                reemplazo->izq->padre=reemplazo;
               _cardinal--;
               break;
           }
         }else if (actual->valor< e){
             actual=actual->der;
         } else{
             actual=actual->izq;
         }
    }
}

template <class T>
void Conjunto<T>::transplant(Nodo* elem, Nodo* elem2) {
    if (elem->padre== nullptr){
        _raiz=elem2;

    }else if (elem==elem->padre->izq){
        elem->padre->izq=elem2;
    }   else{
        elem->padre->der=elem2;
    }
    if (elem2!= nullptr){
        elem2->padre=elem->padre;
    }
}

template <class T>
const T &Conjunto<T>::siguiente(const T &elem) {
    Nodo* actual=_raiz;
    while (actual->valor!=elem){
        actual=buscar(actual,elem);
    }
    if (actual->der!= nullptr){
        return min(actual->der);//minimo();
    } else{
        Nodo* p= actual->padre;
        while (p!= nullptr && actual==p->izq){
            actual=p;
            p=p->padre;
        }
        return actual->valor;
    }

}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo *actual = _raiz;
    while (actual->izq!= nullptr) {
        Nodo *i = actual->izq;
        while (i != nullptr) {
            actual = i;
            i = actual->izq;
        }
    }
    return actual->valor;
}
template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo *actual = _raiz;
    Nodo *d = actual->der;
    while (d != nullptr) {
        actual = d;
        d = actual->der;
    }
    return actual->valor;
}
template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _cardinal;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

template <class T>
void Conjunto<T>::destructor() {
    Nodo* actual = _raiz;
    Nodo* inicial= _raiz;
    if (actual!= nullptr) {
        T original = actual->valor;
        if (actual->valor != minimo()) {
            actual = buscar(actual, minimo());
        }
        while (actual->valor != maximo() && actual->valor!=original) {
            Nodo *sig = buscar(inicial, siguiente(actual->valor));
            remover(actual->valor);
            actual = sig;
        }
        while(actual->valor!=maximo() && inicial!= nullptr){
            Nodo* sig2= buscar(inicial, siguiente(actual->valor));
            remover(actual->valor);
            inicial= buscarR();
            actual = sig2;
        }
        remover(actual->valor);
        _raiz= nullptr;
        _cardinal=0;
    }
}