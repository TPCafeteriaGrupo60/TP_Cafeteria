#include <iostream>
#include <cstring>
#include "Turno.h"
using namespace std;

Turno::Turno() {
    idTurno = 0;
    strcpy(nombre, "");
    strcpy(horaInicio, "");
    strcpy(horaFin, "");
    eliminado = false;
}

Turno::Turno(int id, const char* nom, const char* inicio, const char* fin) {
    idTurno = id;
    strcpy(nombre, nom);
    strcpy(horaInicio, inicio);
    strcpy(horaFin, fin);
    eliminado = false;
}

int Turno::getIdTurno() const { return idTurno; }
const char* Turno::getNombre() const { return nombre; }
const char* Turno::getHoraInicio() const { return horaInicio; }
const char* Turno::getHoraFin() const { return horaFin; }
bool Turno::getEliminado() const { return eliminado; }

void Turno::setEliminado(bool e) { eliminado = e; }

void Turno::Cargar() {
    cout << "ID del turno: ";
    cin >> idTurno;
    cin.ignore();

    cout << "Nombre del turno: ";
    cin.getline(nombre, 20);

    cout << "Hora de inicio (HH:MM): ";
    cin.getline(horaInicio, 6);

    cout << "Hora de fin (HH:MM): ";
    cin.getline(horaFin, 6);

    eliminado = false;
}

void Turno::Mostrar() const {
    cout << "ID Turno: " << idTurno << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Hora inicio: " << horaInicio << endl;
    cout << "Hora fin: " << horaFin << endl;
    cout << "Eliminado: " << (eliminado ? "S " : "No") << endl;
}
