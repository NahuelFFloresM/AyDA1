#ifndef ARBOL_BINARIO_H_INCLUDED
#define ARBOL_BINARIO_H_INCLUDED
#include "climits"

template <typename elemA> class Arbol{

    struct nodo_arbol {
        elemA elemento;
        nodo_arbol * izq;
        nodo_arbol * der;
    };


    int cant;

public:
    Arbol();
    ~Arbol();

    nodo_arbol* Raiz;

    void agregar(nodo_arbol * &cursor,const elemA elemento);

    int cantidad_elementos();

    bool verificar(nodo_arbol * cursor,elemA elemento);

    bool es_vacio();

    int altura_arbol(nodo_arbol * cursor);

    bool eliminar_elemento(const elemA elemento);

    void pre_agregar(const elemA elemento);

    void mostrar_inorder(nodo_arbol * cursor);

    bool es_hoja(nodo_arbol * cursor);

    void mostrar_frontera(nodo_arbol * cursor);

    void mostrar();
};
#endif
