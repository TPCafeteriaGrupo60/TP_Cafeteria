#include <iostream>
#include <cstdio>
#include "ArchivoCliente.h"
using namespace std;

bool ArchivoCliente::guardarCliente(const Cliente& reg)
{
    FILE* p = fopen(nombreArchivo, "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;
}

Cliente ArchivoCliente::leerCliente(int pos)
{
    Cliente reg;
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return reg;
    fseek(p, pos * sizeof(Cliente), SEEK_SET);
    fread(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return reg;
}

int ArchivoCliente::contarCliente()
{
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Cliente);
}

int ArchivoCliente::buscarClientePorId(int id)
{
    Cliente reg;
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return -1;
    int pos = 0;
    while (fread(&reg, sizeof(Cliente), 1, p))
    {
        if (reg.getIdCliente() == id && !reg.getEliminado())
        {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

bool ArchivoCliente::modificarCliente(int pos, const Cliente& reg)
{
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Cliente), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;
}

bool ArchivoCliente::eliminarCliente(int id)
{
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) return false;

    Cliente reg;
    int pos = 0;
    while (fread(&reg, sizeof(Cliente), 1, p) == 1)
    {
        if (reg.getIdCliente() == id)
        {
            reg.setEliminado(true);
            fseek(p, pos * sizeof(Cliente), SEEK_SET);
            fwrite(&reg, sizeof(Cliente), 1, p);
            fclose(p);
            return true;
        }
        pos++;
    }

    fclose(p);
    return false;
}

void ArchivoCliente::listarClientes()
{
    int cant = contarCliente();
    for (int i = 0; i < cant; i++)
    {
        Cliente reg = leerCliente(i);
        if (!reg.getEliminado())
        {
            reg.Mostrar();
            cout << "---------------------" << endl;
        }
    }
}

void ArchivoCliente::MenuClientes()
{
    ArchivoCliente archivo("Clientes.dat");
    int opcion;

    do
    {
        cout << "--- MENU CLIENTES ---" << endl;
        cout << "1 - Agregar cliente" << endl;
        cout << "2 - Listar clientes" << endl;
        cout << "3 - Modificar cliente" << endl;
        cout << "4 - Eliminar cliente" << endl;
        cout << "5 - Salir" << endl;
        cout << "---------------------" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            Cliente c;
            cout << "Ingrese datos del cliente:" << endl;
            c.Cargar();
            if (archivo.guardarCliente(c))
                cout << "Cliente agregado con exito." << endl;
            else
                cout << "Error al guardar el cliente." << endl;
            break;
        }
        case 2:
            cout << "Lista de Clientes:" << endl;
            archivo.listarClientes();
            break;
        case 3:
        {
            int idModificar;
            cout << "Ingrese el ID del cliente a modificar: ";
            cin >> idModificar;

            int pos = archivo.buscarClientePorId(idModificar);
            if (pos == -1)
            {
                cout << "No se encontro cliente con ese ID." << endl;
                break;
            }

            Cliente modificado;
            cout << "Ingrese nuevos datos del cliente:" << endl;
            modificado.Cargar();

            if (archivo.modificarCliente(pos, modificado))
                cout << "Cliente modificado con exito." << endl;
            else
                cout << "Error al modificar el cliente." << endl;
            break;
        }
        case 4:
        {
            int idEliminar;
            cout << "Ingrese el ID del cliente a eliminar: ";
            cin >> idEliminar;

            if (archivo.eliminarCliente(idEliminar))
                cout << "Cliente eliminado con exito." << endl;
            else
                cout << "No se encontro el cliente con ese ID." << endl;
            break;
        }
        case 5:
            cout << "Volviendo al menu principal..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }

    }
    while (opcion != 5);
}
