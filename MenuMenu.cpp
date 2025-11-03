#include <iostream>
#include "MenuMenu.h"
#include "MenuManager.h"

using namespace std;

MenuMenu::MenuMenu(const char* nombreArchivo)
    : _MenuManager(nombreArchivo), _cantidadOpciones(4)
{
}

void MenuMenu:: mostrarMenu()
{
    int opcion;

    do{
        system("cls");
        opcion = seleccionOpcion();
        system("cls");
        ejecutarOpcion(opcion);
    }while (opcion != 0);
}

void MenuMenu:: mostrarOpciones(){

    cout << "---- Menu Menus ----" << endl;
    cout << "1. Agregar Menu" << endl;
    cout << "2. Listar Menus" << endl;
    cout << "3. Modificar Menu" << endl;
    cout << "4. Eliminar Menu" << endl;
    cout << "0. Volver" << endl;
}

int MenuMenu:: seleccionOpcion(){

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

void MenuMenu::ejecutarOpcion(int opcion) {
    do {
        switch (opcion) {
            case 1:
                _MenuManager.agregarMenu();
                break;
            case 2:
                _MenuManager.listarMenus();
                break;
            case 3:
                _MenuManager.modificarMenuPorId();
                break;
            case 4:
                _MenuManager.eliminarMenuPorId();
                break;
            case 0:
                cout << "\nVolviendo al menu principal...\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (false);
}
