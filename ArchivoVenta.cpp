#include <iostream>
#include <cstdio>
#include "ArchivoVenta.h"
#include "ArchivoMozo.h"
#include "ArchivoMesa.h"
#include "ArchivoCliente.h"
using namespace std;

ArchivoVenta::ArchivoVenta(const char* n)
{
    nombreArchivo = n;
}
bool ArchivoVenta::guardarVenta(Venta& reg)
{

    FILE* p=fopen(nombreArchivo, "ab");
    if( p== nullptr) return false;
    bool ok = fwrite(&reg, sizeof(Venta), 1, p);
    fclose(p);
    return ok;
}

bool ArchivoVenta::leerVenta(Venta& reg, int pos)
{
    FILE* p =fopen(nombreArchivo, "rb");
    if (p==nullptr) return false;
    fseek(p, pos * sizeof(Venta), SEEK_SET);
    bool ok = fread(&reg, sizeof(Venta), 1,p);
    fclose(p);
    return ok;
}

int ArchivoVenta::contarVentas()
{

    FILE* p = fopen(nombreArchivo, "rb");
    if (p==nullptr)return 0;
    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(Venta);
    fclose(p);
    return cant;
}
bool ArchivoVenta::modificarVenta(Venta &venta, int pos)
{
    FILE *p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Venta), SEEK_SET);
    bool ok = fwrite(&venta, sizeof(Venta), 1, p);
    fclose(p);
    return ok;
}

int ArchivoVenta::buscarVentaPorId(int id)
{
    Venta reg;
    int cant = contarVentas();
    for (int i = 0; i < cant; i++)
    {
        if (leerVenta(reg, i))
        {
            if (reg.getIdVenta() == id && reg.getEliminado() == false)
            {
                return i;
            }
        }
    }
    return -1;
}

int ArchivoVenta::generarIdVenta()
{
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return 1;  // Si el archivo no existe, empezamos en 1

    Venta reg;
    int ultimoId = 0;
    while (fread(&reg, sizeof(Venta), 1, p))
    {
        ultimoId = reg.getIdVenta();
    }
    fclose(p);
    return ultimoId + 1;  // El siguiente ID
}

void ArchivoVenta::listarVentas()
{
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL)
    {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    Venta venta;
    ArchivoMozo archivoMozo("Mozos.dat");
    Mozo mozo;

    while (fread(&venta, sizeof(Venta), 1, p) == 1)
    {
        mozo = archivoMozo.buscarMozoPorId(venta.getIdMozo());

        cout << "\nID Venta: " << venta.getIdVenta() << endl;
//        cout << "Fecha: " << venta.getFecha().dia << "/" << venta.getFecha().mes << "/" << venta.getFecha().anio << endl;
//        cout << "Hora: " << venta.getHora().hora << ":" << venta.getHora().minuto << endl;
        cout << "Mozo: " <<mozo.getIdMozo() <<" "<< mozo.getNombre() << endl;
        cout << "Metodo de pago: " << (venta.getMetodoPago() == 1 ? "Efectivo" : "Tarjeta") << endl;
        cout << "Estado: " << (venta.getEstado() == 1 ? "Activa" : "Inactiva") << endl;
        cout << "Total: $" << venta.getTotal() << endl;
        cout << "--------------------------" << endl;
    }

    fclose(p);
}

