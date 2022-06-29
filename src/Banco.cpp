#include "Banco.h"
#include "../fila.cpp"
#include "../lista.cpp"

int Banco::cantidad_colas_abiertas(){
    int cant = 0;
    if (this->pr_cola_especial) cant++;
    if (this->sg_cola_especial) cant++;
    return cant;
}
std::string Banco::pr_cola_getcrit(){
    return this->pr_cola_especial->getCriterioText();
}

std::string Banco::sg_cola_getcrit(){
    return this->sg_cola_especial->getCriterioText();
}


void Banco::reencolar_clientes(fila_criterio * cola){
    cola_llegada->iniciar_iterador();
    while (!(cola_llegada->final_iterador())){
        Cliente aux = cola_llegada->elemento_iterador();
        if (cola->cumple_criterio(aux)){
            cola->agregar(aux);
            cola_llegada->eliminar_elem_lista(aux);
        }
        cola_llegada->avanzar_iterador();
    }
};

bool Banco::Abrir_Cola_Criterio(const std::string crit, bool tieneCuenta){
    Criterio criter;
    criter.setCriterio(crit);
    criter.setCuenta(tieneCuenta);
    if (this->pr_cola_especial == NULL){
        this->pr_cola_especial = new fila_criterio(criter);
        this->reencolar_clientes(pr_cola_especial);
        return true;
    }
    if (this->sg_cola_especial == NULL && crit != pr_cola_especial->getCriterioText()) {
        this->sg_cola_especial = new fila_criterio(criter);
        this->reencolar_clientes(sg_cola_especial);
        return true;
    }
    return false;
}
bool Banco::pr_cola_abierto(){
    if (this->pr_cola_especial == NULL) return false;
    return true;
}
bool Banco::sg_cola_abierto(){
    if (this->sg_cola_especial == NULL) return false;
    return true;
}
/*
*   @param opcion contiene el nro de cola a tomar el cliente
*/
Cliente Banco::Atender_Prox_Cliente(int opcion){
    Cliente aux;
    aux.setNombre("vacio");
    if (opcion == 1){
        if (cola_llegada->cantidad_elementos() > 0){
            aux = this->cola_llegada->obtenerElemento();
            this->operaciones->agregar(aux);
            cola_llegada->eliminar_elemento();
            return aux;
        }
    }
    if (opcion == 2){
        if (pr_cola_especial->cantidad_elementos() > 0){
            aux = this->pr_cola_especial->obtenerElemento();
            this->operaciones->agregar(this->pr_cola_especial->obtenerElemento());
            pr_cola_especial->eliminar_elemento();
            return aux;
        }
    }
    if (opcion == 3){
        if (sg_cola_especial->cantidad_elementos() > 0){
            aux = this->sg_cola_especial->obtenerElemento();
            this->operaciones->agregar(this->sg_cola_especial->obtenerElemento());
            sg_cola_especial->eliminar_elemento();
            return aux;
        }
    }
    return aux;
};

bool Banco::Cerrar_Cola_Especial(const int cola){
    if (cola == 1){
        if (this->pr_cola_especial->cantidad_elementos() == 0){
            delete(pr_cola_especial);
            this->pr_cola_especial = NULL;
            return true;
//            return pr_cola_especial->cerrar_cola();
        }
    } else {
        if (this->sg_cola_especial->cantidad_elementos() == 0){
            delete(sg_cola_especial);
            this->sg_cola_especial = NULL;
            return true;
//            return sg_cola_especial->cerrar_cola();
        }
    }
    return false;
};

void Banco::IngresarCliente(Cliente cl){
    /// INGRESAN COLAS CREADAS
    if ( (pr_cola_especial) && pr_cola_especial->getCriterio().cumple_criterio(cl)){
        pr_cola_especial->agregar(cl);
        return;
    }
    if ( (sg_cola_especial) && sg_cola_especial->getCriterio().cumple_criterio(cl)){
        sg_cola_especial->agregar(cl);
        return;
    }
    this->cola_llegada->agregar(cl);
}

void Banco::iniciar_iterador() {
    this->operaciones->iniciar_iterador();
}

void Banco::avanzar_iterador () {
    this->operaciones->avanzar_iterador();
}

Cliente Banco::elemento_iterador () {
    return this->operaciones->elemento_iterador();
}

bool Banco::final_iterador () {
    return this->operaciones->final_iterador();
}

Banco::Banco()
{
    this->pr_cola_especial = NULL;
    this->sg_cola_especial = NULL;
    this->operaciones = new Lista<Cliente>();
}

Banco::~Banco()
{
    delete(this->cola_llegada);
    delete(this->pr_cola_especial);
    delete(this->sg_cola_especial);
    delete(this->operaciones);
}
