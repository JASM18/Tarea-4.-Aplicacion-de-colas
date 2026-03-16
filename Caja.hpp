#ifndef CAJA_HPP_INCLUDED
#define CAJA_HPP_INCLUDED

#include "Persona.hpp"

class Caja{

public:

    Caja();

    void AgregarPersona(Persona persona);

    int ObtenerTiempo();

    std::string ObtenerNombre();

    bool EstaOcupada();

    bool Desocupar();

private:

    bool ocupada;
    Persona persona;

};

#endif // CAJA_HPP_INCLUDED
