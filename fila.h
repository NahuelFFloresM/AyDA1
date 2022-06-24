#ifndef FILA_EJEMPLO_H
#define FILA_EJEMPLO_H

#include "lista.h"
#include "Cliente.h"

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

        bool eliminar_elemento();

        Lista<Cliente>* filtar_x_criterio(std::string crit);

};

#endif
