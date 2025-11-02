#include <iostream>
#include "MozoMenu.h"
#include "MozoManager.h"

using namespace std;

MozoMenu::MozoMenu(const char* nombreArchivo)
    : _MozoManager(nombreArchivo), _cantidadOpciones(4)
{
}

void MozoMenu:: mostrarMenu()
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

void MozoMenu:: mostrarOpciones(){

    cout << "--- Menu Mozos ---" << endl;
    cout << "1. Agregar Mozo" << endl;
    cout << "2. Listar Mozos" << endl;
    cout << "3. Modificar Mozo" << endl;
    cout << "4. Eliminar Mozo" << endl;
    cout << "0. Salir" << endl;
}

int MozoMenu:: seleccionOpcion(){

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

void MozoMenu::ejecutarOpcion(int opcion) {
    do {
        switch (opcion) {
            case 1:
                _MozoManager.agregarMozo();
                break;
            case 2:
                _MozoManager.listarMozos();
                break;
            case 3:
                _MozoManager.modificarMozoPorId();
                break;
            case 4:
                _MozoManager.eliminarMozoPorId();
                break;
            case 0:
                cout << "\nVolviendo al menu principal...\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (false);
}



