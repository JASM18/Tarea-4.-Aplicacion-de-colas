/**
 * \file Persona.hpp
 * Este archivo contiene la definici&oacute;n de la clase Persona, la cual representa a un cliente en la simulaci&oacute;n del banco.
 * \authors
    S&aacute;nchez Montoy, Jes&uacute;s Axel
    Portugal Arreola, Marian Bethsab&eacute;
 * \date 13/03/2026
 * \code{.cpp}
#include <iostream>
#include "Persona.hpp"

using namespace std;

int main()
{

    Persona cliente;

    cout << "Nombre del cliente: " << cliente.ObtenerNombre() << endl;

    cout << "Tiempo que tendrá que esperar el cliente: " << cliente.ObtenerTiempo() << endl;

    return 0;
}
 * \endcode
 */

#ifndef PERSONA_HPP_INCLUDED
#define PERSONA_HPP_INCLUDED

#include <string>
#include "Cola.hpp"

using std::string;

/**
 * \brief Clase que representa a un cliente del banco con un nombre generado aleatoriamente y un tiempo de atenci&oacute;n asignado.
 */
class Persona{

public:

    /**
     * \brief Constructor por default que inicializa a la persona con un nombre y apellido aleatorios, as&iacute; como un tiempo de espera.
     */
    Persona();

    /**
     * \brief M&eacute;todo que devuelve el nombre generado para la persona.
     *
     * \return Cadena de caracteres con el nombre y apellido del cliente.
     */
    string ObtenerNombre();

    /**
     * \brief M&eacute;todo que devuelve el tiempo de atenci&oacute;n asignado al cliente.
     *
     * \return Un n&uacute;mero entero que representa el tiempo de espera en minutos.
     */
    int ObtenerTiempo();

private:

    string nombre;       ///< Cadena de caracteres que almacena el nombre completo de la persona.

    int tiempoEspera;    ///< Entero que representa el tiempo que tardar&aacute; la persona en ser atendida.

};

#endif // PERSONA_HPP_INCLUDED
