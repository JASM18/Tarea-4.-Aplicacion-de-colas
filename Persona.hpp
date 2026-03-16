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

void ImprimirColumnaEspera(Cola<Persona>& fila);

#endif // PERSONA_HPP_INCLUDED
