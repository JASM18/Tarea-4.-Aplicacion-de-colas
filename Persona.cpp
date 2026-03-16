#include "Persona.hpp"
#include "Aleatorio.hpp"

#include <iostream>
#include <string>

//**********************************************
// CONJUNTO DE NOMBRES Y APELLIDOS
//**********************************************

string Nombres[] = {"Mar\241a", "Jos\202", "Marian", "Alba", "Ivana",
"Axel", "Azelet", "David", "Aram", "Angel",
"Isaac", "Denzel", "Fernanda", "Ana", "Jovanna",
"Carolina", "Alejandro", "Alondra", "Jareth", "Mario",
"Paulina", "Miguel", "Marco", "Mayra", "Rodrigo", "Gok\243"};

//**********************************************

string Apellidos[] = {"P\202rez", "G\242mez", "Portugal", "Helleon", "Chenoweth",
"S\240nchez", "G\242nzalez", "Angulo", "Mcgrew", "Dur\242n",
"Espinoza", "Rivera", "Hern\240ndez", "Sortill\242n", "Reyes",
"Inzunza", "Cordero", "Rodr\241guez", "Garc\241a", "Ocejo",
"Boj\242rquez", "Rojas", "Munro", "Murillo", "Real"};

//**********************************************
// CONSTRUCTOR
//**********************************************

Persona::Persona()
{
    tiempoEspera = aleatorio(5, 20);
    int nomAleat = aleatorio(0, 25);
    int apAleat = aleatorio(0, 24);
    nombre = Nombres[nomAleat] + " " + Apellidos[apAleat];
}

//**********************************************
// MÉTODOS PUBLICOS DE LA CLASE
//**********************************************

std::string Persona::ObtenerNombre()
{
    return nombre;
}

//**********************************************

int Persona::ObtenerTiempo()
{
    return tiempoEspera;
}

//**********************************************
// FUNCIONES NO-MIEMBRO DE LA CLASE
//**********************************************

void ImprimirColumnaEspera(Cola<Persona>& fila)
{
    int cantidad = fila.ObtenerNumElem();

    if(cantidad == 0){
        //std::cout << "Nadie en fila." << std::endl;
        return;
    }

    for(int i = 0 ; i < cantidad ; i++){
        Persona p = fila.ObtenerCabeza();
        fila.Eliminar();

        std::cout << "- " << p.ObtenerNombre() << std::endl;

        fila.Agregar(p);
    }
}
