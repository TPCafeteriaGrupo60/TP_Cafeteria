#include "Venta.h"

Venta::Venta(){

        idVenta = 0;
        idMozo = 0;
        idMesa = 0;
        idCliente = 0;
        metodoPago = 0;
        estado = 0;
        total = 0;
        eliminado = false;
        strcpy(hora, "");

}

///getts
   int Venta::getIdVenta() { return idVenta; }
    Fecha Venta::getFecha() { return fecha; }
    const char* Venta::getHora() { return hora; }
    int Venta::getIdMozo() { return idMozo; }
    int Venta::getIdMesa() { return idMesa; }
    int Venta::getIdCliente() { return idCliente; }
    int Venta::getMetodoPago() { return metodoPago; }
    int Venta::getEstado() { return estado; }
    float Venta::getTotal() { return total; }
    bool Venta::getEliminado() { return eliminado; }

    ///setts
    void Venta::setIdVenta(int v){ idVenta = v;}
    void Venta::setFecha(Fecha f){ fecha = f;}
    void Venta::setHora(const char* h){strcpy(hora, h) ;}
    void Venta::setIdMozo(int m) { idMozo = m; }
    void Venta::setIdMesa(int m) { idMesa = m; }
     void Venta::setIdCliente(int c) { idCliente = c; }
     void Venta::setMetodoPago(int p) { metodoPago = p; }
     void Venta::setEstado(int e) { estado = e; }
     void Venta::setTotal(float t) { total = t; }
    void Venta::setEliminado(bool e) { eliminado = e; }


 void Venta::cargar() {
    cout << "ID de venta: ";
    cin >> idVenta;
    cout << "Fecha:" << endl;
    fecha.Cargar();
    cout << "Hora (HH:MM): ";
    cin >> hora;
     cout << "Ingrese ID del mozo: ";
    cin >> idMozo;

    cout << "Ingrese ID de la mesa: ";
    cin >> idMesa;

    cout << "Ingrese ID del cliente: ";
    cin >> idCliente;

    cout << "Metodo de Pago: " << (metodoPago == 1 ? "Efectivo" : "Tarjeta") << endl;
    cout << "Estado: " << (estado == 1 ? "Activa" : "Inactiva") << endl;

    cout << "Ingrese total de la venta: $";
    cin >> total;
    eliminado = false;
}


void Venta::mostrar() {
    if (!eliminado) {
        cout << "-------------------------" << endl;
        cout << "ID Venta: " << idVenta << endl;
        cout << "Fecha: ";
        fecha.Mostrar();
        cout << "Hora: " << hora << endl;
        cout << "ID Mozo: " << idMozo << endl;
        cout << "ID Mesa: " << idMesa << endl;
        cout << "ID Cliente: " << idCliente << endl;
        cout << "Metodo de Pago: " << metodoPago << endl;
        cout << "Estado: " << estado << endl;
        cout << "Total: $" << total << endl;
        cout << "-------------------------" << endl;
    }
}
