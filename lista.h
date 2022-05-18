#ifndef LISTA_EJEMPLO_H
#define LISTA_EJEMPLO_H

template <typename elemL> class Lista{

    struct nodo_lista {
        elemL elemento;
        nodo_lista * sig;
    };

    /*public:
        class Iterador {
            friend class Lista;
        public:
            elemL & elemento_actual();
            void avanzar();
            bool llego_al_final() const;
        private:
            Iterador(Nodo * inicio) { it = inicio; }
            Nodo * it;
        }; // class Iterador*/


    int cant;
    void vaciar(nodo_lista * & primero);

    public:

    Lista();
    ~Lista();

    nodo_lista * Primero;

//    Iterador devolver_iterador() { return Iterador(inicio); }

    void agregar(const elemL elemento , int posicion = 1);

    int cantidad_elementos();

    void mostrar_lista();

    void verificar(elemL elemento);

    bool es_vacia();

    bool eliminar_elemento(const elemL elemento);

};

#endif
