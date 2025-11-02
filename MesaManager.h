#ifndef MesaMANAGER_H_INCLUDED
#define MesaMANAGER_H_INCLUDED

#include "ArchivoMesa.h"

class MesaManager {
private:
    ArchivoMesa archivo;

public:
    MesaManager(const char* nombreArchivo);

    bool agregarMesa();
    void listarMesas();
    bool modificarMesaPorId();
    bool eliminarMesaPorId();
};

#endif
