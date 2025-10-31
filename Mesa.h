#ifndef MESA_H_INCLUDED
#define MESA_H_INCLUDED

#include <iostream>
#include <cstring>

class Mesa {
private:
    int idMesa;
    int capacidad;
    char ubicacion[30];
    int estado;    // 0: libre, 1: ocupada, 2: reservada
    bool eliminado;

public:
    // Constructores
    Mesa();
    Mesa(int id, int cap, const char* ubi, int est);

    // Getters y setters
    int getIdMesa() const;
    int getCapacidad() const;
    const char* getUbicacion() const;
    int getEstado() const;
    bool getEliminado() const;

    void setEliminado(bool e);
    void setEstado(int e);

    // Métodos
    void Cargar();
    void Mostrar() const;
};


#endif
