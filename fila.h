#ifndef FILA_EJEMPLO_H
#define FILA_EJEMPLO_H

template <typename elemL> class Fila{

    struct nodo_lista {
        elemL elemento;
        nodo_lista * sig;
    };


    int cant;
    void vaciar(nodo_lista * & primero);

    public:

    Fila();
    ~Fila();

    nodo_lista * Primero;

    void agregar(const elemL elemento);

    int cantidad_elementos();

    elemL verificar();

    bool es_vacia();

    bool eliminar_elemento();

};

#endif
