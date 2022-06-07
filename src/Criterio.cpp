#include "Criterio.h"

void Criterio::setCriterio(const std::string crit){
    this->operacion = crit;
}

bool Criterio::cumple_criterio(std::string crit){
    return (crit == this->operacion);
}

bool Criterio::tiene_cuenta(Cliente cli){
    return (cli.getEstado() == true);
};

Criterio::Criterio()
{
    //ctor
}

Criterio::~Criterio()
{
    //dtor
}
