#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>

using namespace std;


class Fecha {
private:
int dia, mes, anio;
public:
Fecha(int d = 0, int m = 0, int a = 0) {
dia = d; mes = m; anio = a;
}
void Cargar() {
cout<<"Dia: ";cin>>dia;
cout<<"Mes: ";cin>>mes;
cout<<"Anio: ";cin>>anio;
}
void Mostrar()  {
cout<<dia<<"/"<<mes<<"/"<< anio;
}
};
#endif // FECHA_H_INCLUDED
