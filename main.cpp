/*
Equipo #3:

-> Domínguez Martínez Edder Emmanuel
-> Esqueda Rodríguez, Fabián Alejandro.
-> Godoy Rodríguez, Berenice.
-> Gómez Jiménez, Ángel Armando.
-> Gómez Ramírez, Eduardo Fabián.

Sección: D05
Calendario: 2021-A
*/
#include <iostream>
#include "producto.h"
using namespace std;

void menu_tienda();

size_t op;
int cont = 0, i = 0, cont2 = 0;
double total;
Producto prod[5], producto;
Cola<Producto> almacen;

int main(){
    system("color F1");
    system("cls");

    // Recuperar informacion desde el archivo
    fstream archivoProductosE("productos.dat", ios::in | ios::binary);

    //Valida si el archivo se pudo abrir, en caso de que si, recupera desde el archivo, 
    //si no, se va directo al menu de opciones
    if(archivoProductosE.is_open()){
        cout<<"\t\t\tRECUPERANDO LOS PRODUCTOS DESDE EL ARCHIVO"<<endl;
        while(!archivoProductosE.eof()){
            archivoProductosE.seekg((cont) * sizeof(Producto));
            archivoProductosE.read(reinterpret_cast<char *>(&prod[cont]), sizeof(Producto));

            if(prod[cont].regresarClave() != 0){
                almacen + prod[cont];
                cout<<prod[cont]<<endl;
                cont++;
                cont2++;
            }
            archivoProductosE.peek();
        }
        cout<<endl<<endl;
        system("pause"); system("cls");
    }

    archivoProductosE.close();
  
    //Si el archivo no esta abierto, se llama a esta funcion, que es donde esta el menú
    if(!archivoProductosE.is_open()){
        menu_tienda();
    }

    return 0;
}

void menu_tienda(){
do{
        //Menu de opciones
        cout<<"MENU - LA PANZA ES PRIMERO"<<endl<<endl;

        cout<<"1. COMPRA DE UN PRODUCTO (INSERTAR)"<<endl;
        cout<<"2. VENTA DE UN PRODUCTO (ELIMINAR)"<<endl;
        cout<<"3. TOTAL DE LO VENDIDO"<<endl;
        cout<<"4. SALIR"<<endl<<endl;

        cout<<"DIGITE UNA OPCION: ";
        cin>>op;

        system("cls");

        switch(op){
            case 1: cout<<"\t\t\tREGISTRAR PRODUCTO"<<endl<<endl;
                   if(cont < 5){
                        //Usando la sobrecarga del operador >> en la clase
                        cout<<"Producto #"<<cont2+1<<endl;
                        cin>>prod[cont];
                        almacen + prod[cont];//Se guarda el producto registrado en la cola
                        
                        cont2++;//Contadora para el numero de productos
                        cont++;//Contadora para el arreglo de productos
                    }
                    else{
                        cout<<"\n\n\tNO HAY LUGAR EN EL ALMACEN PARA REGISTRAR OTRO PRODUCTO\n\n";
                    }
                    cout<<endl<<endl;
                    system("pause"); system("cls");
                    break;
            
            case 2: cout<<"\t\t\tVENDER UN PRODUCTO AL CLIENTE"<<endl;
                    // i = 0;
                    //Si se pueden ir sacando los elementos de la cola
                    if(almacen - &prod[i]){//Se va quitando el producto (es una referencia, porque el parametro 
                                        //en la sobrecarga del operador -, es un puntero)
                        cout<<prod[i]<<endl;
                        total = total + prod[i].RegresaPrecio();
                        
                        i++;//Se incrementa este contador, para que el frente sea el siguiente elemento del arreglo                       
                        cont2--;//Decrementar el contador para el numero de productos(No el arreglo)
                    }
                    else{
                        cout<<"\n\n\t\tNO HAY PRODUCTOS EN EL ALMACEN\n\n";
                    }
                    cout<<endl<<endl;
                    system("pause"); system("cls");
                    break;

            case 3: cout<<"\t\t\tTOTAL DE VENTAS"<<endl<<endl;
                    
                    cout<<"Ventas totales: $"<<total<<endl<<endl;

                    cout<<endl<<endl;
                    system("pause"); system("cls");
                    break;

            case 4: cout<<"\t\t\tSALIENDO..."<<endl<<endl<<endl;
                    cout<<"LA INFORMACION ESTA SIENDO RESPALDADA EN UN ARCHIVO"<<endl<<endl<<endl;

                    producto.respaldar_productos(prod, cont, i);
        }

    }while(op != 4);

}