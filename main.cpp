#include <iostream>

///#include "ArchivoCliente.h"
#include "ClienteMenu.h"

///#include "ArchivoMenu.h"
#include "MenuMenu.h"

///#include "ArchivoMesa.h"
#include "MesaMenu.h"

///#include "ArchivoMozo.h"
#include "MozoMenu.h"

///#include "ArchivoTurno.h"
#include "TurnoMenu.h"

#include "StockManager.h"
#include "ArchivoVenta.h"

using namespace std;

int main()
{
    ///ArchivoMenu menuMenus("Menus.dat");
    MenuMenu menuMenus("Menus.dat");

    ///ArchivoCliente menuClientes("Clientes.dat");
    ClienteMenu menuClientes("Clientes.dat");

    ///ArchivoMesa menuMesas("Mesas.dat");
    MesaMenu menuMesas("Mesas.dat");

    ///ArchivoMozo menuMozos("Mozos.dat");
    MozoMenu menuMozos("Mozos.dat");

    ///ArchivoTurno menuTurnos("Turnos.dat");
    TurnoMenu menuTurnos("Turnos.dat");

    VentaManager ventaManager("Ventas.dat");

    // Crear el manager de Stock - CORREGIDO
    StockManager stockManager("Stock.dat");  // Nombre del archivo para stock

    int opcion;
    do {
        system("cls");
        cout<< "---- Menu Principal ----" <<endl;
        cout<< "1. Mozos"<<endl;
        cout<< "2. Stock"<<endl;
        cout<< "3. Mesas"<<endl;
        cout<< "4. Ventas"<<endl;
        cout<< "5. Clientes"<<endl;
        cout<< "6. Menus a la Venta"<<endl;
        cout<< "7. Turnos de Atencion"<<endl;
        cout<< "8. Salir"<<endl;  // Agregué la opción salir
        cout<< "------------------------" <<endl;
        cout<<"Elegir Opcion: ";
        cin>>opcion;

        switch(opcion)
        {
            case 1:
                system("cls");
                menuMozos.mostrarMenu();
                break;
            case 2:
                system("cls");
                stockManager.menuStock();  // CORREGIDO: usar el método de StockManager
                break;
            case 3:
                system("cls");
                menuMesas.mostrarMenu();
                break;
            case 4:
                system("cls");
                ventaManager.menuVentas();
                break;
            case 5:
                system("cls");
                menuClientes.mostrarMenu();
                break;
            case 6:
                system("cls");
                menuMenus.mostrarMenu();
                break;
            case 7:
                system("cls");
                menuTurnos.mostrar();
                break;
            case 8:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida!" << endl;
                system("pause");
        }

    } while(opcion != 8);

    return 0;
}
