#ifndef LISTA_ITERADOR_EJEMPLO_H
#define LISTA_ITERADOR_EJEMPLO_H

template <typename elemL> class Lista_Iterador<elemL>::Lista_Iterador{


    public:

    Lista_Iterador();
    ~Lista_Iterador();

    nodo_lista * it;

    void avanzar();
    elemL elemento_actual();
    bool fin_lista();

};

#endif
