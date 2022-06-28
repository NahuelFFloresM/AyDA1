#ifndef BANCO_H
#define BANCO_H

#include "../fila.h"
#include "fila_criterio.h"
#include "Cliente.h"
#include "Criterio.h"
#include "../lista.h"

#include <string>

class Banco
{
    public:
        Banco();
        virtual ~Banco();

    protected:

    private:

        Fila<Cliente> * cola_llegada = new Fila<Cliente>();
        fila_criterio * pr_cola_especial;
        fila_criterio * sg_cola_especial;
        Lista<Cliente> * operaciones;


    public:
        void reencolar_clientes(fila_criterio * cola);
        void IngresarCliente(Cliente cl);
        void Atender_Prox_Cliente(int opcion);
        bool Abrir_Cola_Criterio(std::string crit,bool tieneCuenta);
        bool Cerrar_Cola_Especial(const int cola);
        bool pr_cola_abierto();
        bool sg_cola_abierto();
        std::string pr_cola_getcrit();
        std::string sg_cola_getcrit();
        void iniciar_iterador();
        void avanzar_iterador();
        Cliente elemento_iterador();
        bool final_iterador();
        int cantidad_colas_abiertas();


};

#endif // BANCO_H
