#ifndef FILA_CRITERIO_H
#define FILA_CRITERIO_H

#include "../fila.h"
#include "Cliente.h"

class fila_criterio: public Fila<Cliente> {
    public:
        fila_criterio();
        virtual ~fila_criterio();

    protected:

    private:
};

#endif // FILA_CRITERIO_H
