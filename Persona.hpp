#ifndef PERSONA_HPP_INCLUDED
#define PERSONA_HPP_INCLUDED

#include <string>
#include "Cola.hpp"

using std::string;

class Persona{

public:

    Persona();

    string ObtenerNombre();

    int ObtenerTiempo();

private:

    string nombre;

    int tiempoEspera;

};

#endif // PERSONA_HPP_INCLUDED
