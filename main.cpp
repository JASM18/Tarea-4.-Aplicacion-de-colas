#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

#include "Cola.hpp"
#include "Persona.hpp"
#include "Aleatorio.hpp"
#include "Caja.hpp"

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
    cout << "SIMULACI\340N DE BANCO CON 3 CAJAS" << endl;
    cout << "===============================\n" << endl;

    int tiempoDeAtencion = aleatorio(120, 240);
    Cola<Persona> colaEspera;
    Cola<string> colaAtendidos;
    Caja caja1, caja2, caja3;
    int tiempo1, tiempo2, tiempo3;

    cout << "La caja atender\240 a cuantas personas pueda en " << tiempoDeAtencion << " minutos." << endl;
    cout << "El tiempo de atenci\242n por persona es aleatorio." << endl;

    cout << endl;
    system("pause");
    system("CLS");


    int esperaAgregar = aleatorio(0, 15);

    for(int i = 1 ; i <= tiempoDeAtencion ; ++i){

        cout << "ITERACI\340N " << i << endl << endl;

        if(esperaAgregar > 0){
            esperaAgregar--;

        }else{
            //al esperar el tiempo agrega una persona a la lista de espera
            Persona personita;
            colaEspera.Agregar(personita);

            cout << "[EXITO] se agreg\242 la persona " << personita.ObtenerNombre() << " a la cola." << endl;

            esperaAgregar = aleatorio(0, 15);
        }

        cout << "\nespera para agregar: " << esperaAgregar << endl;


        //Inicia el proceso de atención
        if (colaEspera.EstaVacia() && !caja1.EstaOcupada() && !caja2.EstaOcupada() && !caja3.EstaOcupada()){
            continue;
        }else{
            //Si la caja está desocupada y hay al menos una persona eperando, se atiende a la persona en la caja 1
            if (!caja1.EstaOcupada() && !colaEspera.EstaVacia()){
                caja1.AgregarPersona(colaEspera.ObtenerCabeza());
                colaEspera.Eliminar();
                tiempo1 = caja1.ObtenerTiempo();

            //Si la caja está ocupada, si la cola está vacía, o ambos
            }else if(caja1.EstaOcupada() || colaEspera.EstaVacia())
                //decrementar el contador
                tiempo1--;

                //cuando el contador sea 0 agregar a la cola de atendidos
                if (tiempo1 == 0){
                    //agregar a cola
                    colaAtendidos.Agregar(caja1.ObtenerNombre());
                    //desocupar
                    caja1.Desocupar();
                }

            }

            if (!caja2.EstaOcupada() && !colaEspera.EstaVacia()){
                caja2.AgregarPersona(colaEspera.ObtenerCabeza());
                colaEspera.Eliminar();
                tiempo2 = caja2.ObtenerTiempo();

            }else{
                //decrementar el contador
                tiempo2--;

                //cuando el contador sea 0 agregar a la cola de atendidos
                if (tiempo2 == 0){
                    //agregar a cola
                    colaAtendidos.Agregar(caja2.ObtenerNombre());
                    //desocupar
                    caja2.Desocupar();
                }

            }

            if (!caja3.EstaOcupada() && !colaEspera.EstaVacia()){
                caja3.AgregarPersona(colaEspera.ObtenerCabeza());
                colaEspera.Eliminar();
                tiempo3 = caja3.ObtenerTiempo();

            }else{
                //decrementar el contador
                tiempo3--;

                //cuando el contador sea 0 agregar a la cola de atendidos
                if (tiempo3 == 0){
                    //agregar a cola
                    colaAtendidos.Agregar(caja3.ObtenerNombre());
                    //desocupar
                    caja3.Desocupar();
                }

            }

        }



        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("CLS");
    }





    system("pause");
    return 0;
}
