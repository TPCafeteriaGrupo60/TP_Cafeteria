#include <iostream>
#include <cstring>
#include "Mesa.h"
using namespace std;

Mesa::Mesa() {
    idMesa = 0;
    capacidad = 0;
    strcpy(ubicacion, "");
    estado = 0;
    eliminado = false;
}

Mesa::Mesa(int id, int cap, const char* ubi, int est) {
    idMesa = id;
    capacidad = cap;
    strcpy(ubicacion, ubi);
    estado = est;
    eliminado = false;
}

int Mesa::getIdMesa() const { return idMesa; }
int Mesa::getCapacidad() const { return capacidad; }
const char* Mesa::getUbicacion() const { return ubicacion; }
int Mesa::getEstado() const { return estado; }
bool Mesa::getEliminado() const { return eliminado; }

void Mesa::setEliminado(bool e) { eliminado = e; }
void Mesa::setEstado(int e) { estado = e; }

void Mesa::Cargar() {
    cout << "ID Mesa: ";
    cin >> idMesa;
    cout << "Capacidad: ";
    cin >> capacidad;
    cout << "Ubicacion: ";
    cin.ignore();
    cin.getline(ubicacion, 30);
    cout << "Estado (0: Libre, 1: Ocupada, 2: Reservada): ";
    cin >> estado;
    eliminado = false;
}

void Mesa::Mostrar() const {
    cout << "ID Mesa: " << idMesa << endl;
    cout << "Capacidad: " << capacidad << endl;
    cout << "Ubicacion: " << ubicacion << endl;
    cout << "Estado: ";
    switch (estado) {
        case 0: cout << "Libre"; break;
        case 1: cout << "Ocupada"; break;
        case 2: cout << "Reservada"; break;
        default: cout << "Desconocido";
    }
    cout << endl;
    cout << "Eliminado: " << (eliminado ? "Si" : "No") << endl;
    cout << "-----------------------------" << endl;
}

