#include "lista.h"

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

template <typename elemL> Lista<elemL>::Lista() {

    this->Primero = NULL;
    this->cant = 0;

}

template <typename elemL> Lista<elemL>::~Lista() {
    vaciar(this->Primero);
}

template <typename elemL> void Lista<elemL>::vaciar(nodo_lista * & primero) {

    nodo_lista * aux;
    aux = primero;
    while (aux != NULL) {
        primero = primero->sig;
        delete aux;
        aux = primero;
    }
}

template <typename elemL> void Lista<elemL>::agregar(const elemL elemento,int posicion){
    nodo_lista * aux = new nodo_lista;
    aux->elemento = elemento;
    aux->sig = NULL;
    nodo_lista * l = this->Primero;

    if (l != NULL){
        if (posicion == 0){
            nodo_lista * cursor = l;
            while (cursor->sig != NULL){
                cursor = cursor->sig;
            }
            cursor->sig = aux;
        }
        else{
            if (posicion == 1){
                aux->sig = l;
                this->Primero = aux;
            }
            else{
                while (posicion > 1){
                    l = l->sig;
                    posicion--;
                }
                aux->sig = l->sig;
                l->sig = aux;
            }
        }
    }
    else{
        this->Primero = aux;
    }
    this->cant++;
    cout <<"Elemento agregado: " << elemento << endl;
}

template <typename elemL> int Lista<elemL>::cantidad_elementos(){
    return this->cant;
}

template <typename elemL> void Lista<elemL>::verificar(elemL elemento){
    nodo_lista * l = this->Primero;
    bool found = false;
    while ((!found) && (l != NULL)){
        if (l->elemento == elemento){
            found = true;
            cout << "El elemento existe en la lista" << endl;
        }
        else{
            l = l->sig;
        }
    }
    if (l == NULL) cout << "El elemento no existe en la lista" << endl;
}

template <typename elemL> bool Lista<elemL>::es_vacia(){
    if (Primero != NULL) return false;
    return true;
}

template <typename elemL> bool Lista<elemL>::eliminar_elemento(const elemL elemento){
    nodo_lista * cursor = Primero;
    nodo_lista * aux = cursor;
    bool found = false;
    while ((cursor != NULL) && (!found)){

            if (cursor->elemento == elemento){
                if (cursor == Primero) {
                    aux = cursor;
                    Primero = cursor->sig;
                    delete aux;
                }
                else{
                    aux->sig = cursor->sig;
                    delete cursor;
                }
                cant--;
                found = true;
            }
            else{
                aux = cursor;
                cursor = cursor->sig;
            }
    }
    return found;
}

template <typename elemL> void Lista<elemL>::mostrar_lista(){
    while (Primero != NULL){
        cout << Primero->elemento << "-";
        Primero = Primero->sig;
    }
    cout << endl;
}

template <typename Elem>
Elem & Lista<Elem>::Iterador::elemento_actual() {
    return it->elemento;
}

template <typename Elem>
void Lista<Elem>::Iterador::avanzar(){
    it = it->siguiente;
}

template <typename Elem>
bool Lista<Elem>::Iterador::llego_al_final() const{
    return (it == NULL);
}

template class Lista<unsigned int>;
template class Lista<float>;
template class Lista<string>;
template class Lista<char>;
template class Lista<bool>;
