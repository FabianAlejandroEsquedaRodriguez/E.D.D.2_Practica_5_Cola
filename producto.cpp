#include "producto.h"

/* Declaración del método constructor por omisión. */
Producto::Producto(){

}
/* Declaración del método constructor con parámetros. */
Producto::Producto(int Cla, char NomP[], double Pre){
    Clave= Cla;
    strcpy(NomProd, NomP);
    Precio= Pre;
}

/* Método que permite, a usuarios externos a la clase, conocer el valor
del atributo privado Precio. */
double Producto::RegresaPrecio(){
    return Precio;
}

/* Sobrecarga del operador >>. De esta forma se permite leer objetos de
tipo Producto de manera directa . */
istream &operator>>(istream &Lee, Producto &ObjProd){
    cout<<"\n\nIngrese clave del producto: ";
    Lee>>ObjProd.Clave;  
    cout<<"\nIngrese nombre del producto: ";
    Lee>>ObjProd.NomProd; 
    cout<<"\nIngrese precio: $";
    Lee>>ObjProd.Precio;

    return Lee;
}

/* Sobrecarga del operador <<. De esta forma se permite imprimir objetos
de tipo Producto de manera directa . */
ostream &operator<< (ostream &Escribe, Producto &ObjProd){
    Escribe<<"\n\n\t<-> DATOS DEL PRODUCTO <->\n";
    Escribe<<"\n\t\tClave: "<<ObjProd.Clave;
    Escribe<<"\n\t\tNombre: "<<ObjProd.NomProd;
    Escribe<<"\n\t\tPrecio: $"<<ObjProd.Precio;

    return Escribe;
}

int Producto::regresarClave(){
    return Clave;
}


void Producto::respaldar_productos(Producto prod[], int contP, int i){
    int cont;

    fstream archivoProductos("productos.dat", ios::out | ios::binary);

    if(!archivoProductos){
        cerr<<"\n\n\t\t\tNO SE PUDO ABRIR EL ARCHIVO"<<endl<<endl;
        exit(1);
    }

    //Va desde 0 hasta el valor de i, que es la posicion del frente que marcó en el main
    for(cont = i; cont < contP; cont++){
        archivoProductos.write(reinterpret_cast<const char *>(&prod[cont]), sizeof(Producto));
    }

    archivoProductos.close();
}