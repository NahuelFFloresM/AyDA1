#include "arbol.cpp"
#include "lista.cpp"
#include "fila.cpp"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    //--------------------LISTA
    cout << "--------------------LISTA" << endl;
    Lista<unsigned int> valores;
    Lista<string> valores2;
    // Armar menu para confirmar posicion
    valores.agregar(1);
    valores.agregar(2);
    valores.agregar(3,1);
    if (valores.eliminar_elemento(3)) cout << "Elemento eliminado"<< endl;
    valores.iniciar_iterador();
    ///Preguntar si lista vacia antes de pedir elemento??????-------------------------------
    ///O armar Menu en ciclo?
    cout << "Elemento iterador: " << valores.elemento_iterador() << endl;
    valores.avanzar_iterador();
    cout << "Avanznado Iterador" << endl;
    cout << "Elemento iterador: " << valores.elemento_iterador() << endl;

    valores2.agregar("algo");
    valores2.agregar("algo2");
    valores2.agregar("algo3",2);
    valores2.verificar("algo3");
    cout << "Lista enteros" << endl;
    valores.mostrar_lista();
    cout << endl;
    cout << "Lista con string" << endl;
    valores2.mostrar_lista();

    if (valores.es_vacia()) cout << "Lista vacia" << endl;
    else cout << "Lista con elementos-" << endl;

    cout << "Cantidad: "<< valores.cantidad_elementos() << endl;
    //----------------------------FILA
    cout << "----------------------------FILA" << endl;
    Fila<unsigned int> fila_vals;
    fila_vals.agregar(1);
    fila_vals.agregar(2);
    fila_vals.agregar(3);

    if (fila_vals.es_vacia()) cout << "Lista vacia" << endl;
    else cout << "Lista con elementos-" << endl;
    cout << "Cantidad: "<< fila_vals.cantidad_elementos() << endl;
    cout << "Eliminando elemento de fila" << endl;
    fila_vals.eliminar_elemento();
    fila_vals.verificar();

    //------------------------ARBIN
    cout << "------------------------ARBIN" << endl;
    Arbol<string> Arbin;
    Arbol<int> Arbol;

    Arbol.pre_agregar(2);
    Arbol.pre_agregar(1);
    Arbol.pre_agregar(3);
    Arbol.pre_agregar(8);
    Arbol.pre_agregar(6);
    Arbol.pre_agregar(5);

    Arbin.pre_agregar("texto2");
    Arbin.pre_agregar("texto");
    Arbin.pre_agregar("texto3");
    Arbin.pre_agregar("texto8");
    Arbin.pre_agregar("texto6");
    Arbin.pre_agregar("texto5");

    /**
        Codigo sin menu para ahorrar tiempo.
    */
    if (Arbol.es_vacio()) cout << "Arbol vacio" << endl;
    else cout << "Arbol con elementos" << endl;

    /**
        la funcion verificar/altura_arbol/mostrar_frontera necestia la raiz para empezar a recorrer, se podria crear una funcion
        que reciba la peticion del cliente para facilitar el trabajo al usuario.
    */
    if (Arbin.verificar(Arbin.Raiz,"texto2")){
        cout << "Elemento existente en el Arbol" << endl;
    }
    else cout << "Elemento inexistente en el Arbol" << endl;

    Arbol.mostrar();
    cout << endl;
    cout << "Cant. Elementos: " << Arbol.cantidad_elementos() << endl;
    cout << "Altura Arbol: " << Arbol.altura_arbol(Arbol.Raiz) <<endl;
    cout << "Frontera Arbol: "<< endl;
    Arbol.mostrar_frontera(Arbol.Raiz);


    return 0;
}
