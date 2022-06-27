#ifndef LISTA_EJEMPLO_H
#define LISTA_EJEMPLO_H

#include <stdlib.h>
#include "Cliente.h"

template <typename elemL> class Lista{

    private:
        struct nodo_lista {
            elemL elemento;
            nodo_lista * sig;
        };


        int cant;
        void vaciar(nodo_lista * & primero);
        void remover_it_nodo();
        nodo_lista * Primero, *it, *it_previo;

    public:

        Lista();
        ~Lista();


        void agregar(elemL elemento , int posicion = 0);

        int cantidad_elementos();

        bool verificar( const elemL elemento);

        bool es_vacia() const;

        bool eliminar_elemento(const elemL elemento);

        void iniciar_iterador();

        void avanzar_iterador();

        elemL elemento_iterador();

        elemL obtener_elemento_it();

        bool final_iterador();

        elemL primer_elemento();

};

#endif
