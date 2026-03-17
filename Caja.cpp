/**
 * \file Caja.cpp
 * Este archivo contiene la implementaci&oacute;n de los m&eacute;todos de la clase Caja.
 * \authors
    S&aacute;nchez Montoy, Jes&uacute;s Axel
    Portugal Arreola, Marian Bethsab&eacute;
 * \date 15/03/2026
 */

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
