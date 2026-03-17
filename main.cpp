/**
 * \file main.cpp
 * Este archivo contiene la ejecuci&oacute;n principal para la simulaci&oacute;n de un banco con una cola de clientes y tres cajas.
 * \authors
    S&aacute;nchez Montoy, Jes&uacute;s Axel
    Portugal Arreola, Marian Bethsab&eacute;
 * \date 13/03/2026
 */

#include <iostream>
#include <ctime>

#include "Banco.hpp"
#include "Cursor.hpp"

using namespace std;

int main()
{
    srand(time(NULL));

    try{

        cout << "===============================" << endl;
        cout << "SIMULACI\340N DE BANCO CON 3 CAJAS" << endl;
        cout << "===============================\n" << endl;

        Banco miBanco;

        cout << "La caja atender\240 a cuantas personas pueda en " << miBanco.ObtenerTiempoDeAtencion() << " minutos." << endl;
        cout << "El tiempo de atenci\242n por persona es aleatorio." << endl;

        cout << endl;
        system("pause");
        system("CLS");

        CambiarCursor(APAGADO);

        miBanco.IniciarSimulacion();
        miBanco.MostrarReporteFinal();


    }catch(const char* mensaje){
        CambiarCursor(ENCENDIDO);
        cerr << "Error: " << mensaje << endl;
    }catch(const exception &error){
        CambiarCursor(ENCENDIDO);
        cerr << "Error: " << error.what();
    }catch(...){
        cerr << "El programa tuvo un error inesperado." << endl;
    }

    CambiarCursor(ENCENDIDO);

    system("pause");
    return 0;
}
