/*#include <iostream>
#include <cstdio>
#include "StockManager.h"

using namespace std;

StockManager::StockManager(const char* nombreArchivo)
: archivo(nombreArchivo) { }

bool StockManager::agregarStock()
{
    system("cls");
    cout << "AGREGAR PRODUCTO" << endl;
    cout << "===============" << endl;

    int id = archivo.generarIdStock();
    Stock producto;

    cout << "ID generado: " << id << endl;
    producto.setIdProducto(id);
    producto.Cargar();

    if (archivo.guardarStock(producto))
    {
        cout << "Producto agregado correctamente!" << endl;
        return true;
    }
    else
    {
        cout << "Error al agregar producto!" << endl;
        return false;
    }
}

void StockManager::listarStocks()
{
    system("cls");
    archivo.listarStocks();
}

bool StockManager::modificarStockPorId()
{
    system("cls");
    cout << "MODIFICAR PRODUCTO" << endl;
    cout << "=================" << endl;

    int id;
    cout << "ID del producto a modificar: ";
    cin >> id;

    int pos = archivo.buscarPosPorId(id);
    if (pos == -1)
    {
        cout << "Producto no encontrado!" << endl;
        system("pause");
        return false;
    }

    Stock producto = archivo.leerStock(pos);
    producto.Mostrar();

    char opcion;
    cout << "Desea modificar este producto? (s/n): ";
    cin >> opcion;

    if (opcion == 's' || opcion == 'S')
    {
        // CORRECCIÓN: Copiar el producto existente en lugar de crear uno nuevo
        Stock modificado = producto;  // Esto copia todos los datos del producto original

        // Ahora cargar solo los nuevos datos (sin el ID)
        modificado.Cargar();
        // El ID se mantiene automáticamente porque copiamos el producto original

        if (archivo.modificarStock(pos, modificado))
        {
            cout << "Producto modificado correctamente!" << endl;
            return true;
        }
        else
        {
            cout << "Error al modificar producto!" << endl;
            return false;
        }
    }
    return false;
}

bool StockManager::eliminarStockPorId()
{
    system("cls");
    cout << "ELIMINAR PRODUCTO" << endl;
    cout << "================" << endl;

    int id;
    cout << "ID del producto a eliminar: ";
    cin >> id;

    int pos = archivo.buscarPosPorId(id);
    if (pos == -1)
    {
        cout << "Producto no encontrado!" << endl;
        system("pause");
        return false;
    }

    Stock producto = archivo.leerStock(pos);
    producto.Mostrar();

    char opcion;
    cout << "Esta seguro de eliminar este producto? (s/n): ";
    cin >> opcion;

    if (opcion == 's' || opcion == 'S')
    {
        if (archivo.eliminarStock(id))
        {
            cout << "Producto eliminado correctamente!" << endl;
            return true;
        }
        else
        {
            cout << "Error al eliminar producto!" << endl;
            return false;
        }
    }
    return false;
}

void StockManager::consultarStockPorId()
{
    system("cls");
    int id;
    cout << "ID del producto: ";
    cin >> id;

    Stock producto = archivo.buscarStockPorId(id);
    if (producto.getIdProducto() == 0)
    {
        cout << "Producto no encontrado!" << endl;
        return;
    }

    cout << "STOCK DEL PRODUCTO:" << endl;
    cout << "Nombre: " << producto.getNombre() << endl;
    cout << "Stock Actual: " << producto.getStockActual() << endl;
    cout << "Stock Minimo: " << producto.getStockMinimo() << endl;

    if (producto.getStockActual() < producto.getStockMinimo())
    {
        cout << "ALERTA: Stock por debajo del minimo!" << endl;
    }
}

void StockManager::alertaStockMinimo()
{
    system("cls");
    archivo.alertaStockMinimo();
}

void StockManager::menuConsultas()
{
    int opcion;
    do
    {
        system("cls");
        cout << "CONSULTAS DE STOCK" << endl;
        cout << "==================" << endl;
        cout << "1 - CONSULTAR POR PRODUCTO (ID)" << endl;
        cout << "2 - CONSULTAR POR CATEGORIA" << endl;
        cout << "3 - CONSULTAR POR PRECIO" << endl;
        cout << "4 - CONSULTAR POR NIVEL DE STOCK" << endl;
        cout << "0 - VOLVER AL MENU STOCK" << endl;
        cout << "==================" << endl;
        cout << "OPCION: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            consultarStockPorId();
            system("pause");
            break;
        case 2:
            archivo.consultarPorCategoria();
            system("pause");
            break;
        case 3:
            archivo.consultarPorPrecio();
            system("pause");
            break;
        case 4:
            archivo.consultarPorNivelStock();
            system("pause");
            break;
        case 0:
            cout << "Volviendo al menu stock..." << endl;
            break;
        default:
            cout << "Opcion invalida!" << endl;
            system("pause");
            break;
        }
    }
    while (opcion != 0);
}

void StockManager::mostrarMenuStock()
{
    system("cls");
    cout << "STOCK" << endl;
    cout << "---" << endl;
    cout << "1 - AGREGAR PRODUCTO" << endl;
    cout << "2 - MODIFICAR PRODUCTO" << endl;
    cout << "3 - ELIMINAR PRODUCTO" << endl;
    cout << "4 - LISTAR PRODUCTOS" << endl;
    cout << "5 - CONSULTAS DE STOCK" << endl;
    cout << "6 - ALERTA DE STOCK MINIMO" << endl;
    cout << "---" << endl;
    cout << "0 - VOLVER" << endl;
    cout << "---" << endl;
    cout << "OPCION: ";
}

void StockManager::menuStock()
{
    int opcion;
    do
    {
        mostrarMenuStock();
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            agregarStock();
            system("pause");
            break;
        case 2:
            modificarStockPorId();
            system("pause");
            break;
        case 3:
            eliminarStockPorId();
            system("pause");
            break;
        case 4:
            listarStocks();
            system("pause");
            break;
        case 5:
            menuConsultas();
            break;
        case 6:
            alertaStockMinimo();
            system("pause");
            break;
        case 0:
            cout << "Volviendo al menu principal..." << endl;
            break;
        default:
            cout << "Opcion invalida!" << endl;
            system("pause");
            break;
        }
    }
    while (opcion != 0);
}

*/



