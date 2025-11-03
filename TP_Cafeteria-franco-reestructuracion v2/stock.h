#ifndef STOCK_H
#define STOCK_H

class Stock
{
private:
    int _idProducto;
    char _nombre[40];
    char _categoria[20];
    char _unidadMedida[10];
    float _precioCosto;
    float _precioVenta;
    int _stockActual;
    int _stockMinimo;
    bool _eliminado;

public:
    Stock(); //construcxtor
    Stock(int id, const char* nombre, const char* categoria, const char* unidadMedida,
          float precioCosto, float precioVenta, int stockActual, int stockMinimo);

    // Getters
    int getIdProducto();
    const char* getNombre();
    const char* getCategoria();
    const char* getUnidadMedida();
    float getPrecioCosto();
    float getPrecioVenta();
    int getStockActual();
    int getStockMinimo();
    bool getEliminado();

    // Setters
    void setIdProducto(int id);
    void setNombre(const char* nombre);
    void setCategoria(const char* categoria);
    void setUnidadMedida(const char* unidadMedida);
    void setPrecioCosto(float precio);
    void setPrecioVenta(float precio);
    void setStockActual(int stock);
    void setStockMinimo(int stockMinimo);
    void setEliminado(bool eliminado);

    void mostrar();
};

// Funciones para manejar el archivo
bool guardarStock(Stock producto);
bool guardarStock(Stock producto, int posicion);
int buscarStock(int idProducto);
Stock leerStock(int posicion);
int cantidadRegistrosStock();
bool eliminarStock(int posicion);

// Funciones principales
void listarStocks();
void consultarStock(int idProducto);
void alertaStockMinimo();
int generarIdStock();

// Funciones del menú
void agregarProducto();
void modificarProducto();
void eliminarProducto();
void mostrarMenuStock();
void menuStock();

// Funciones de consultas
void consultarPorCategoria();
void consultarPorPrecio();
void consultarPorNivelStock();
void menuConsultas();

/////Listar productos eliminados
/////////Listar productos en seccion de modificacion

#endif
