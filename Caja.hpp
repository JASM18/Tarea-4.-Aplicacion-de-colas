#ifndef CAJA_HPP_INCLUDED
#define CAJA_HPP_INCLUDED

#include <string>

#include "Persona.hpp"
#include "Cola.hpp"

class Caja{

public:

    Caja();

    void AgregarPersona(Persona persona);

    void AtenderMinuto();

    int ObtenerTiempo();

    int ObtenerTiempoRestante();

    std::string ObtenerNombre();

    bool EstaOcupada();

    bool Desocupar();

    Cola<std::string>& ObtenerHistorial();

private:

    bool ocupada;

    Persona persona;

    int tiempoRestante;

    Cola<std::string> listaAtendidos;

};

#endif // CAJA_HPP_INCLUDED
