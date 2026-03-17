/**
 * \file Banco.hpp
 * Este archivo contiene la definici&oacute;n de la clase Banco, encargada de gestionar la simulaci&oacute;n de las cajas y la cola de espera.
 * \authors
    S&aacute;nchez Montoy, Jes&uacute;s Axel
    Portugal Arreola, Marian Bethsab&eacute;
 * \date 15/03/2026
 * \code{.cpp}
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
 * \endcode
 */

#ifndef BANCO_HPP_INCLUDED
#define BANCO_HPP_INCLUDED

#include <string>

#include "Cola.hpp"
#include "Persona.hpp"
#include "Caja.hpp"

using namespace std;

/**
 * \brief Clase que representa la simulaci&oacute;n de un banco con una cola de clientes y 3 cajas de atenci&oacute;n.
 */
class Banco{

public:

    /** \brief Constructor por default que inicializa el banco y define aleatoriamente su tiempo total de atenci&oacute;n (entre 120 y 240 min).
     */
    Banco();

    /** \brief M&eacute;todo que inicia el reloj y el ciclo de atenci&oacute;n de clientes en las cajas.
     *
     * \return void
     */
    void IniciarSimulacion();

    /** \brief M&eacute;todo que imprime un resumen al finalizar el tiempo de atenci&oacute;n del banco.
     *
     * \return void
     */
    void MostrarReporteFinal();

    /** \brief M&eacute;todo que devuelve el tiempo total que el banco estar&aacute; atendiendo.
     *
     * \return Un n&uacute;mero entero que representa los minutos de atenci&oacute;n total.
     */
    int ObtenerTiempoDeAtencion();

private:

    int tiempoDeAtencion;           ///< Entero con el tiempo total de atenci&oacute;n del banco (entre 120 y 240 minutos)

    Caja caja1;                     ///< Objeto que representa la primera caja de atenci&oacute;n del banco
    Caja caja2;                     ///< Objeto que representa la segunda caja de atenci&oacute;n del banco
    Caja caja3;                     ///< Objeto que representa la tercera caja de atenci&oacute;n del banco

    Cola<Persona> colaEspera;       ///< Estructura de datos Cola que almacena a los clientes en espera

    /** \brief M&eacute;todo auxiliar privado que imprime los nombres de las personas formadas en la cola.
     *
     * \param fila Referencia a la cola de clientes en espera que se desea imprimir.
     * \return void
     */
    void ImprimirColumnaEspera(Cola<Persona>& fila);

};
#endif // BANCO_HPP_INCLUDED
