#include <stdlib.h>
#include <string.h>
#include "alumnos.h"
#include <stdio.h>
#include "index.h"

Datos* Datos_new()
{
    Datos* lista = (Datos*) malloc(sizeof(Datos));
    if( lista != NULL)
    {
        strcpy(lista->nombre,"");
        lista->edad = 0;
        lista->legajo = 0;
        strcpy(lista->sexo,"");
    }
    return lista;
}

Datos* Datos_newParametros(char* dato1,char* dato2,char* dato3, char* dato4)
{

    Datos* lista;
    lista  = Datos_new();

    if (dato1 != NULL && dato2 != NULL && dato3 != NULL && dato4 != NULL)
    {

        if( lista != NULL)
        {
                Datos_setDato1(lista,dato1);
                Datos_setDato2(lista,atoi(dato2));
                Datos_setDato3(lista,atoi(dato3));
                Datos_setDato4(lista,dato4);

        }else{

        printf("No se encontro memoria \n");

        }
    }

    return lista;
}

int Datos_setDato1(Datos* lista,char* dato)
{

    int todoOk = 0;

    if( lista != NULL && dato != NULL && strlen(dato) > 1)
    {

        strcpy(lista->nombre, dato);
        todoOk = 1;
    }

    return todoOk;
}


int Datos_getDato1(Datos* lista,char* dato)
{

    int todoOk = 0;

    if( lista != NULL && dato != NULL )
    {

        strcpy(dato, lista->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int Datos_setDato2(Datos* lista,int dato)
{

    int todoOk = 0;

    if( lista != NULL && dato > 0)
    {

        lista->edad = dato;
        todoOk = 1;
    }


    return todoOk;

}

int Datos_getDato2(Datos* lista,int* dato)
{

    int todoOk = 0;

    if( lista != NULL && dato != NULL )
    {

        *dato = lista->edad;
        todoOk = 1;
    }

    return todoOk;

}



int Datos_setDato3(Datos* lista,int dato)
{

    int todoOk = 0;

    if( lista != NULL && dato > 0)
    {

        lista->legajo = dato;
        todoOk = 1;
    }

    return todoOk;
}
int Datos_getDato3(Datos* lista,int* dato)
{

    int todoOk = 0;

    if( lista != NULL && dato != NULL )
    {

        *dato = lista->legajo;
        todoOk = 1;
    }
    return todoOk;

}

int Datos_setDato4(Datos* lista,char* dato)
{
    int todoOk=0;
    if( lista != NULL && dato != NULL)
    {

        strcpy(lista->sexo, dato);
        todoOk = 1;
    }

    return todoOk;
}

int Datos_getDato4(Datos* lista,char* dato)//devuelve un idProblema
{
    int todoOk = 0;

    if( lista != NULL && dato != NULL )
    {

        strcpy(dato, lista->sexo);
        todoOk = 1;
    }
    return todoOk;
}


int Datos_list(Datos* lista)
{
        printf("%5d %20s %10d   %5s \n",lista->legajo,lista->nombre,lista->edad,lista->sexo);

    return 1;
}

int fn(void* pElement)
{

    int compara = 0;
    Datos* Datoss=(Datos*)pElement;
    int edad;
    Datos_getDato2(Datoss,&edad);

    if(edad>30)
    {
        compara=1;
    }
    return compara;

}

int comprarPorDato2(void* estructuraUno,void* estructuraDos)
{
    int compara=-1;
    int dato2e1;
    int dato2e2;

    Datos* estructura1=(Datos*)estructuraUno;
    Datos* estructura2=(Datos*)estructuraDos;

    Datos_getDato2(estructura1,&dato2e1);
    Datos_getDato2(estructura2,&dato2e2);
    if(dato2e1>dato2e2)
    {
        compara=1;
    }
    else
    {

        if(dato2e1==dato2e2)
        {
            compara=0;

        }
    }
    return compara;
}









