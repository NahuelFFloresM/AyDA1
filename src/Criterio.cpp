#include "Criterio.h"
#include <iostream>

void Criterio::setCriterio(const std::string crit){
    this->operacion = crit;
};

void Criterio::setCuenta(bool cuenta){
  this->cuenta = cuenta;
};

bool Criterio::cumple_criterio(Cliente cli){
    if ((this->operacion == cli.getOperacion()) && (this->cuenta == cli.getEstado())) return true;
    return false;
};

std::string Criterio::getCriterio(){
    return this->operacion;
}

Criterio::Criterio()
{
    //ctor
}

Criterio::~Criterio()
{
    //dtor
}
