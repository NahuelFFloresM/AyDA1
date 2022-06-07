#ifndef BANCO_H
#define BANCO_H

#include "../fila.h"
#include "Cliente.h"
#include "Criterio.h"

#include <string>

class Banco
{
    public:
        Banco();
        virtual ~Banco();

    protected:

    private:

        Fila<Cliente> cola_llegada;
        Fila<Cliente> pr_cola_especial;
        Fila<Cliente> sg_cola_especial;

    public:
        bool IngresarCliente(Cliente cl);
        Cliente Atender_Prox_Cliente();
        bool Abrir_Cola_Criterio(const std::string crit);
        bool Cerrar_Cola_Especial(const int cola);
        void Listar_Operaciones(const int minimo, const int maximo);


};

#endif // BANCO_H
