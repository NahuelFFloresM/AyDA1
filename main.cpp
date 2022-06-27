#include "arbol.cpp"
#include "lista.cpp"
#include "fila.cpp"
#include "Banco.h"

#include <iostream>

using namespace std;

Banco  * bnc = new Banco();
int opcion = -1;

void ingresar_usuario(){
    system("cls");
    /// Destinos: persona, banco o impuesto
    /// Operaciones: Retiro, Depósito, Transferencia o Pago
    int nro = rand() % 100+1;

    Cliente nuevoC;
    nuevoC.setNombre("Cliente" + nro);
    nuevoC.setEdad(nro);
    nuevoC.setMonto(rand() % 10000+1);
    // TO DO generar ingresos random
    nuevoC.setDestino("persona");
    nuevoC.setOperacion("retiro");
    nuevoC.setEstado(true);
    bnc->IngresarCliente(nuevoC);
    cout << "Nuevo cliente ingresado" << endl;
    system("pause");
};

void abrir_cola(){
    if (bnc->cantidad_colas_abiertas() < 2){
        string criterio = "retiro";
        bnc->Abrir_Cola_Criterio(criterio);
    } else {
        cout << "Cantidad maxima de colas alcanzadas" << endl;
    }
    system("pause");
};

void proxClienteCola(){
    if (bnc->cantidad_colas_abiertas() == 0){
        bnc->Atender_Prox_Cliente(1);
    } else {
        int opcion_cola = 1;
        cout << "Seleccione cola para atender cliente" << endl;
        cout << "1 - Cola general" << endl;
        if (bnc->pr_cola_abierto()) cout << "2 - Cola con Criterio: " << bnc->pr_cola_getcrit() << endl;
        if (bnc->sg_cola_abierto()) cout << "3 - Cola con Criterio: " << bnc->sg_cola_getcrit() << endl;
        cout << "---> ";
        cin >> opcion_cola;
        bnc->Atender_Prox_Cliente(opcion_cola);
    }
};
void cerrar_cola(){
    int cola;
    if ((!bnc->pr_cola_abierto()) && (!bnc->sg_cola_abierto())){
        cout << "Ninguna Cola especila Abierta" << endl;
    } else {
        cout << "Seleccion Cola a cerrar" << endl;
        if (bnc->pr_cola_abierto()) cout << "1 - Cola con criterio " << bnc->pr_cola_getcrit() << endl;
        if (bnc->sg_cola_abierto()) cout << "2 - COla con criterio " << bnc->sg_cola_getcrit() << endl;
        cout << "---> ";
        cin >> cola;
        if (bnc->Cerrar_Cola_Especial(cola)) cout << "Cola cerrada" << endl;
        else cout << "La cola no se encuentra vacia" << endl;
        system("pause");
    }
};
void listar_operaciones(){
    bnc->iniciar_iterador();
    float suma = 0;
    int contador = 0;
    int minimo, maximo;
    cout << "Ingresar monto minimo: " << endl;
    cin >> minimo;
    cout << "Ingresar monto maximo: " << endl;
    cin >> maximo;
    while (not bnc->final_iterador()) {
        if ((bnc->elemento_iterador().getMonto() >= minimo) && (bnc->elemento_iterador().getMonto() <= maximo)) {
            cout << bnc->elemento_iterador().getNombre() << endl;
            cout << bnc->elemento_iterador().getEdad() << endl;
            cout << bnc->elemento_iterador().getOperacion() << endl;
            cout << bnc->elemento_iterador().getDestino() << endl;
            cout << bnc->elemento_iterador().getMonto() << endl;
            if (bnc->elemento_iterador().getEstado()) {cout << "Es cliente del banco" << endl;}
            else {cout << "No es cliente del banco" << endl;}
            suma += bnc->elemento_iterador().getEdad();
            contador++;
        }
        bnc->avanzar_iterador();
    }
    cout << "El promedio de edadde los clientes del listado es " << (suma / contador) << endl;
};


