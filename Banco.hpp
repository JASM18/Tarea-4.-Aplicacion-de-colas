#ifndef BANCO_HPP_INCLUDED
#define BANCO_HPP_INCLUDED

#include <string>

#include "Cola.hpp"
#include "Persona.hpp"
#include "Caja.hpp"

using namespace std;

class Banco{

public:

    Banco();

    void IniciarSimulacion();

    void MostrarReporteFinal();

    int ObtenerTiempoDeAtencion();

private:

    // Tiempo de atencion del banco (120, 240)
    int tiempoDeAtencion;

    Caja caja1;
    Caja caja2;
    Caja caja3;

    Cola<Persona> colaEspera;

    void ImprimirColumnaEspera(Cola<Persona>& fila);

};
#endif // BANCO_HPP_INCLUDED
