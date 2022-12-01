
#include "string_map.h"
template <typename T>
string_map<T>::string_map(){
    // COMPLETAR
    raiz= nullptr;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar;}// Provisto por la catedra: utiliza el operador asignación para realizar la copia. }

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    // COMPLETAR
    *this->raiz=nullptr;  // Sería mejor usar erase para "vaciar" *this? Estoy usando el operador = de Nodo* acá, no?
    for (auto  c : d._claves){
        const pair<string,T> par(c, d.at(c));
        *this->insert(par);
    }
    return *this;
}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
    // Kaboom();
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}

 template<typename T>
void string_map<T>::insert(const pair<string, T>  &pal) {
    if(raiz== nullptr){
      raiz=new Nodo();
    }
    Nodo* actual=raiz;
    int i=0;
    T def=pal.second;
    while(i<pal.first.size()){
        int indice = pal.first[i];
        if (actual->siguientes[indice]== nullptr){
            actual->siguientes[indice]= new Nodo();
        }else{
            actual=actual->siguientes[indice];
            i++;
        }
    }
    if (actual->definicion!= nullptr){
        delete actual->definicion;
    }
    (actual->definicion)=new T(def);
  /*  T* def;
    *def=pal.second;
    */
    _claves.insert(pal.first);
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    // COMPLETAR
    Nodo* actual=raiz;
    bool esta= false;
    int i=0;
    string c=clave;
    while (i<c.size()  && actual!= nullptr) {
                actual=actual->siguientes[c[i]];
                i++;
            }
    if(i==clave.size() and actual!=nullptr and actual->definicion!= nullptr){
        esta=true;
    }
    return esta;
}


template <typename T>
const T& string_map<T>::at(const string& clave) const {
    // COMPLETAR
    Nodo* actual=raiz;
    int i=0;
    while(i<clave.size()){
        actual=actual->siguientes[clave[i]];
        i++;
    }
    auto def =actual->definicion;
    return *def;
}

template <typename T>
T &string_map<T>::at( const std::string &clave) {
    // COMPLETAR
    Nodo* actual=raiz;
    int i=0;
    while(i<clave.size()){
        actual=actual->siguientes[clave[i]];
        i++;
    }
    return *actual->definicion;
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    // COMPLETAR
    Nodo* actual=raiz;
    Nodo* ultimaClave=actual;
    int i=0;
    string c=clave;
    bool sigue= false;
    for (int j=0; j<c.size();j++){
        if (actual->siguientes[c[j]]->definicion!= nullptr){
            ultimaClave=actual;
            i=j;
        }
        actual=actual->siguientes[c[j]];
        if (actual!= nullptr) {
            for (auto &p: actual->siguientes) {
                if (p != nullptr) {
                    sigue = true;
                    i=j;
                }
            }
        }
    }

    if (sigue){
        delete actual->definicion;
        actual->definicion= nullptr;
    }else{
        Nodo* desde;
        if (ultimaClave->definicion== nullptr){
            i=0;
            desde=raiz->siguientes[clave[i]];
        } else {
            desde = ultimaClave->siguientes[clave[i]];
        }
        for (i;i<c.size()-1;i++) {
                Nodo* prox = desde->siguientes[c[i+1]];
                delete desde;
                desde= prox;
        }
        delete actual->definicion;
        actual->definicion= nullptr;
        delete actual;
        raiz->siguientes[c[0]]= nullptr;
        _claves.erase(clave);

    }
}

template <typename T>
int string_map<T>::size() const{
    // COMPLETAR
    return _claves.size();
}

template <typename T>
bool string_map<T>::empty() const{
    // COMPLETAR
    return _claves.empty();
}
template <typename T>
void string_map<T>::Kaboom() {
    //borrarNodos(raiz);
}