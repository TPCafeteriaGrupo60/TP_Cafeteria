#ifndef ClienteMANAGER_H_INCLUDED
#define ClienteMANAGER_H_INCLUDED

#include "ArchivoCliente.h"

class ClienteManager {
private:
    ArchivoCliente archivo;

public:
    ClienteManager(const char* nombreArchivo);

    bool agregarCliente();
    void listarClientes();
    bool modificarClientePorId();
    bool eliminarClientePorId();
};

#endif
