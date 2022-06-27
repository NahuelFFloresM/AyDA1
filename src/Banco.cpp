#include "Banco.h"
#include "../fila.cpp"
#include "../lista.cpp"

int Banco::cantidad_colas_abiertas(){
    int cant = 0;
    if (!this->pr_cola_especial) cant++;
    if (!this->sg_cola_especial) cant++;
    return cant;
}
std::string Banco::pr_cola_getcrit(){
    return this->pr_cola_especial->getCriterioText();
}

std::string Banco::sg_cola_getcrit(){
    return this->sg_cola_especial->getCriterioText();
}


void Banco::reencolar_clientes(fila_criterio * cola){
    Lista<Cliente> clientes;
    clientes = cola_llegada->filtrar_x_criterio(cola->getCriterio());
};

bool Banco::Abrir_Cola_Criterio(const std::string crit){
    Criterio criter;
    criter.setCriterio(crit);
    cout << "abriendo cola criterio" << endl;
    if (!this->pr_cola_especial){
        this->pr_cola_especial = new fila_criterio(criter);
        this->reencolar_clientes(pr_cola_especial);
        return true;
    }
    return false;
}
bool Banco::pr_cola_abierto(){
    return this->pr_cola_especial->abrir_cola();
}
bool Banco::sg_cola_abierto(){
    return this->sg_cola_especial->abrir_cola();
}
/*
*   @param opcion contiene el nro de cola a tomar el cliente
*/
void Banco::Atender_Prox_Cliente(int opcion){
    if (opcion == 1){
        this->operaciones->agregar(this->cola_llegada->obtenerElemento());
    }
    if (opcion == 2){
        this->operaciones->agregar(this->pr_cola_especial->obtenerElemento());
    }
    if (opcion == 3){
        this->operaciones->agregar(this->sg_cola_especial->obtenerElemento());
    }
};

bool Banco::Cerrar_Cola_Especial(const int cola){
    if (cola == 1){
        if (this->pr_cola_especial->es_vacia()){
            return pr_cola_especial->cerrar_cola();
        }
    } else {
        if (this->sg_cola_especial->es_vacia()){
            return sg_cola_especial->cerrar_cola();
        }
    }
    return false;
};

void Banco::IngresarCliente(Cliente cl){
    /// INGRESAR SEGUN COLAS CREADAS
    if (pr_cola_abierto() && pr_cola_especial->getCriterio().cumple_criterio(cl)){
        pr_cola_especial->agregar(cl);
        return;
    }
    if (sg_cola_abierto() && sg_cola_especial->getCriterio().cumple_criterio(cl)){
        sg_cola_especial->agregar(cl);
        return;
    }
    this->cola_llegada->agregar(cl);
}

void Banco::iniciar_iterador() {
    this->operaciones->iniciar_iterador();
}

void Banco::avanzar_iterador () {
    this ->operaciones->avanzar_iterador();
}

Cliente Banco::elemento_iterador () {
    this ->operaciones->elemento_iterador();
}

bool Banco::final_iterador () {
    this ->operaciones->final_iterador();
}

Banco::Banco()
{
    //ctor
}

Banco::~Banco()
{
    //dtor
}
