#include <iostream>
#include "TurnoMenu.h"
#include "TurnoManager.h"

using namespace std;

TurnoMenu::TurnoMenu(const char* nombreArchivo)
    : _tareaManager(nombreArchivo), _cantidadOpciones(4)
{
}

void TurnoMenu:: mostrar()
{
    int opcion;

    do{
        system("cls");
        opcion = seleccionOpcion();
        system("cls");
        ejecutarOpcion(opcion);
        system("pause");
    }while (opcion != 0);
}

void TurnoMenu:: mostrarOpciones(){

    cout << "--- Menu Turnos ---" << endl;
    cout << "1. Agregar turno" << endl;
    cout << "2. Listar turnos" << endl;
    cout << "3. Modificar turno" << endl;
    cout << "4. Eliminar turno" << endl;
    cout << "0. Salir" << endl;
}

int TurnoMenu:: seleccionOpcion(){

    int opcion;
    mostrarOpciones();
    cout << "-------------------" << endl;
    cout << "Ingrese opcion: ";
    cin >> opcion;

    while (opcion < 0 || opcion > _cantidadOpciones){
        cout << "Opcion incorrecta..." << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;
    }

    return opcion;
}


void TurnoMenu:: ejecutarOpcion(int opcion)
{
switch(opcion) {
    case 1: {
        Turno t;
        t.Cargar();
        if(_tareaManager.agregarTurno(t))
            cout << "Turno agregado con exito." << endl;
        else
            cout << "Error al agregar turno." << endl;
        break;
    }
    case 2:
        _tareaManager.listarTurnos();
        break;
    case 3: {
        int id;
        cout << "Ingrese ID a modificar: ";
        cin >> id;
        Turno t;
        t.Cargar();
        if(_tareaManager.modificarTurnoPorId(id, t))
            cout << "Turno modificado." << endl;
        else
            cout << "Error al modificar turno." << endl;
        break;
    }
    case 4: {
        int id;
        cout << "Ingrese ID a eliminar: ";
        cin >> id;
        if(_tareaManager.eliminarTurnoPorId(id))
            cout << "Turno eliminado." << endl;
        else
            cout << "Error al eliminar turno." << endl;
        break;
    }
    case 5:
        cout << "\nVolviendo al menu principal...\n" << endl;
        break;
    default:
    cout << "Opcion invalida. Intente nuevamente." << endl;
        }
}
