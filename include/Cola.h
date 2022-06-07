#ifndef COLA_H
#define COLA_H


template <typename elemL> class Cola
{
    protected:

    private:
        struct nodo_lista {
            elemL elemento;
            nodo_lista * sig;
        };


        int cant;
        void vaciar(nodo_lista * & primero);

    public:

        Cola();
        virtual ~Cola();

        nodo_lista * Primero;

        void agregar(const elemL elemento);

        int cantidad_elementos();

        elemL verificar();

        bool es_vacia();

        bool eliminar_elemento();
};

#endif // COLA_H
