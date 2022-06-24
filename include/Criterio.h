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
        bool cumple_criterio(const std::string crit,Cliente cli);

    protected:

    private:
        std::string operacion;
        bool cuenta;;
};

#endif // CRITERIO_H
