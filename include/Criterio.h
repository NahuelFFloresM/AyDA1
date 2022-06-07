#ifndef CRITERIO_H
#define CRITERIO_H

#include "Cliente.h"
#include <string>
class Criterio
{
    public:
        Criterio();
        virtual ~Criterio();
        void setCriterio(const std::string crit);
        bool cumple_criterio(const std::string crit);
        bool tiene_cuenta(Cliente cli);

    protected:

    private:
        std::string operacion;
};

#endif // CRITERIO_H
