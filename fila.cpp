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
    this->lista.eliminar_elemento(aux);
    return aux;
}

template <typename elemL> bool Fila<elemL>::es_vacia(){
    return (this->lista.es_vacia());
}

template <typename elemL> bool Fila<elemL>::eliminar_elemento(){
//    nodo_lista * cursor = this->Primero;
//    if (cursor != NULL){
//        this->Primero = this->Primero->sig;
//        delete(cursor);
//        return true;
//    }
//    return false;

    return this->lista.eliminar_elemento(this->lista.primer_elemento());
}

template <typename elemL> Lista<Cliente> Fila<elemL>::filtrar_x_criterio(Criterio crit){
    Lista<Cliente> filtrados;
//    this->lista.iniciar_iterador();
//    while(!lista.final_iterador()){
//        elemL aux = lista.elemento_iterador();
//        if (crit.cumple_criterio(aux)){
//
//        }
//    }
    return filtrados;
};


template class Fila<unsigned int>;
template class Fila<float>;
template class Fila<string>;
template class Fila<char>;
template class Fila<bool>;
template class Fila<Cliente>;
