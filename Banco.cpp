/**
 * \file Banco.cpp
 * Este archivo contiene la implementaci&oacute;n de los m&eacute;todos de la clase Banco y la l&oacute;gica de la simulaci&oacute;n.
 * \authors
    S&aacute;nchez Montoy, Jes&uacute;s Axel
    Portugal Arreola, Marian Bethsab&eacute;
 * \date 16/03/2026
 */

#include <iostream>
#include <thread>
#include <chrono>

#include "Banco.hpp"
#include "Aleatorio.hpp"
#include "Cursor.hpp"

//**********************************************
// CONSTRUCTORES
//**********************************************

Banco::Banco()
{
    tiempoDeAtencion = aleatorio(120, 240);
}

//**********************************************
// MÉTODOS DE CLASE
//**********************************************

int Banco::ObtenerTiempoDeAtencion()
{
    return tiempoDeAtencion;
}

//**********************************************

void Banco::ImprimirColumnaEspera(Cola<Persona>& fila)
{
    int cantidad = fila.ObtenerNumElem();
    if(cantidad == 0) return;

    for(int i = 0 ; i < cantidad ; i++){
        Persona p = fila.ObtenerCabeza();
        fila.Eliminar();
        cout << "- " << p.ObtenerNombre() << endl;
        fila.Agregar(p);
    }
}

//**********************************************

void Banco::IniciarSimulacion()
{
    CambiarCursor(APAGADO);
    int esperaAgregar = aleatorio(0, 4);

    for(int i = 1 ; i <= tiempoDeAtencion ; ++i){

        // ===================
        // PROCESO DE ATENCION
        // ===================

        // CAJA 1
        if( !caja1.EstaOcupada() && !colaEspera.EstaVacia() ){
            caja1.AgregarPersona(colaEspera.ObtenerCabeza());
            colaEspera.Eliminar();
        }else{
            caja1.AtenderMinuto();
        }

        // CAJA 2
        if( !caja2.EstaOcupada() && !colaEspera.EstaVacia() ){
            caja2.AgregarPersona(colaEspera.ObtenerCabeza());
            colaEspera.Eliminar();
        }else{
            caja2.AtenderMinuto();
        }

        // CAJA 3
        if( !caja3.EstaOcupada() && !colaEspera.EstaVacia() ){
            caja3.AgregarPersona(colaEspera.ObtenerCabeza());
            colaEspera.Eliminar();
        }else{
            caja3.AtenderMinuto();
        }

        // ==========
        // LLEGAN CLIENTES
        // ==========

        if(esperaAgregar > 0){
            esperaAgregar--;

        }else{
            //al esperar el tiempo agrega una persona a la lista de espera
            Persona cliente;
            colaEspera.Agregar(cliente);

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
            cout << "Tiempo de atencion: " << caja1.ObtenerTiempo() - caja1.ObtenerTiempoRestante();
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
            cout << "Tiempo de atencion: " << caja2.ObtenerTiempo() - caja2.ObtenerTiempoRestante();
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
            cout << "Tiempo de atencion: " << caja3.ObtenerTiempo() - caja3.ObtenerTiempoRestante();
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
}

//**********************************************

void Banco::MostrarReporteFinal()
{

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

    Cola<string> lista1 = caja1.ObtenerHistorial();
    cout << "Total de atendidos: " << lista1.ObtenerNumElem() << endl;;

    cout << "Lista de atendidos:" << endl;
    while(!lista1.EstaVacia()){
        cout << "- " << lista1.ObtenerCabeza() << endl;
        lista1.Eliminar();
    }


    // Reporte caja 2
    cout << "\n-> Reporte caja 2:" << endl;

    if(caja2.EstaOcupada()){
        cout << "Terminará de atender a: " << caja2.ObtenerNombre() << endl;
    }else{
        cout << "Termino desocupada." << endl;
    }

    Cola<string> lista2 = caja2.ObtenerHistorial();
    cout << "Total de atendidos: " << lista2.ObtenerNumElem() << endl;;

    cout << "Lista de atendidos:" << endl;
    while(!lista2.EstaVacia()){
        cout << "- " << lista2.ObtenerCabeza() << endl;
        lista2.Eliminar();
    }


    // Reporte caja 3
    cout << "\n-> Reporte caja 3:" << endl;

    if(caja3.EstaOcupada()){
        cout << "Terminará de atender a: " << caja3.ObtenerNombre() << endl;
    }else{
        cout << "Termino desocupada." << endl;
    }

    Cola<string> lista3 = caja3.ObtenerHistorial();
    cout << "Total de atendidos: " << lista3.ObtenerNumElem() << endl;;

    cout << "Lista de atendidos:" << endl;
    while(!lista3.EstaVacia()){
        cout << "- " << lista3.ObtenerCabeza() << endl;
        lista3.Eliminar();
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
}
