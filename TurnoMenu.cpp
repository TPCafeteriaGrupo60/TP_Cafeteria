#include <iostream>
#include "TurnoMenu.h"
#include "TurnoManager.h"
using namespace std;

TurnoMenu::TurnoMenu(const char* nombreArchivo)
    : _turnoManager(nombreArchivo), _cantidadOpciones(4)
{
}

void TurnoMenu:: mostrarMenu()
{
    int opcion;

    do{
        system("cls");
        opcion = seleccionOpcion();
        system("cls");
        ejecutarOpcion(opcion);
    }while (opcion != 0);
}

void TurnoMenu:: mostrarOpciones(){

    cout << "---- Menu Turnos ----" << endl;
    cout << "1. Agregar turno" << endl;
    cout << "2. Listar turnos" << endl;
    cout << "3. Modificar turno" << endl;
    cout << "4. Eliminar turno" << endl;
    cout << "0. Volver" << endl;
}

int TurnoMenu:: seleccionOpcion(){

    int opcion;
    mostrarOpciones();
    cout << "------------------------" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    while (opcion < 0 || opcion > _cantidadOpciones){
        cout << "\nOpcion incorrecta...\n" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
    }

    return opcion;
}

void TurnoMenu::ejecutarOpcion(int opcion) {
    do {
        switch (opcion) {
            case 1:
                _turnoManager.agregarTurno();
                break;
            case 2:
                _turnoManager.listarTurnos();
                break;
            case 3:
                _turnoManager.modificarTurnoPorId();
                break;
            case 4:
                _turnoManager.eliminarTurnoPorId();
                break;
            case 0:
                cout << "\nVolviendo al menu principal...\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (false);
}
