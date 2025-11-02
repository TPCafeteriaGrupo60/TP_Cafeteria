#include <iostream>
#include <cstdio>
#include "ArchivoStock.h"

using namespace std;

bool ArchivoStock::guardarStock(const Stock& reg)
{
    FILE* p = fopen(nombreArchivo, "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(Stock), 1, p);
    fclose(p);
    return ok;
}

Stock ArchivoStock::leerStock(int pos)
{
    Stock reg;
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return reg;
    fseek(p, pos * sizeof(Stock), SEEK_SET);
    fread(&reg, sizeof(Stock), 1, p);
    fclose(p);
    return reg;
}

int ArchivoStock::contarStock()
{
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Stock);
}

Stock ArchivoStock::buscarStockPorId(int id)
{
    int cant = contarStock();
    for (int i = 0; i < cant; i++)
    {
        Stock reg = leerStock(i);
        if (reg.getIdProducto() == id && !reg.getEliminado())
            return reg;
    }
    return Stock();
}

int ArchivoStock::buscarPosPorId(int id)
{
    int cant = contarStock();
    for (int i = 0; i < cant; i++)
    {
        Stock reg = leerStock(i);
        if (reg.getIdProducto() == id && !reg.getEliminado())
            return i;
    }
    return -1;
}

bool ArchivoStock::modificarStock(int pos, const Stock& modificado)
{
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Stock), SEEK_SET);
    bool ok = fwrite(&modificado, sizeof(Stock), 1, p);
    fclose(p);
    return ok;
}

bool ArchivoStock::eliminarStock(int id)
{
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) return false;

    Stock reg;
    int pos = 0;
    while (fread(&reg, sizeof(Stock), 1, p) == 1)
    {
        if (reg.getIdProducto() == id)
        {
            reg.setEliminado(true);
            fseek(p, pos * sizeof(Stock), SEEK_SET);
            fwrite(&reg, sizeof(Stock), 1, p);
            fclose(p);
            return true;
        }
        pos++;
    }

    fclose(p);
    return false;
}

void ArchivoStock::listarStocks()
{
    int cant = contarStock();
    cout << "LISTADO DE PRODUCTOS" << endl;
    cout << "==================================================" << endl;

    for (int i = 0; i < cant; i++)
    {
        Stock reg = leerStock(i);
        if (!reg.getEliminado())
        {
            reg.Mostrar();
        }
    }
}

int ArchivoStock::generarIdStock()
{
    int total = contarStock();
    if (total == 0)
        return 1;

    Stock ultimo = leerStock(total - 1);
    return ultimo.getIdProducto() + 1;
}

void ArchivoStock::alertaStockMinimo()
{
    int total = contarStock();
    bool hayAlertas = false;

    cout << "ALERTAS DE STOCK MINIMO" << endl;
    cout << "==================================================" << endl;

    for (int i = 0; i < total; i++)
    {
        Stock producto = leerStock(i);
        if (!producto.getEliminado() && producto.getStockActual() < producto.getStockMinimo())
        {
            cout << "ALERTA: " << producto.getNombre() << " - Stock: " << producto.getStockActual()
                 << " (Minimo: " << producto.getStockMinimo() << ")" << endl;
            hayAlertas = true;
        }
    }

    if (!hayAlertas)
    {
        cout << "No hay productos con stock por debajo del minimo." << endl;
    }
}

void ArchivoStock::consultarPorCategoria()
{
    system("cls");
    cout << "CONSULTA POR CATEGORIA" << endl;
    cout << "=====================" << endl;

    char categoria[20];
    cout << "Ingrese la categoria a buscar: ";
    cin.ignore();
    cin.getline(categoria, 20);

    int total = contarStock();
    bool encontrado = false;

    cout << "PRODUCTOS DE LA CATEGORIA: " << categoria << endl;
    cout << "==================================================" << endl;

    for (int i = 0; i < total; i++)
    {
        Stock producto = leerStock(i);
        if (!producto.getEliminado() && strcmp(producto.getCategoria(), categoria) == 0)
        {
            producto.Mostrar();
            encontrado = true;
        }
    }

    if (!encontrado)
    {
        cout << "No se encontraron productos en esta categoria." << endl;
    }
}

void ArchivoStock::consultarPorPrecio()
{
    system("cls");
    cout << "CONSULTA POR RANGO DE PRECIO" << endl;
    cout << "============================" << endl;

    float precioMin, precioMax;
    cout << "Precio minimo: $";
    cin >> precioMin;
    cout << "Precio maximo: $";
    cin >> precioMax;

    if (precioMin > precioMax)
    {
        cout << "Error: El precio minimo no puede ser mayor al maximo." << endl;
        system("pause");
        return;
    }

    int total = contarStock();
    bool encontrado = false;

    cout << "PRODUCTOS ENTRE $" << precioMin << " Y $" << precioMax << endl;
    cout << "==================================================" << endl;

    for (int i = 0; i < total; i++)
    {
        Stock producto = leerStock(i);
        if (!producto.getEliminado() &&
                producto.getPrecioVenta() >= precioMin &&
                producto.getPrecioVenta() <= precioMax)
        {
            producto.Mostrar();
            encontrado = true;
        }
    }

    if (!encontrado)
    {
        cout << "No se encontraron productos en este rango de precio." << endl;
    }
}

void ArchivoStock::consultarPorNivelStock()
{
    system("cls");
    cout << "CONSULTA POR NIVEL DE STOCK" << endl;
    cout << "===========================" << endl;
    cout << "1 - STOCK MINIMO (igual al stock minimo)" << endl;
    cout << "2 - STOCK BAJO (por debajo del stock minimo)" << endl;
    cout << "3 - STOCK NORMAL (por encima del stock minimo)" << endl;
    cout << "===========================" << endl;

    int opcion;
    cout << "Seleccione nivel: ";
    cin >> opcion;

    int total = contarStock();
    bool encontrado = false;

    switch (opcion)
    {
    case 1: // Stock mínimo
        cout << "PRODUCTOS CON STOCK MINIMO" << endl;
        cout << "==================================================" << endl;
        for (int i = 0; i < total; i++)
        {
            Stock producto = leerStock(i);
            if (!producto.getEliminado() && producto.getStockActual() == producto.getStockMinimo())
            {
                producto.Mostrar();
                encontrado = true;
            }
        }
        break;

    case 2: // Stock bajo
        cout << "PRODUCTOS CON STOCK BAJO" << endl;
        cout << "==================================================" << endl;
        for (int i = 0; i < total; i++)
        {
            Stock producto = leerStock(i);
            if (!producto.getEliminado() && producto.getStockActual() < producto.getStockMinimo())
            {
                producto.Mostrar();
                encontrado = true;
            }
        }
        break;

    case 3: // Stock normal
        cout << "PRODUCTOS CON STOCK NORMAL" << endl;
        cout << "==================================================" << endl;
        for (int i = 0; i < total; i++)
        {
            Stock producto = leerStock(i);
            if (!producto.getEliminado() && producto.getStockActual() > producto.getStockMinimo())
            {
                producto.Mostrar();
                encontrado = true;
            }
        }
        break;

    default:
        cout << "Opcion invalida!" << endl;
        system("pause");
        return;
    }

    if (!encontrado)
    {
        cout << "No se encontraron productos con este nivel de stock." << endl;
    }
}
