#include "arbol.h"

#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;


template <typename elemA> Arbol<elemA>::Arbol() {

    this->Raiz = NULL;
    this->cant = 0;

}

template <typename elemA> Arbol<elemA>::~Arbol() {
    delete this->Raiz;
}

template <typename elemA> void Arbol<elemA>::agregar(nodo_arbol * &cursor,const elemA elemento){
    if (cursor == NULL){
        nodo_arbol * aux = new nodo_arbol;
        aux->der = NULL;
        aux->izq = NULL;
        aux->elemento = elemento;
        cursor = aux;
        cant++;
    }
    else{
        if (cursor->elemento < elemento){
            agregar(cursor->der,elemento);
        }
        else{
            agregar(cursor->izq,elemento);
        }
    }
}

template <typename elemA> void Arbol<elemA>::pre_agregar(const elemA elemento){
    agregar(Raiz,elemento);
}

template <typename elemA> void Arbol<elemA>::mostrar_inorder(nodo_arbol * cursor){
    if (cursor != NULL){
        mostrar_inorder(cursor->izq);
        cout << cursor->elemento << "-";
        mostrar_inorder(cursor->der);
    }
}

template <typename elemA> bool Arbol<elemA>::verificar_elemento(elemA elemento){
    return verificar(this->Raiz, elemento);
}

template <typename elemA> bool Arbol<elemA>::verificar(nodo_arbol * cursor, elemA elemento){
    if (cursor != NULL){
        if (cursor->elemento == elemento){
            return true;
        }
        else{
            if (cursor->elemento < elemento){
                return verificar(cursor->der,elemento);
            }
            else return verificar(cursor->izq,elemento);
        }
    }
    else return false;
}

template <typename elemA> void Arbol<elemA>::mostrar(){
    nodo_arbol * cursor = Raiz;
    if (Raiz != NULL){
        mostrar_inorder(cursor);
    }
    else{ cout << "Arbol vacio" << endl;}
}

template <typename elemA> int Arbol<elemA>::cantidad_elementos(){
    return cant;
}

template <typename elemA> bool Arbol<elemA>::es_vacio(){
    return (Raiz == NULL);
}

template <typename elemA> int Arbol<elemA>::altura_arbol(nodo_arbol* cursor){
    if (cursor != NULL){
        return 1+max(altura_arbol(cursor->der),altura_arbol(cursor->izq));
    }
    else return 0;
}

template <typename elemA> bool Arbol<elemA>::es_hoja(nodo_arbol* cursor){
    if ((cursor->der == NULL) && (cursor->izq == NULL)) return true;
    else return false;
}

template <typename elemA> void Arbol<elemA>::mostrar_frontera(nodo_arbol * cursor){
    if (cursor != NULL){
        if (es_hoja(cursor)){ cout << cursor->elemento << "-";}
        else{
            mostrar_frontera(cursor->der);
            mostrar_frontera(cursor->izq);
        }
    }
}

//-------------------------------------
template class Arbol<unsigned int>;
template class Arbol<float>;
template class Arbol<string>;
template class Arbol<char>;
template class Arbol<bool>;
