#ifndef FUNCIONESMOZO_H_INCLUDED
#define FUNCIONESMOZO_H_INCLUDED
#include "Mozo.h"
 ///prototipos para funciones.

bool guardarMozo(Mozo mozo);              ///agregar nuevo registro.
bool editarMozo(Mozo mozo, int posicion); ///para modificar existente.
int buscarMozo(int idMozo);
Mozo leerMozo(int posicion);
int cantidadRegistrosMozos();
bool eliminarMozo(int posicion);
void listarMozo();
int generarIdMozo();
void agregarMozo();
void MostrarMenuMozos();

#endif // FUNCIONESMOZO_H_INCLUDED
