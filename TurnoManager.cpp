#include <iostream>
#include <cstdio>
#include "TurnoManager.h"

using namespace std;


TurnoManager::TurnoManager(const char* nombreArchivo) : archivo(nombreArchivo) { }

bool TurnoManager::agregarTurno(const Turno& t) {
    return archivo.guardarTurno(t);
}

void TurnoManager::listarTurnos() {
    archivo.listarTurnos();
}

bool TurnoManager::modificarTurnoPorId(int id, const Turno& t) {
    int pos = archivo.buscarPosPorId(id);
    if(pos == -1) return false;
    return archivo.modificarTurno(pos, t);
}

bool TurnoManager::eliminarTurnoPorId(int id) {
    return archivo.eliminarTurno(id);
}
