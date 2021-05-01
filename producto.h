#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "cola.h"

#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

/* Aplicación de una estructura de datos tipo cola. Se define la clase
Producto y una cola de objetos tipo Producto. Considerando que se
quieren vender los productos de acuerdo al orden en el que fueron
comprados, se usó una cola para almacenarlos. La cola se actualiza a
medida que se compran o se venden productos. */

/* Definición de la clase Producto. */
class Producto{
public:
    Producto();
    Producto(int, char[], double);
    double RegresaPrecio();
    friend istream &operator>>(istream &, Producto &);//Sobrecarga del operador de insercion
    friend ostream &operator<<(ostream &, Producto &);//Sobrecarga del operador de extraccion

    void respaldar_productos(Producto [], int, int);
    int regresarClave();
    
private:
    int Clave;
    char NomProd[15];
    double Precio;
};

#endif //PRODUCTO_H