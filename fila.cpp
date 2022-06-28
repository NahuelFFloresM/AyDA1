#include "fila.h"

#include "Cliente.h"
#include <string>
#include <stdlib.h>

#include <iostream>

using namespace std;

template <typename elemL> Fila<elemL>::Fila() {

}

template <typename elemL> Fila<elemL>::~Fila() {

}

template <typename elemL> void Fila<elemL>::iniciar_iterador(){
    this->lista.iniciar_iterador();
};

template <typename elemL> elemL Fila<elemL>::elemento_iterador(){
    return this->lista.elemento_iterador();
};

template <typename elemL> void Fila<elemL>::avanzar_iterador(){
    this->lista.avanzar_iterador();
};

template <typename elemL> elemL Fila<elemL>::obtener_elemento_it(){
    return this->lista.obtener_elemento_it();
};

template <typename elemL> bool Fila<elemL>::final_iterador(){
    return this->lista.final_iterador();
};

//
//template <typename elemL> void Fila<elemL>::vaciar(nodo_lista * & primero) {
//
//    nodo_lista * aux;
//    aux = primero;
//    while (aux != NULL) {
//        primero = primero->sig;
//        delete aux;
//        aux = primero;
//    }
//}

template <typename elemL> void Fila<elemL>::agregar(elemL elemento){
//    nodo_lista * aux = new nodo_lista;
//    aux->elemento = elemento;
//    aux->sig = NULL;
//    nodo_lista * l = this->Primero;
//    /**Recorro la lista de primero hasta el final y agrego el elemento*/
//    if (l != NULL){
//        nodo_lista * cursor = l;
//        while (cursor->sig != NULL){
//            cursor = cursor->sig;
//        }
//        cursor->sig = aux;
//    } else {
//        this->Primero = aux;
//    }
    this->lista.agregar(elemento);
}

template <typename elemL> int Fila<elemL>::cantidad_elementos(){
    return this->lista.cantidad_elementos();
}

template <typename elemL> elemL Fila<elemL>::obtenerElemento(){
    elemL aux = this->lista.primer_elemento();
    return aux;
}

template <typename elemL> bool Fila<elemL>::es_vacia(){
    return (this->lista.es_vacia());
}

template <typename elemL> void Fila<elemL>::eliminar_elemento(){
    elemL aux = this->lista.primer_elemento();
    this->lista.eliminar_elemento(aux);
}

template <typename elemL> void Fila<elemL>::eliminar_elem_lista(elemL L){
    this->lista.eliminar_elemento(L);
}




template class Fila<unsigned int>;
template class Fila<float>;
template class Fila<string>;
template class Fila<char>;
template class Fila<bool>;
template class Fila<Cliente>;
