#ifndef FILA_EJEMPLO_H
#define FILA_EJEMPLO_H

#include "lista.h"
#include "Cliente.h"
#include "Criterio.h"

template <typename elemL> class Fila{

    private:

        Lista<elemL> lista;

    public:

        Fila();
        ~Fila();

        void agregar(elemL elemento);

        int cantidad_elementos();

        elemL verificar();

        elemL obtenerElemento();

        bool es_vacia();

        void eliminar_elemento();

        void eliminar_elem_lista(elemL L);

        void iniciar_iterador();

        void avanzar_iterador();

        bool final_iterador();

        elemL elemento_iterador();

        elemL obtener_elemento_it();

};

#endif
