#ifndef CAJA_HPP_INCLUDED
#define CAJA_HPP_INCLUDED

#include "Persona.hpp"

class Caja{

public:

    Caja();
    void AgregarPersona(Persona persona);
    int ObtenerTiempo();
    string ObtenerNombre();
    bool EstaOcupada();

private:

    bool ocupada;
    Persona persona;

};



#endif // CAJA_HPP_INCLUDED
