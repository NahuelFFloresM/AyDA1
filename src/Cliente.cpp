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
void Cliente::setOperacion(std::string oper){
    this->tipo_operacion = oper;
}
void Cliente::setMonto(int monto){
    this->monto = monto;
}
void Cliente::setDestino(std::string destino){
    this->destino_operacion = destino;
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

std::string Cliente::getOperacion(){
    return this->tipo_operacion;
}

int Cliente::getMonto(){
    return this->monto;
}

std::string Cliente::getDestino(){
    return this->destino_operacion;
}

bool Cliente::operator==(Cliente cl2){
    return this->nombre == cl2.getNombre();
}

Cliente::Cliente()
{
    //ctor
}

Cliente::~Cliente()
{
    //dtor
}
