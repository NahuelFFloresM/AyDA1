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
        std::string getNombre();
        int getEdad();
        bool getEstado();

    protected:

    private:
        std::string nombre;
        int edad;
        bool es_cliente;
};

#endif // CLIENTE_H
