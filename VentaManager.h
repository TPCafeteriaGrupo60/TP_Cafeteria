#ifndef VENTAMANAGER_H_INCLUDED
#define VENTAMANAGER_H_INCLUDED

#include "ArchivoVenta.h"

class VentaManager {
private:
    ArchivoVenta archivo;

public:
    VentaManager(const char* nombreArchivo);
    bool agregarVenta();
    void listarVentas();
    bool modificarVentaPorId();
    bool eliminarVentaPorId();
    void menuVentas();
};

#endif // VENTAMANAGER_H_INCLUDED
