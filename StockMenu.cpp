#include <iostream>
#include "StockMenu.h"

using namespace std;

StockMenu::StockMenu(const char* nombreArchivo)
    : _StockManager(nombreArchivo), _cantidadOpciones(6) {}

void StockMenu::mostrarMenu()
{
    int opcion;
    do {
        system("cls");
        opcion = seleccionOpcion();
        system("cls");
        ejecutarOpcion(opcion);
        system("pause");
    } while (opcion != 0);
}

void StockMenu::mostrarOpciones()
{
    cout << "STOCK" << endl;
    cout << "---" << endl;
    cout << "1 - AGREGAR PRODUCTO" << endl;
    cout << "2 - MODIFICAR PRODUCTO" << endl;
    cout << "3 - ELIMINAR PRODUCTO" << endl;
    cout << "4 - LISTAR PRODUCTOS" << endl;
    cout << "5 - CONSULTAS DE STOCK" << endl;
    cout << "6 - ALERTA DE STOCK MINIMO" << endl;
    cout << "0 - VOLVER" << endl;
    cout << "---" << endl;
}

int StockMenu::seleccionOpcion()
{
    int opcion;
    mostrarOpciones();
    cout << "OPCION: ";
    cin >> opcion;

    while (opcion < 0 || opcion > _cantidadOpciones)
    {
        cout << "Opcion incorrecta..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }
    return opcion;
}

void StockMenu::ejecutarOpcion(int opcion)
{
    switch (opcion)
    {
    case 1:
        _StockManager.agregarStock();
        break;
    case 2:
        _StockManager.modificarStockPorId();
        break;
    case 3:
        _StockManager.eliminarStockPorId();
        break;
    case 4:
        _StockManager.listarStocks();
        break;
    case 5:
        _StockManager.menuConsultas();
        break;
    case 6:
        _StockManager.alertaStockMinimo();
        break;
    case 0:
        cout << "\nVolviendo al menu principal...\n";
        break;
    default:
        cout << "Opcion invalida. Intente nuevamente." << endl;
    }
}
