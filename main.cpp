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
    cout << "Elemento Agregado: 1" << endl;
    valores.agregar(2);
    cout << "Elemento Agregado: 2" << endl;
    valores.agregar(3,1);
    cout << "Elemento Agregado: 3 en posición 1" << endl;
    cout << "Eliminando elemento 3..." << endl;
    if (valores.eliminar_elemento(3)) cout << "Elemento eliminado"<< endl;
    else cout << "Elemento no encontrado"<< endl;
    if (valores.es_vacia()) cout << "Lista vacia" << endl;
    else cout << "Lista con elementos-" << endl;
    cout << endl;
    /// PRUEBA DE ITERADOR
    cout << "//////Prueba de Iterador " << endl;
    valores.iniciar_iterador(); // Iterador iniciado.
    cout << "Elemento iterador: ";
    if (!valores.final_iterador()) cout << valores.elemento_iterador() << endl;
    cout << "Avanzando Iterador" << endl;
    valores.avanzar_iterador();
    cout << "Elemento iterador: ";
    if (!valores.final_iterador()) cout << valores.elemento_iterador() << endl;
    cout << "Avanzando Iterador" << endl;
    valores.avanzar_iterador();
    cout << "Elemento iterador: ";
    if (!valores.final_iterador()) cout << valores.elemento_iterador() << endl;
    else cout << "Fin iterador" << endl;

    /// Prueba de lista con String para probar parametrización.

    valores2.agregar("algo");
    valores2.agregar("algo2");
    valores2.agregar("algo3",2);
    if (valores2.verificar("algo3")) cout << "Valor encontrado" << endl;
    else cout << "No existe el valor en la lista" << endl;
    /*Como el programa no encuentra error a la hora de ejecucion se ejecutaron bien la sentencias*/
    //----------------------------FILA
    cout << "----------------------------FILA" << endl;
    cout << "Creando fila con valores: 1,2,3 " << endl;
    Fila<unsigned int> fila_vals;
    fila_vals.agregar(1);
    fila_vals.agregar(2);
    fila_vals.agregar(3);
    fila_vals.agregar(4);

    if (fila_vals.es_vacia()) cout << "Fila vacia" << endl;
    else cout << "Fila con elementos" << endl;
    cout << "Cantidad: "<< fila_vals.cantidad_elementos() << endl;
    cout << "Eliminando elemento de fila" << endl;
    fila_vals.eliminar_elemento();
    cout << "Siguiente elemento: " << fila_vals.verificar() << endl;

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

    if (Arbin.verificar_elemento("texto2")){
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
