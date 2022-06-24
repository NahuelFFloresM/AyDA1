#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
class Cliente
{
    public:
        Cliente();
        virtual ~Cliente();
        void setNombre(std::string name);
        void setEdad(int age);
        void setEstado(bool estado);
        void setOperacion(std::string oper);
        void setDestino(std::string oper);
        void setMonto(int monto);
        std::string getNombre();
        int getEdad();
        bool getEstado();
        std::string getOperacion();
        std::string getDestino();
        int getMonto();
        bool operator==(Cliente cl2);


    protected:

    private:
        std::string nombre;
        int edad;
        bool es_cliente;
        std::string tipo_operacion;
        std::string destino_operacion;
        int monto;
};

#endif // CLIENTE_H
