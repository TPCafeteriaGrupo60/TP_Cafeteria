#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <iostream>
#include <cstring>

#include "Fecha.h"

class Cliente {
private:
    int idCliente;
    char nombre[30];
    char apellido[30];
    char telefono[20];
    Fecha fechaAlta;
    bool eliminado;

public:
    Cliente();
    Cliente(int id, const char* nom, const char* ape, const char* tel, Fecha fAlta);

    int getIdCliente() ;
    const char* getNombre() ;
    const char* getApellido() ;
    const char* getTelefono() ;
    Fecha getFechaAlta() ;
    bool getEliminado() ;

    void setEliminado(bool e);

    void Cargar();
    void Mostrar() ;
};

#endif
