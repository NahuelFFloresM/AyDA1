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
        void setCuenta(bool estado);
        std::string getCriterio();
        bool cumple_criterio(Cliente cli);
        bool cumple_criterio(Cliente * cli);

    protected:

    private:
        std::string operacion;
        bool cuenta;;
};

#endif // CRITERIO_H
