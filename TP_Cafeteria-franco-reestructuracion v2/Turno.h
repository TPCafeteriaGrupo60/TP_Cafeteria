#ifndef TURNO_H_INCLUDED
#define TURNO_H_INCLUDED


class Turno {
private:
    int idTurno;
    char nombre[20];
    char horaInicio[6];
    char horaFin[6];
    bool eliminado;

public:
    Turno();
    Turno(int id, const char* nom, const char* inicio, const char* fin);

    int getIdTurno() const;
    const char* getNombre() const;
    const char* getHoraInicio() const;
    const char* getHoraFin() const;
    bool getEliminado() const;
    void setEliminado(bool e);

    void Cargar();
    void Mostrar() const;
};



#endif
