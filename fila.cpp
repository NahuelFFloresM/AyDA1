#include "fila.h"

#include "Cliente.h"
#include <string>
#include <stdlib.h>

using namespace std;

template <typename elemL> Fila<elemL>::Fila() {

    this->Primero = NULL;
    this->cant = 0;
}

template <typename elemL> Fila<elemL>::~Fila() {
    vaciar(this->Primero);
}

template <typename elemL> void Fila<elemL>::vaciar(nodo_lista * & primero) {

    nodo_lista * aux;
    aux = primero;
    while (aux != NULL) {
        primero = primero->sig;
        delete aux;
        aux = primero;
    }
}

template <typename elemL> void Fila<elemL>::agregar(const elemL elemento){
    nodo_lista * aux = new nodo_lista;
    aux->elemento = elemento;
    aux->sig = NULL;
    nodo_lista * l = this->Primero;
    /**Recorro la lista de primero hasta el final y agrego el elemento*/
    if (l != NULL){
        nodo_lista * cursor = l;
        while (cursor->sig != NULL){
            cursor = cursor->sig;
        }
        cursor->sig = aux;
    } else {
        this->Primero = aux;
    }

    this->cant++;
}

template <typename elemL> int Fila<elemL>::cantidad_elementos(){
    return this->cant;
}

template <typename elemL> elemL Fila<elemL>::verificar(){
    return this->Primero->elemento;
}

template <typename elemL> bool Fila<elemL>::es_vacia(){
    return (this->Primero == NULL);
}

template <typename elemL> bool Fila<elemL>::eliminar_elemento(){
    nodo_lista * cursor = this->Primero;
    while (cursor != NULL){
        this->Primero = this->Primero->sig;
        delete(cursor);
        return true;
    }
    return false;
}

template class Fila<unsigned int>;
template class Fila<float>;
template class Fila<string>;
template class Fila<char>;
template class Fila<bool>;
template class Fila<Cliente>;
