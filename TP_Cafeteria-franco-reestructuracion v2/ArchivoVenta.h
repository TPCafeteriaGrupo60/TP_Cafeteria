#ifndef ARCHIVOVENTA_H_INCLUDED
#define ARCHIVOVENTA_H_INCLUDED

#include "Venta.h"

class ArchivoVenta{

private:
    const char* nombreArchivo;

public:
    ArchivoVenta(const char* n ="Ventas.dat");
    bool guardarVenta(Venta& reg);
    bool leerVenta(Venta&, int pos);
    int contarVentas();
    int buscarVentaPorId(int id);
    void listarVentas();
    void cargarVenta();
    void menuVentas();
    bool modificarVenta(Venta &venta, int pos);
    int generarIdVenta();

} ;


#endif // ARCHIVOVENTA_H_INCLUDED
