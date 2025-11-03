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
    } while (opcion != 0);
}

void StockMenu::mostrarOpciones()
{
    cout << "---- Menu Stock ----" << endl;
    cout << "1 - Agregar Producto" << endl;
    cout << "2 - Modificar Producto" << endl;
    cout << "3 - Eliminar Producto" << endl;
    cout << "4 - Llistar Productos" << endl;
    cout << "5 - Consultas de Stock" << endl;
    cout << "6 - Alerta de Stock Minimo" << endl;
    cout << "0 - Volver" << endl;
}

int StockMenu::seleccionOpcion()
{
    int opcion;
    mostrarOpciones();
    cout << "------------------------" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    while (opcion < 0 || opcion > _cantidadOpciones)
    {
        cout << "\nOpcion incorrecta...\n" << endl;
        cout << "Seleccione una opcion: ";
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
