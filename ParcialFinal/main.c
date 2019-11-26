#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "llamada.h"
#include "input.h"
/***
Se deber� realizar un programa que permita el an�lisis de dicho archivo y sea capaz de generar un
nuevo archivo de salida de formato similar en el cual solo sean incluidas las llamadas de un problema
en particular especificado por el usuario.

El programa contar� con el siguiente men�:

1) Cargar archivo: Se pedir� el nombre del archivo y se cargar� en un LinkedList los elementos del
mismo.

2) Imprimir Llamadas: Se imprimir� por pantalla la tabla con los datos de las llamadas indicando el
problema en forma de texto (no de n�mero)

3) Generar archivo de llamadas: Se pedir� que se ingrese el n�mero de problema (1 a 5), y se
generar� un archivo CSV con el mismo formato que el original, pero solo con las llamadas de dicho
tipo de problema.

4) Salir.
*/

int main()
{
    int opcion;
    LinkedList* lista=ll_newLinkedList();
    //char nombre[10];
    do
    {
        while(getIntValid(&opcion,"Menu: \n1-Cargar archivo\n2-Imprimir llamadas\n3-Generar archivo de llamadas\n4-Salir\n","Salir",1,4));

        switch(opcion)
        {
        case 1:
            menuCargarArchivo(lista);
            break;
        case 2:
            controller_ListLlamada(lista);

            break;
        case 3:
            FiltrarLlamada(lista);
            break;
        case 4:
            printf("Saliendo\n");
            break;
        }
        system("pause");
        system("cls");

    }
    while(opcion!=4);

    return 0;
}





























