#ifndef ARCHIVOCLIENTE_H_INCLUDED
#define ARCHIVOCLIENTE_H_INCLUDED

#include "Cliente.h"
#include <cstdio>

class ArchivoCliente {
private:
    const char* nombreArchivo;

public:
    ArchivoCliente(const char* nombre) { nombreArchivo = nombre; }

    bool guardarCliente(const Cliente& reg);
    Cliente leerCliente(int pos);
    int contarCliente();
    int buscarClientePorId(int id);
    bool modificarCliente(int id, const Cliente& modificado);
    bool eliminarCliente(int id);
    void listarClientes();
    void MenuClientes();
};

#endif
