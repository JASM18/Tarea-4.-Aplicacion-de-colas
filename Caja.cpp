#include "Caja.hpp"

#include <iostream>

// Constructor
Caja::Caja()
{
    ocupada = false;
}

void Caja::AgregarPersona(Persona personaAgregar)
{
    ocupada = true;
    persona = personaAgregar;
}

int Caja::ObtenerTiempo()
{
    return persona.ObtenerTiempo();
}

string Caja::ObtenerNombre()
{
    return persona.ObtenerNombre();
}

bool Caja::EstaOcupada()
{
    return ocupada;
}