#include <iostream>
#include "StockManager.h"

using namespace std;

StockManager::StockManager(const char* nombreArchivo)
    : archivo(nombreArchivo) { }

bool StockManager::agregarStock()
{
    cout << "--- Agregar nuevo Producto ---\n";

    int id = archivo.generarIdStock();
    Stock s;
    s.setIdProducto(id);
    s.Cargar();

    if (archivo.guardarStock(s))
    {
        cout << "Producto agregado correctamente!\n";
        return true;
    }
    else
    {
        cout << "Error al agregar producto!\n";
        return false;
    }
}

bool StockManager::modificarStockPorId()
{
    int id;
    cout << "ID del producto a modificar: ";
    cin >> id;

    int pos = archivo.buscarPosPorId(id);
    if (pos == -1)
    {
        cout << "Producto no encontrado!\n";
        return false;
    }

    Stock existente = archivo.leerStock(pos);
    existente.Mostrar();

    char opcion;
    cout << "Desea modificar este producto? (s/n): ";
    cin >> opcion;

    if (opcion == 's' || opcion == 'S')
    {
        Stock modificado;
        modificado.setIdProducto(id);
        modificado.Cargar();

        if (archivo.modificarStock(id, modificado))
        {
            cout << "Producto modificado correctamente!\n";
            return true;
        }
        else
        {
            cout << "Error al modificar producto!\n";
            return false;
        }
    }
    return false;
}

bool StockManager::eliminarStockPorId()
{
    int id;
    cout << "ID del producto a eliminar: ";
    cin >> id;

    int pos = archivo.buscarPosPorId(id);
    if (pos == -1)
    {
        cout << "Producto no encontrado!\n";
        return false;
    }

    Stock existente = archivo.leerStock(pos);
    existente.Mostrar();

    char opcion;
    cout << "Esta seguro de eliminar este producto? (s/n): ";
    cin >> opcion;

    if (opcion == 's' || opcion == 'S')
    {
        if (archivo.eliminarStock(id))
        {
            cout << "Producto eliminado correctamente!\n";
            return true;
        }
        else
        {
            cout << "Error al eliminar producto!\n";
            return false;
        }
    }
    return false;
}

void StockManager::listarStocks()
{
    cout << "\n--- Listado de Productos ---\n";
    archivo.listarStocks();
}

void StockManager::alertaStockMinimo()
{
    cout << "\n--- Alertas de Stock Minimo ---\n";
    archivo.alertaStockMinimo();
}

void StockManager::consultarStockPorId()
{
    int id;
    cout << "ID del producto: ";
    cin >> id;
    archivo.consultarStock(id);
}

void StockManager::menuConsultas()
{
    int opcion;
    do
    {
        system("cls");
        cout << "CONSULTAS DE STOCK" << endl;
        cout << "==================" << endl;
        cout << "1 - CONSULTAR POR PRODUCTO (ID)" << endl;
        cout << "2 - CONSULTAR POR CATEGORIA" << endl;
        cout << "3 - CONSULTAR POR PRECIO" << endl;
        cout << "4 - CONSULTAR POR NIVEL DE STOCK" << endl;
        cout << "0 - VOLVER AL MENU STOCK" << endl;
        cout << "==================" << endl;
        cout << "OPCION: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            consultarStockPorId();
            system("pause");
            break;
        case 2:
            system("cls");
            archivo.consultarPorCategoria();
            system("pause");
            break;
        case 3:
            system("cls");
            archivo.consultarPorPrecio();
            system("pause");
            break;
        case 4:
            system("cls");
            archivo.consultarPorNivelStock();
            system("pause");
            break;
        case 0:
            cout << "Volviendo al menu stock..." << endl;
            break;
        default:
            cout << "Opcion invalida!" << endl;
            system("pause");
            break;
        }
    } while (opcion != 0);
}
