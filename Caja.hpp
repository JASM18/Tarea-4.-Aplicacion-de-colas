/**
 * \file Caja.hpp
 * Este archivo contiene la definici&oacute;n de la clase Caja, que representa una caja de atenci&oacute;n en el banco.
 * \authors
S&aacute;nchez Montoy, Jes&uacute;s Axel
Portugal Arreola, Marian Bethsab&eacute;
 * \date 15/03/2026
 * \code{.cpp}
#include <iostream>
#include "Caja.hpp"
#include "Persona.hpp"
#include "Cola.hpp"

int main() {

    Caja ventanilla;
    Persona cliente;

    if (!ventanilla.EstaOcupada()) {
        ventanilla.AgregarPersona(cliente);
        std::cout << "Atendiendo a: " << ventanilla.ObtenerNombre() << std::endl;
        std::cout << "Tiempo total requerido: " << ventanilla.ObtenerTiempo() << " min" << std::endl;
    }

    std::cout << "\n--- Iniciando atencion ---" << std::endl;
    while (ventanilla.EstaOcupada()) {
        std::cout << "Faltan: " << ventanilla.ObtenerTiempoRestante() << " min" << std::endl;

        ventanilla.AtenderMinuto();
    }

    Cola<std::string> historial = ventanilla.ObtenerHistorial();

    std::cout << "\n--- Corte de caja ---" << std::endl;
    std::cout << "Total de clientes atendidos: " << historial.ObtenerNumElem() << std::endl;

    return 0;
}
 * \endcode
 */

#ifndef CAJA_HPP_INCLUDED
#define CAJA_HPP_INCLUDED

#include <string>

#include "Persona.hpp"
#include "Cola.hpp"

/**
 * \brief Clase que gestiona una caja del banco.
 */
class Caja{

public:

    /** \brief Constructor por default que inicializa la caja como desocupada y con tiempo restante cero.
     */
    Caja();

    /** \brief M&eacute;todo que recibe a un cliente y lo asigna a la caja para comenzar a ser atendido.
     *
     * \param persona Objeto Persona que ocupar&aacute; la caja.
     * \return void
     */
    void AgregarPersona(Persona persona);

    /** \brief M&eacute;todo que simula el paso de un minuto atendiendo a un cliente.
     *
     * Reduce el tiempo restante y, si este llega a cero, a&ntilde;ade al cliente al historial y desocupa la caja.
     * \return void
     */
    void AtenderMinuto();

    /** \brief M&eacute;todo que devuelve el tiempo total que requiere la persona que est&aacute; siendo atendida.
     *
     * \return Entero con los minutos totales requeridos por el cliente actual.
     */
    int ObtenerTiempo();

    /** \brief M&eacute;todo que devuelve el tiempo que le falta a la caja para terminar de atender al cliente actual.
     *
     * \return Entero con los minutos restantes.
     */
    int ObtenerTiempoRestante();

    /** \brief M&eacute;todo que devuelve el nombre de la persona que est&aacute; siendo atendida.
     *
     * \return Cadena de caracteres con el nombre del cliente.
     */
    std::string ObtenerNombre();

    /** \brief M&eacute;todo que indica si la caja tiene un cliente asignado en este momento.
     *
     * \return true si la caja est&aacute; atendiendo a alguien, false si no hay nadie.
     */
    bool EstaOcupada();

    /** \brief M&eacute;todo que libera la caja.
     *
     * \return Devuelve false, dejando la caja desocupada.
     */
    bool Desocupar();

    /** \brief M&eacute;todo que devuelve el historial de todas las personas que fueron atendidas en esta caja.
     *
     * \return Referencia a una Cola de strings que contiene los nombres de los clientes atendidos.
     */
    Cola<std::string>& ObtenerHistorial();

private:

    bool ocupada;                       ///< Booleano que indica si la caja est&aacute; en uso.

    Persona persona;                    ///< Objeto Persona que representa al cliente actual.

    int tiempoRestante;                 ///< Cantidad de minutos que faltan para terminar de atender al cliente actual.

    Cola<std::string> listaAtendidos;   ///< Cola que contiene los nombres de los clientes ya atendidos.

};

#endif // CAJA_HPP_INCLUDED