int main(int argc, char *argv[])
{

    /// TPE PARTE 1
//    --------------------LISTA
//    cout << "--------------------LISTA" << endl;
//    Lista<unsigned int> valores;
//    Lista<string> valores2;
//     Armar menu para confirmar posicion
//    valores.agregar(1);
//    cout << "Elemento Agregado: 1" << endl;
//    valores.agregar(2);
//    cout << "Elemento Agregado: 2" << endl;
//    valores.agregar(3,1);
//    cout << "Elemento Agregado: 3 en posición 1" << endl;
//    cout << "Eliminando elemento 3..." << endl;
//    if (valores.eliminar_elemento(3)) cout << "Elemento eliminado"<< endl;
//    else cout << "Elemento no encontrado"<< endl;
//    if (valores.es_vacia()) cout << "Lista vacia" << endl;
//    else cout << "Lista con elementos-" << endl;
//    cout << endl;
//    / PRUEBA DE ITERADOR
//    cout << "//////Prueba de Iterador " << endl;
//    valores.iniciar_iterador(); // Iterador iniciado.
//    cout << "Elemento iterador: ";
//    if (!valores.final_iterador()) cout << valores.elemento_iterador() << endl;
//    cout << "Avanzando Iterador" << endl;
//    valores.avanzar_iterador();
//    cout << "Elemento iterador: ";
//    if (!valores.final_iterador()) cout << valores.elemento_iterador() << endl;
//    cout << "Avanzando Iterador" << endl;
//    valores.avanzar_iterador();
//    cout << "Elemento iterador: ";
//    if (!valores.final_iterador()) cout << valores.elemento_iterador() << endl;
//    else cout << "Fin iterador" << endl;
//
//    / Prueba de lista con String para probar parametrización.
//
//    valores2.agregar("algo");
//    valores2.agregar("algo2");
//    valores2.agregar("algo3",2);
//    if (valores2.verificar("algo3")) cout << "Valor encontrado" << endl;
//    else cout << "No existe el valor en la lista" << endl;
//    Como el programa no encuentra error a la hora de ejecucion se ejecutaron bien la sentencias
//    ----------------------------FILA
//    cout << "----------------------------FILA" << endl;
//    cout << "Creando fila con valores: 1,2,3,4 " << endl;
//    Fila<unsigned int> fila_vals;
//    fila_vals.agregar(1);
//    fila_vals.agregar(2);
//    fila_vals.agregar(3);
//    fila_vals.agregar(4);
//
//    if (fila_vals.es_vacia()) cout << "Fila vacia" << endl;
//    else cout << "Fila con elementos" << endl;
//    cout << "Cantidad: "<< fila_vals.cantidad_elementos() << endl;
//    cout << "Eliminando elemento de fila" << endl;
//    fila_vals.eliminar_elemento();
//    cout << "Siguiente elemento: " << fila_vals.obtenerElemento() << endl;
//
//    //------------------------ARBIN
//    cout << "------------------------ARBIN" << endl;
//    Arbol<string> Arbin;
//    Arbol<int> Arbol;
//
//    Arbol.pre_agregar(2);
//    Arbol.pre_agregar(1);
//    Arbol.pre_agregar(3);
//    Arbol.pre_agregar(8);
//    Arbol.pre_agregar(6);
//    Arbol.pre_agregar(5);
//
//    Arbin.pre_agregar("texto2");
//    Arbin.pre_agregar("texto");
//    Arbin.pre_agregar("texto3");
//    Arbin.pre_agregar("texto8");
//    Arbin.pre_agregar("texto6");
//    Arbin.pre_agregar("texto5");
//
//    /**
//        Codigo sin menu para ahorrar tiempo.
//    */
//    if (Arbol.es_vacio()) cout << "Arbol vacio" << endl;
//    else cout << "Arbol con elementos" << endl;
//
//    if (Arbin.verificar_elemento("texto2")){
//        cout << "Elemento existente en el Arbol" << endl;
//    }
//    else cout << "Elemento inexistente en el Arbol" << endl;
//
//    Arbol.mostrar();
//    cout << endl;
//    cout << "Cant. Elementos: " << Arbol.cantidad_elementos() << endl;
//    cout << "Altura Arbol: " << Arbol.altura_arbol(Arbol.Raiz) <<endl;
//    cout << "Frontera Arbol: "<< endl;
//    Arbol.mostrar_frontera(Arbol.Raiz);

    /// TPE PARTE 2

    bool uso_sistema = true;

    while(uso_sistema){
        system("cls");
        cout << "Sistema Banco" << endl;
        cout <<"--Menu-" <<endl;
        cout <<"1. Ingresar Cliente" <<endl;
        cout <<"2. Atender Proximo Cliente" <<endl;
        cout <<"3. Abrir Cola con criterio" <<endl;
        cout <<"4. Cerrar Cola especial" <<endl;
        cout <<"5. Listar Operacion por Monto" <<endl;
        cout <<"0. Salir" <<endl;
        cout << endl;
        cout << "Ingrese Opcion:" << endl;
        /// No se chequea si no es un nro el valor ingresado
        cin >> opcion;
        if (opcion == 1) ingresar_usuario();
        if (opcion == 2) proxClienteCola();
        if (opcion == 3) abrir_cola();
        if (opcion == 4) cerrar_cola();
        if (opcion == 5) listar_operaciones();
        if (opcion == 0){
            uso_sistema = false;
        }
        system("cls");
    }

    return 0;
}


