#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "alumnos.h"
#include "index.h"
/**
1-Crear archivo alumnos.csv que va a contiene información de 10 alumnos (nombre ,edad, legajo , sexo), los cuales
deberán ser creados de manera dinámica almacenados en un arrayList.
2- Listar los del arraylist ordenados por edad.
*/

int main()
{
    int opcion;
    LinkedList* lista=ll_newLinkedList();
    do
    {
        while(getIntValid(&opcion,"Menu\n1-Cargar archivo\n2-Listar ordenados por edad\n3-Filtrar y crear archivo\n4-salir\n","Error",1,4));
        switch(opcion)
        {
        case 1:
            menuCargarArchivo(lista);
            break;
        case 2:
            controller_ListDatosOrdenado(lista);
            break;
        case 3:
            FiltrarDatos(lista);
            break;
        case 4:
            printf("saliendo");
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion!=4);

    return 0;
}

-----------------------------------------------------------------------------------------
int main()
{
    int opcion;
    LinkedList* lista=ll_newLinkedList();
    do
    {
        while(getIntValid(&opcion,"Menu\n1-------\n2---------\n3------------\n4-salir\n","Error",1,4));
        switch(opcion)
        {
        case 1:
            //menuCargarArchivo(lista);
            break;
        case 2:
            //controller_ListDatosOrdenado(lista);
            break;
        case 3:
            //FiltrarDatos(lista);
            break;
        case 4:
            printf("saliendo");
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion!=4);

    return 0;
}
