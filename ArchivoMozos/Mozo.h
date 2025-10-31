#ifndef MOZO_H_INCLUDED
#define MOZO_H_INCLUDED
class Mozo{

private:
    int _idMozo;
    char _nombre[30];
    char _apellido[30];
    int _edad;
    bool _activo;
    int _idTurno;

public:
    Mozo();
    Mozo(int id, const char* nombre, const char* apellido, int edad, int idTurno);

    ///gets
    int getIdMozo();
    const char* getNombre();
    const char* getApellido();
    int getEdad();
    bool getActivo();
    int getIdTurno();

    ///sets
    void setIdMozo(int id);
    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setEdad(int edad);
    void setActivo(bool activo);
    void setIdTurno(int idTurno);

    void mostrar();


};


#endif // MOZO_H_INCLUDED