void ArchivoVenta::cargarVenta()
{
    Venta reg;
    ArchivoMozo archivoMozo("Mozos.dat");
    ArchivoMesa archivoMesa("Mesas.dat");
    ArchivoCliente archivoCliente("Clientes.dat");

    cout << "--- CARGAR NUEVA VENTA ---" << endl;


    int idVenta = generarIdVenta();
    reg.setIdVenta(idVenta);
    cout << "ID de venta asignado automaticamente: " << idVenta << endl;

    Fecha f;
    f.Cargar(); // Asumimos que ya tenés esta función en tu clase Fecha
    reg.setFecha(f);

    char hora[6];
    cout << "Ingrese hora (HHMM): ";
    cin >> hora;
    reg.setHora(hora);

    // === MOSTRAR MOZOS ===
    cout << "\n--- LISTA DE MOZOS ---" << endl;
    archivoMozo.listarMozos();
    int idMozo;
    cout << "Seleccione ID de mozo: ";
    cin >> idMozo;
    reg.setIdMozo(idMozo);

    // === MOSTRAR MESAS ===
    cout << "\n--- LISTA DE MESAS ---" << endl;
    archivoMesa.listarMesas();
    int idMesa;
    cout << "Seleccione ID de mesa: ";
    cin >> idMesa;
    reg.setIdMesa(idMesa);

    // === MOSTRAR CLIENTES ===
    cout << "\n--- LISTA DE CLIENTES ---" << endl;
    archivoCliente.listarClientes();
    int idCliente;
    cout << "Seleccione ID de cliente (0 si no registrado): ";
    cin >> idCliente;
    reg.setIdCliente(idCliente);

    // === OTROS DATOS ===
    int metodoPago, estado;
    float total;

    cout << "Ingrese metodo de pago (1=Efectivo, 2=Tarjeta, etc): ";
    cin >> metodoPago;
    reg.setMetodoPago(metodoPago);

    cout << "Ingrese estado (1=Activa, 2=Cerrada, etc): ";
    cin >> estado;
    reg.setEstado(estado);

    cout << "Ingrese total: ";
    cin >> total;
    reg.setTotal(total);

    reg.setEliminado(false);

    // === GUARDAR EN ARCHIVO ===
    if (guardarVenta(reg))
    {
        cout << "\nVenta guardada correctamente en Ventas.dat" << endl;
    }
    else
    {
        cout << "\nError al guardar la venta." << endl;
    }
}


/// agregado
bool ArchivoVenta::eliminarVenta(int id) {
    FILE* p = fopen(nombreArchivo, "rb+");
    if (!p) return false;

    Venta reg;
    int pos = 0;
    while (fread(&reg, sizeof(Venta), 1, p) == 1) {
        if (reg.getIdVenta() == id) {
            reg.setEliminado(true);
            fseek(p, pos * sizeof(Venta), SEEK_SET);
            fwrite(&reg, sizeof(Venta), 1, p);
            fclose(p);
            return true;
        }
        pos++;
    }

    fclose(p);
    return false;
}


/*
void ArchivoVenta::menuVentas()
{
    int opcion = 0;
    Venta venta;
    ArchivoVenta archivo("Ventas.dat");

    while (opcion != 5)
    {
        cout << "----- MENU VENTAS -----" << endl;
        cout << "1. Cargar venta" << endl;
        cout << "2. Listar todas las ventas" << endl;
        cout << "3. Buscar venta por ID" << endl;
        cout << "4. Modificar venta" << endl;
        cout << "5. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            cargarVenta();
            system("cls");

        }
        break;

        case 2:
        {   system("cls");
            listarVentas();
            break;

            case 3:
            {
                int id;
                cout << "Ingrese el ID de la venta a buscar: ";
                cin >> id;
                int pos = archivo.buscarVentaPorId(id);
                if (pos >= 0)
                {
                    archivo.leerVenta(venta, pos);
                    venta.mostrar();
                }
                else
                {
                    cout << "Venta no encontrada." << endl;
                }
            }
            break;

            case 4:
            {
                int id;
                cout << "Ingrese el ID de la venta a modificar: ";
                cin >> id;
                int pos = archivo.buscarVentaPorId(id);
                if (pos >= 0)
                {
                    archivo.leerVenta(venta, pos);
                    cout << "Venta actual:" << endl;
                    venta.mostrar();
                    cout << "Ingrese los nuevos datos:" << endl;
                    archivo.cargarVenta();
                    archivo.modificarVenta(venta, pos);
                    cout << "Venta modificada correctamente." << endl;
                }
                else
                {
                    cout << "Venta no encontrada." << endl;
                }
            }
            break;

            case 5:
                cout << "Volviendo al menu principal..." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
            }

            cout << endl;
        }
    }
}
*/
