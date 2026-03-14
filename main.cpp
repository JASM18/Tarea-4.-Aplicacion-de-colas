#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

#include "Cola.hpp"
#include "Persona.hpp"
#include "Aleatorio.hpp"

using namespace std;

int main()
{
    srand(time(NULL));

//    while(true){
//        Persona a;
//        cout << a.ObtenerNombre() << endl;
//        cout << "Tiempo de espera: " << a.ObtenerTiempo() << endl << endl;
//
//        if(a.ObtenerNombre() == "Marian Portugal") break;
//    }


    cout << "===============================" << endl;
    cout << "SIMULACIÓN DE BANCO CON 3 CAJAS" << endl;
    cout << "===============================\n" << endl;

    int tiempoDeAtencion = aleatorio(120, 240);

    cout << "La caja atenderá a cuantas personas pueda en " << tiempoDeAtencion << " minutos." << endl;
    cout << "El tiempo de atención por persona es aleatorio." << endl;

    cout << endl;
    system("pause");
    system("CLS");

    Cola<Persona> colita1;

    int esperaAgregar = aleatorio(1, 7);

    for(int i = 1 ; i <= tiempoDeAtencion ; ++i){


        cout << "ITERACION " << i << endl;

        if(esperaAgregar > 0) esperaAgregar--;

        if(esperaAgregar == 0){

            Persona personita;
            colita1.Agregar(personita);
            cout << "[EXITO] se agrego el eleemnto " << personita.ObtenerNombre() << " a la cola" << endl;
        }



        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("CLS");
    }



    system("pause");
    return 0;
}
