#include <iostream>
#include "ClienteMenu.h"
#include "ClienteManager.h"

using namespace std;

ClienteMenu::ClienteMenu(const char* nombreArchivo)
    : _ClienteManager(nombreArchivo), _cantidadOpciones(4)
{
}

void ClienteMenu:: mostrarMenu()
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

void ClienteMenu:: mostrarOpciones(){

    cout << "--- Menu Clientes ---" << endl;
    cout << "1. Agregar Cliente" << endl;
    cout << "2. Listar Clientes" << endl;
    cout << "3. Modificar Cliente" << endl;
    cout << "4. Eliminar Cliente" << endl;
    cout << "0. Salir" << endl;
}

int ClienteMenu:: seleccionOpcion(){

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

void ClienteMenu::ejecutarOpcion(int opcion) {
    do {
        switch (opcion) {
            case 1:
                _ClienteManager.agregarCliente();
                break;
            case 2:
                _ClienteManager.listarClientes();
                break;
            case 3:
                _ClienteManager.modificarClientePorId();
                break;
            case 4:
                _ClienteManager.eliminarClientePorId();
                break;
            case 0:
                cout << "\nVolviendo al menu principal...\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (false);
}

