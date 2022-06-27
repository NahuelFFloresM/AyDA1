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
        fila_criterio(Criterio criter);
        virtual ~fila_criterio();

        void setCriterio(const std::string crit){
            criter.setCriterio(crit);
        }

        bool cumple_criterio(Cliente cli){
            if (criter.cumple_criterio(cli)) return true;
            return false;
        }

        bool cumple_criterio(Cliente * cli){
            if (criter.cumple_criterio(cli)) return true;
            return false;
        }


        std::string getCriterioText(){
            return this->criter.getCriterio();
        }

        Criterio getCriterio(){
            return this->criter;
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
