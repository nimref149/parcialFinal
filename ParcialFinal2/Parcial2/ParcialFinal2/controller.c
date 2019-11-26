#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "alumnos.h"
#include "controller.h"
#include "parser.h"
#include <string.h>
#include "index.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path,LinkedList* lista)
{
    int retorno=-1;
    FILE* archivo;
    if(lista!=NULL)
    {
        archivo=fopen(path,"r");
        if(path!=NULL&&archivo!=NULL)
        {
            retorno=parser_DatosFromText(archivo,lista);
            fclose(archivo);
        }
    }
    else
    {
        retorno=-2;
    }
    return retorno;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* lista)
{
    int retorno=-1;
    FILE* archivoB;
    if(lista!=NULL)
    {
        archivoB=fopen(path,"rb");
        if(archivoB!=NULL&&path!=NULL)
        {
            retorno=parser_DatosFromBinary(archivoB,lista);
            fclose(archivoB);
        }
    }
    else
    {
        retorno=-2;
    }
    return retorno;
}

/*
int controller_ListDatos(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    Datos* aux;
    int len;
    int listaCargada;
    listaCargada=ll_isEmpty(pArrayListEmployee);
    if(pArrayListEmployee!=NULL)
    {
        if(listaCargada!=1)
        {
            len=ll_len(pArrayListEmployee);
            printf("\n\nLista de empleados\n");
            printf("ID_Datos   Fecha   Numero_Cliente         ID_Problema          Solucionado\n");
            for(i=0; i<len; i++)
            {
                aux= (Datos*)  ll_get(pArrayListEmployee, i);
                Datos_list(aux);
            }
            retorno=1;
        }
        else
        {
            retorno=-2;
        }
    }
    return retorno;
}

*/




/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int opcion;
    int respuesta;
    int listaCargada;
    listaCargada=ll_isEmpty(pArrayListEmployee);
    if(pArrayListEmployee!=NULL)
    {
        if(listaCargada!=1)
        {
            system("cls");
            while(getIntValid(&opcion,"Menu ordenar empleados\n1-Por id\n2-Por sueldo\n3-Por nombre\n4-Por horas\n5-Salir\n","Error",1,5)==-1);
            switch(opcion)
            {
            case 1:
                while(getIntValid(&respuesta,"ELIJA EL ORDEN\n0-De mayor a menor\n1-De menor a mayor\n","Error",0,1)==-1);
                ll_sort(pArrayListEmployee,compararPorLegajo,respuesta);
                retorno=1;
                break;
            case 2:
                while(getIntValid(&respuesta,"ELIJA EL ORDEN\n0-De mayor a menor\n1-De menor a mayor\n","Error",0,1)==-1);
                ll_sort(pArrayListEmployee,compararPorSueldo,respuesta);
                retorno=1;
                break;
            case 3:
                while(getIntValid(&respuesta,"ELIJA EL ORDEN\n0-De manera descendente\n1-De manera ascendente\n","Error",0,1)==-1);
                ll_sort(pArrayListEmployee,compararPorNombre,respuesta);
                retorno=1;
                break;
            case 4:
                while(getIntValid(&respuesta,"ELIJA EL ORDEN\n0-De mayor a menor\n1-De menor a mayor\n","Error",0,1)==-1);
                ll_sort(pArrayListEmployee,compararPorHoras,respuesta);
                retorno=1;
                break;
            case 5:
                printf("Saliendo\n");
                retorno=0;
                break;
            }
        }
        else
        {
            retorno=-2;
        }
    }

    return retorno;
}
*/

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char* path, LinkedList* lista)
{
    int retorno=-1;
    int i;
    int len;
    Datos* aux;
    FILE* miArchivo;
    if(path!=NULL&&lista!=NULL)
    {
        miArchivo=fopen(path,"w");
        if(miArchivo!=NULL)
        {
            len=ll_len(lista);
            fprintf(miArchivo,"NOMBRE,EDAD,LEGAJO,SEXO\n");
            for(i=0; i<len; i++)
            {
                aux=(Datos*)ll_get(lista,i);
                fprintf(miArchivo,"%s,%d,%d,%s\n",aux->nombre,aux->edad,aux->legajo,aux->sexo);
            }
            fclose(miArchivo);
            retorno=1;
        }
    }
    else
    {
        retorno=-2;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    int len;
    Datos* aux;
    FILE* miArchivo;
    if(path!=NULL&&pArrayListEmployee!=NULL)
    {
        miArchivo=fopen(path,"wb");
        if(miArchivo!=NULL)
        {
            len=ll_len(pArrayListEmployee);
            for(i=0; i<len; i++)
            {
                aux=(Datos*)ll_get(pArrayListEmployee,i);
                fwrite(aux,sizeof(Datos),1,miArchivo);
            }
            fclose(miArchivo);
            retorno=1;
        }
    }
    else
    {
        retorno=-2;
    }
    return retorno;
}



int menuCargarArchivo(LinkedList*lista)
{
    int retorno=-1;
    char nombre[50];
    while(getStringLetrasYpuntos(nombre,"Ingrese nombre del archivo: ","Error",1,50));
    retorno=controller_loadFromText(nombre,lista);
    return retorno;
}

int controller_ListDatosOrdenado(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    Datos* aux;
    int len;
    int listaCargada;
    listaCargada=ll_isEmpty(pArrayListEmployee);
    if(pArrayListEmployee!=NULL)
    {
        if(listaCargada!=1)
        {
            ll_sort(pArrayListEmployee,comprarPorDato2,1);
            len=ll_len(pArrayListEmployee);
            printf("\n\nLista\n");
            printf("ID   |Nombre              |edad     |sexo\n");
            for(i=0; i<len; i++)
            {
                aux= (Datos*)  ll_get(pArrayListEmployee, i);
                Datos_list(aux);
            }
            retorno=1;
        }
        else
        {
            retorno=-2;
        }
    }
    return retorno;
}



int FiltrarDatos(LinkedList* lista)
{
    LinkedList* auxLista=NULL;
    int retorno=-1;
    int len;
    len=ll_len(lista);
    if(lista!=NULL&&len>0)
    {
            auxLista=ll_filter(lista,fn);
            if(auxLista!=NULL)
            {
            controller_saveAsText("out.csv",auxLista);
            printf("El nombre del archivo es out.csv\n");
            retorno=1;
            }

    }
    ll_clear(lista);
    return retorno;

}



