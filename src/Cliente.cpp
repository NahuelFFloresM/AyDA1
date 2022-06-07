#include "Cliente.h"


void Cliente::setNombre(std::string name){
    this->nombre = name;
}

void Cliente::setEdad(int age){
    this->edad = age;
}

void Cliente::setEstado(bool estado){
    this->es_cliente = estado;
}

std::string Cliente::getNombre(){
    return this->nombre;
}

int Cliente::getEdad(){
    return this->edad;
}

bool Cliente::getEstado(){
    return this->es_cliente;
}

Cliente::Cliente()
{
    //ctor
}

Cliente::~Cliente()
{
    //dtor
}
