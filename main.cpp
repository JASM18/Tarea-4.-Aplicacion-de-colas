#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

#include "Cola.hpp"
#include "Persona.hpp"
#include "Caja.hpp"
#include "Aleatorio.hpp"
#include "Cursor.hpp"

using namespace std;

int main()
{
    srand(time(NULL));

    cout << "===============================" << endl;
    cout << "SIMULACI\340N DE BANCO CON 3 CAJAS" << endl;
    cout << "===============================\n" << endl;

    int tiempoDeAtencion = aleatorio(120, 240);
    int tiempo1, tiempo2, tiempo3;

    Cola<Persona> colaEspera;
    Cola<string> lista1_Atendidos, lista2_Atendidos, lista3_Atendidos;

    Caja caja1, caja2, caja3;

    cout << "La caja atender\240 a cuantas personas pueda en " << tiempoDeAtencion << " minutos." << endl;
    cout << "El tiempo de atenci\242n por persona es aleatorio." << endl;

    cout << endl;
    system("pause");
    system("CLS");

    CambiarCursor(APAGADO);

    int esperaAgregar = aleatorio(0, 4);

    for(int i = 1 ; i <= tiempoDeAtencion ; ++i){

        // ===================
        // PROCESO DE ATENCION
        // ===================

        // Si la caja esta desocupada y hay al menos un cliente esperando...
        if( !caja1.EstaOcupada() && !colaEspera.EstaVacia() ){

            caja1.AgregarPersona(colaEspera.ObtenerCabeza());
            colaEspera.Eliminar();
            tiempo1 = caja1.ObtenerTiempo();

        }else if(caja1.EstaOcupada()){ // Si la caja esta ocupada...

            tiempo1--;

            //cuando el contador sea 0 agregar a la cola de atendidos
            if(tiempo1 == 0){
                lista1_Atendidos.Agregar(caja1.ObtenerNombre());
                caja1.Desocupar();
            }
        }

        // CAJA 2
        if( !caja2.EstaOcupada() && !colaEspera.EstaVacia() ){

            caja2.AgregarPersona(colaEspera.ObtenerCabeza());
            colaEspera.Eliminar();
            tiempo2 = caja2.ObtenerTiempo();

        }else if(caja2.EstaOcupada()){ // Si la caja esta ocupada...

            tiempo2--;

            //cuando el contador sea 0 agregar a la cola de atendidos
            if(tiempo2 == 0){
                lista2_Atendidos.Agregar(caja2.ObtenerNombre());
                caja2.Desocupar();
            }
        }

        // CAJA 3
        if( !caja3.EstaOcupada() && !colaEspera.EstaVacia() ){

            caja3.AgregarPersona(colaEspera.ObtenerCabeza());
            colaEspera.Eliminar();
            tiempo3 = caja3.ObtenerTiempo();

        }else if(caja3.EstaOcupada()){ // Si la caja esta ocupada...

            tiempo3--;

            //cuando el contador sea 0 agregar a la cola de atendidos
            if(tiempo3 == 0){
                lista3_Atendidos.Agregar(caja3.ObtenerNombre());
                caja3.Desocupar();
            }
        }

        // ==========
        // LLEGAN CLIENTES
        // ==========

        if(esperaAgregar > 0){
            esperaAgregar--;

        }else{
            //al esperar el tiempo agrega una persona a la lista de espera
            Persona personita;
            colaEspera.Agregar(personita);

            esperaAgregar = aleatorio(0, 7);
        }

        // ==========
        // IMPRIMIR ESTADO
        // ==========

        cout << "Las cajas atenderan a cuantas personas pueda en " << tiempoDeAtencion << " minutos." << endl;
        cout << "Reloj: " << i;

        // Estado caja 1
        MoverCursor(5, 4);
        cout << "Caja 1:";

        MoverCursor(5, 5);
        if(caja1.EstaOcupada()){
            cout << "Atendiendo a: " << caja1.ObtenerNombre();
        }else{
            cout << "La caja esta desocupada";
        }

        if(caja1.EstaOcupada()){
            MoverCursor(5, 6);
            cout << "Tiempo de atencion: " << caja1.ObtenerTiempo() - tiempo1;
        }

        // Estado caja 2
        MoverCursor(40, 4);
        cout << "Caja 2:";

        MoverCursor(40, 5);
        if(caja2.EstaOcupada()){
            cout << "Atendiendo a: " << caja2.ObtenerNombre();
        }else{
            cout << "La caja esta desocupada";
        }

        if(caja2.EstaOcupada()){
            MoverCursor(40, 6);
            cout << "Tiempo de atencion: " << caja2.ObtenerTiempo() - tiempo2;
        }

        // Estado caja 3
        MoverCursor(80, 4);
        cout << "Caja 3:";

        MoverCursor(80, 5);
        if(caja3.EstaOcupada()){
            cout << "Atendiendo a: " << caja3.ObtenerNombre();
        }else{
            cout << "La caja esta desocupada";
        }

        if(caja3.EstaOcupada()){
            MoverCursor(80, 6);
            cout << "Tiempo de atencion: " << caja3.ObtenerTiempo() - tiempo3;
        }

        // Estado de espera
        //MoverCursor(0, 8);
        //cout << "Espera para agregar: " << esperaAgregar << endl;

        MoverCursor(0,8);
        cout << "En espera: " << endl;
        ImprimirColumnaEspera(colaEspera);

        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("CLS");
    }

    // ===================
    // Se acabó el tiempo!
    // ===================

    system("CLS");

    cout << "===================" << endl;
    cout << "SE ACABO EL TIEMPO" << endl;
    cout << "===================" << endl << endl;

    cout << "Termino el tiempo de atención de las cajas (Tiempo: " << tiempoDeAtencion << " min)" << endl;

    // Reporte caja 1
    cout << "\n-> Reporte caja 1:" << endl;

    if(caja1.EstaOcupada()){
        cout << "Terminará de atender a: " << caja1.ObtenerNombre() << endl;
    }else{
        cout << "Termino desocupada." << endl;
    }

    cout << "Total de atendidos: " << lista1_Atendidos.ObtenerNumElem() << endl;;

    cout << "Lista de atendidos:" << endl;
    while(!lista1_Atendidos.EstaVacia()){
        cout << "- " << lista1_Atendidos.ObtenerCabeza();
        lista1_Atendidos.Eliminar();
        cout << endl;
    }

    // Reporte caja 2
    cout << "\n-> Reporte caja 2:" << endl;

    if(caja2.EstaOcupada()){
        cout << "Terminará de atender a: " << caja2.ObtenerNombre() << endl;
    }else{
        cout << "Termino desocupada." << endl;
    }

    cout << "Total de atendidos: " << lista2_Atendidos.ObtenerNumElem() << endl;;

    cout << "Lista de atendidos:" << endl;
    while(!lista2_Atendidos.EstaVacia()){
        cout << "- " << lista2_Atendidos.ObtenerCabeza();
        lista2_Atendidos.Eliminar();
        cout << endl;
    }

    // Reporte caja 3
    cout << "\n-> Reporte caja 3:" << endl;

    if(caja3.EstaOcupada()){
        cout << "Terminará de atender a: " << caja3.ObtenerNombre() << endl;
    }else{
        cout << "Termino desocupada." << endl;
    }

    cout << "Total de atendidos: " << lista3_Atendidos.ObtenerNumElem() << endl;;

    cout << "Lista de atendidos:" << endl;
    while(!lista3_Atendidos.EstaVacia()){
        cout << "- " << lista3_Atendidos.ObtenerCabeza();
        lista3_Atendidos.Eliminar();
        cout << endl;
    }

    // Lista de espera final
    cout << "\n\n";
    cout << "- - - - -" << endl;
    cout << "Quedaron " << colaEspera.ObtenerNumElem() << " personas por atender:" << endl;

    if(!colaEspera.EstaVacia()){
        while(!colaEspera.EstaVacia()){
            cout << "- " << colaEspera.ObtenerCabeza().ObtenerNombre() << " (Iba a tardar " << colaEspera.ObtenerCabeza().ObtenerTiempo() << " min)" << endl;
            colaEspera.Eliminar();
        }
    }

    cout << "\n\nSimulacion terminada." << endl;

    system("pause");
    return 0;
}
