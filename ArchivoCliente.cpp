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

int ArchivoCliente::buscarClientePorId(int id) {
    int cant = contarCliente();
    for (int i = 0; i < cant; i++) {
        Cliente reg = leerCliente(i);
        if (reg.getIdCliente() == id && !reg.getEliminado())
            return i;
    }
    return -1;
}

bool ArchivoCliente::modificarCliente(int pos, const Cliente& modificado) {
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Cliente), SEEK_SET);
    bool ok = fwrite(&modificado, sizeof(Cliente), 1, p);
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
