#ifndef LISTA_EJEMPLO_H
#define LISTA_EJEMPLO_H

template <typename elemL> class Lista{

    struct nodo_lista {
        elemL elemento;
        nodo_lista * sig;
    };


    int cant;
    void vaciar(nodo_lista * & primero);

    public:

    Lista();
    ~Lista();

    nodo_lista * Primero, *it;

    void agregar(const elemL elemento , int posicion = 0);

    int cantidad_elementos();

    bool verificar( const elemL elemento);

    bool es_vacia() const;

    bool eliminar_elemento(const elemL elemento);

    void iniciar_iterador();

    void avanzar_iterador();

    elemL elemento_iterador();

    bool final_iterador();

};

#endif
