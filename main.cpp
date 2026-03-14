#include <iostream>
#include <ctime>

#include "Persona.hpp"

using namespace std;

int main()
{
    srand(time(NULL));

    while(true){
        Persona a;
        cout << a.ObtenerNombre() << endl;
        cout << "Tiempo de espera: " << a.ObtenerTiempo() << endl << endl;

        if(a.ObtenerNombre() == "Marian Portugal") break;
    }

    cout << endl;
    system("pause");
    return 0;
}
