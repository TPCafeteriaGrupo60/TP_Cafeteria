#ifndef MOZO_H
#define MOZO_H

#include "Fecha.h"

class Mozo {
private:
    int idMozo;
    char nombre[30];
    char apellido[30];
    Fecha fechaIngreso;
    int idTurno;
    bool eliminado;

public:
    // Constructores
    Mozo();
    Mozo(int id, const char* nom, const char* ape, int turno);

    // Getters y setters
    int getIdMozo() ;
    const char* getNombre() ;
    const char* getApellido() ;
    Fecha getFechaIngreso() ;
    int getIdTurno() ;
    bool getEliminado() ;

    void setEliminado(bool e);

    // Métodos
  //  void Cargar();
    void Mostrar() ;  //  el const indica que no modifica atributos
};

#endif
