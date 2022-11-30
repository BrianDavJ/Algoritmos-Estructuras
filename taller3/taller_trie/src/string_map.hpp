
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
/*    Nodo* actual=raiz;
    actual=new Nodo();
    auto it=d._claves.cbegin();
    while(it!=d._claves.cend()){
        int i=0;
        while(i<it->size()-1) {
            actual->siguientes[*it[i]]=new Nodo();
            i++;
        }
        actual->siguientes[*it[i]]=new Nodo(d.raiz[*it[i]]);
        it++;
    }
*/
    return *this;
}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
    Kaboom();
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
    /*
     * while(i<clave.size()){
        bool bifurca= false;
        int j=0;
        while(not bifurca and j<actual->siguientes.size()){
            if (actual->siguientes[j]!= nullptr){
                bifurca= true;
            }else{
                desde=j;
                j++;
            }
        }
    }
     */
    Nodo* ultimaClave=actual;
    string pal;
    for (auto& c : clave){
        actual=actual->siguientes[c];
        if (actual->definicion!= nullptr){
            ultimaClave=actual;
        }

    }
    int j=0;
    bool sigue= false;
    if (actual!= nullptr) {
        for (auto &p: actual->siguientes) {
            if (p != nullptr) {
                sigue = true;
            }
        }
    }
    if (sigue){
        delete actual->definicion;

    }else{
        Nodo* desde;
        if (ultimaClave->definicion==actual->definicion){
            desde=raiz;
        } else {
            desde = ultimaClave;
        }
        for (auto& c : clave) {
                Nodo *prox = desde->siguientes[c];
                delete desde;
                desde= prox;
                if (desde->definicion==actual->definicion){
                    delete desde->definicion;
                }
        }


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
    borrarNodos(raiz);
}