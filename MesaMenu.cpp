#include <iostream>
#include "MesaMenu.h"
#include "MesaManager.h"

using namespace std;

MesaMenu::MesaMenu(const char* nombreArchivo)
    : _MesaManager(nombreArchivo), _cantidadOpciones(4)
{
}

void MesaMenu:: mostrarMenu()
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

void MesaMenu:: mostrarOpciones(){

    cout << "--- Menu Mesas ---" << endl;
    cout << "1. Agregar Mesa" << endl;
    cout << "2. Listar Mesas" << endl;
    cout << "3. Modificar Mesa" << endl;
    cout << "4. Eliminar Mesa" << endl;
    cout << "0. Salir" << endl;
}

int MesaMenu:: seleccionOpcion(){

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

void MesaMenu::ejecutarOpcion(int opcion) {
    do {
        switch (opcion) {
            case 1:
                _MesaManager.agregarMesa();
                break;
            case 2:
                _MesaManager.listarMesas();
                break;
            case 3:
                _MesaManager.modificarMesaPorId();
                break;
            case 4:
                _MesaManager.eliminarMesaPorId();
                break;
            case 0:
                cout << "\nVolviendo al menu principal...\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (false);
}
