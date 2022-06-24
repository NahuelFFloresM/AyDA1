#ifndef FILA_CRITERIO_H
#define FILA_CRITERIO_H

#include "../fila.h"
#include "Cliente.h"
#include "Criterio.h"
#include <string>

class fila_criterio: public Fila<Cliente> {

    private:
        Criterio criter;
        bool abierta = false;

    public:
        fila_criterio();
        virtual ~fila_criterio();

        void setCriterio(const std::string crit){
            criter.setCriterio(crit);
        }

        bool cumple_criterio(std::string crit, Cliente cli){
            if (criter.cumple_criterio(crit,cli)) return true;
            return false;
        }


        std::string getCriterio(){
            return this->criter.getCriterio();
        }

        bool abrir_cola(){
            this->abierta = true;
            return true;
        }

        bool cerrar_cola() {
            this->abierta = false;
            return true;
        }


};

#endif // FILA_CRITERIO_H
