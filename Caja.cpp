#include <iostream>

#include "Caja.hpp"

//**********************************************
// CONSTRUCTOR
//**********************************************

Caja::Caja()
{
    ocupada = false;
}

//**********************************************
// MÉTODOS PUBLICOS DE LA CLASE
//**********************************************

void Caja::AgregarPersona(Persona personaAgregar)
{
    ocupada = true;
    persona = personaAgregar;
}

//**********************************************

int Caja::ObtenerTiempo()
{
    return persona.ObtenerTiempo();
}

//**********************************************

string Caja::ObtenerNombre()
{
    return persona.ObtenerNombre();
}

//**********************************************

bool Caja::EstaOcupada()
{
    return ocupada;
}

//**********************************************

bool Caja::Desocupar()
{
    ocupada = false;
    return ocupada;
}
