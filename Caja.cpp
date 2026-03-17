#include <iostream>

#include "Caja.hpp"

//**********************************************
// CONSTRUCTOR
//**********************************************

Caja::Caja()
{
    ocupada = false;
    tiempoRestante = 0;
}

//**********************************************
// MÉTODOS PUBLICOS DE LA CLASE
//**********************************************

void Caja::AgregarPersona(Persona personaAgregar)
{
    ocupada = true;
    persona = personaAgregar;
    tiempoRestante = persona.ObtenerTiempo();
}

//**********************************************

void Caja::AtenderMinuto()
{
    if(ocupada){

        tiempoRestante--;

        if(tiempoRestante == 0){
            listaAtendidos.Agregar(persona.ObtenerNombre());
            Desocupar();
        }
    }
}

//**********************************************

int Caja::ObtenerTiempo()
{
    return persona.ObtenerTiempo();
}

//**********************************************

int Caja::ObtenerTiempoRestante()
{
    return tiempoRestante;
}

//**********************************************

std::string Caja::ObtenerNombre()
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
    tiempoRestante = 0;
    return ocupada;
}

//**********************************************

Cola<std::string>& Caja::ObtenerHistorial()
{
    return listaAtendidos;
}
