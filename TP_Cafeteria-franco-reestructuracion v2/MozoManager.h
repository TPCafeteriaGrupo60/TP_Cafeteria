#ifndef MozoMANAGER_H_INCLUDED
#define MozoMANAGER_H_INCLUDED

#include "ArchivoMozo.h"

class MozoManager {
private:
    ArchivoMozo archivo;

public:
    MozoManager(const char* nombreArchivo);

    bool agregarMozo();
    void listarMozos();
    bool modificarMozoPorId();
    bool eliminarMozoPorId();
};

#endif
