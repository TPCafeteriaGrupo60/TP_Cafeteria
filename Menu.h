#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

class Menu {
private:
    int idMenu;
    int idProducto;
    char nombre[40];
    char descripcion[120];
    float precioVenta;
    char categoria[20];
    bool activo;
    bool eliminado;

public:
    Menu();
    Menu(int idM, int idProd, const char* nom, const char* desc, float precio, const char* cat, bool act = true);

    int getIdMenu() const;
    int getIdProducto() const;
    const char* getNombre() const;
    const char* getDescripcion() const;
    float getPrecioVenta() const;
    const char* getCategoria() const;
    bool getActivo() const;
    bool getEliminado() const;

    void setIdMenu(int id);
    void setIdProducto(int id);
    void setNombre(const char* n);
    void setDescripcion(const char* d);
    void setPrecioVenta(float p);
    void setCategoria(const char* c);
    void setActivo(bool a);
    void setEliminado(bool e);

    void Cargar();
    void Mostrar() const;
};

#endif
