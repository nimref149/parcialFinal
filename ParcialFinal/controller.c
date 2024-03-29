#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "llamada.h"
#include "controller.h"
#include "parser.h"
#include <string.h>
#include "input.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path,LinkedList* pArrayList)
{
    int retorno=-1;
    FILE* archivo;
    if(pArrayList!=NULL)
    {
        archivo=fopen(path,"r");
        if(path!=NULL&&archivo!=NULL)
        {
            retorno=parser_DatosFromText(archivo,pArrayList);
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
int controller_loadFromBinary(char* path, LinkedList* pArrayList)
{
    int retorno=-1;
    FILE* archivoB;
    if(pArrayList!=NULL)
    {
        archivoB=fopen(path,"rb");
        if(archivoB!=NULL&&path!=NULL)
        {
            retorno=parser_DatosFromBinary(archivoB,pArrayList);
            fclose(archivoB);
        }
    }
    else
    {
        retorno=-2;
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* aux;
    int id;
    char idConvert[100];
    char nombre[100];
    char sueldo[100];
    char horas[100];
    int listaCargada;
    listaCargada=ll_isEmpty(pArrayListEmployee);
    if(pArrayListEmployee != NULL)
    {
        if(listaCargada!=1){
        system("cls");
        id=autoId(pArrayListEmployee,1);
        sprintf(idConvert,"%d",id);//convertir id a cadena
        while(getStringLetras(nombre,"Ingrese el nombre del empleado: ","Error",1,25)==-1);
        while(getStringNumeros(horas,"Ingrese las horas trabajadas: ","Error",1,1000)==-1);
        while(getStringFlotantes(sueldo,"Ingrese el sueldo del empleado: ","Error",1,100000)==-1);

        aux=employee_newParametros(idConvert,nombre,horas,sueldo);
        printf("ID \t\t     NOMBRE \t SUELDO \t HORAS\n");
        employee_list(aux);
        if(confirm("Desea confirmar el empleado? S/N\n")==1)
        {
            ll_add(pArrayListEmployee,aux);
            retorno=1;
        }
        else
        {
            free(aux);
            aux=NULL;
            retorno=0;
        }
        }else{
        retorno=-2;
        }

    }

    return retorno;
}


* \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id=0;
    int listaCargada;
    listaCargada=ll_isEmpty(pArrayListEmployee);
    int idMayor;
    int retorno=-1;
    idMayor=buscarIdMayor(pArrayListEmployee);
    int respuesta;
    if(pArrayListEmployee!=NULL)
    {
        if(listaCargada!=1)
        {
            controller_ListEmployee(pArrayListEmployee);
            while(getIntValid(&id,"Ingrese ID de empleado a modificar: ","Error",1,idMayor)==-1);
            respuesta=BuscarEmpleadoPorId(pArrayListEmployee,id);
            if(respuesta!=-1)
            {
                retorno=menuModificarEmpleado(pArrayListEmployee,respuesta);
            }
            else
            {
                retorno=-3;
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

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux;
    int listaCargada;
    int retorno=-1;
    int id;
    int idMayor;
    int respuesta;
    listaCargada=ll_isEmpty(pArrayListEmployee);
    if(pArrayListEmployee!=NULL)
    {
        if(listaCargada!=1)
        {
            idMayor=buscarIdMayor(pArrayListEmployee);
            controller_ListEmployee(pArrayListEmployee);
            while(getIntValid(&id,"Ingrese id de empleado a eliminar: ","Error",1,idMayor)==-1);
            respuesta=BuscarEmpleadoPorId(pArrayListEmployee,id);
            if(respuesta!=-1)
            {
                printf("Se eliminar el siguiente empleado\n");
                printf("  ID \t\t     NOMBRE \t SUELDO \t HORAS\n");
                aux=(Employee*)ll_get(pArrayListEmployee,respuesta);
                printf("\n");
                employee_list(aux);
                printf("\n");
                if(confirm("Esta seguro que desea eliminar? S/N \n")==1)
                {
                    ll_remove(pArrayListEmployee,respuesta);
                    retorno=1;
                }
                else
                {
                    retorno=0;
                }
            }
            else
            {
                retorno=-3;
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

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_ListLlamada(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    Llamada* aux;
    int len;
    int listaCargada;
    listaCargada=ll_isEmpty(pArrayListEmployee);
    if(pArrayListEmployee!=NULL)
    {
        if(listaCargada!=1)
        {
            len=ll_len(pArrayListEmployee);
            printf("\n\nLista de empleados\n");
            printf("ID_Llamada   Fecha   Numero_Cliente         ID_Problema          Solucionado\n");
            for(i=0; i<len; i++)
            {
                aux= (Llamada*)  ll_get(pArrayListEmployee, i);
                Llamada_list(aux);
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

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    int len;
    Llamada* aux;
    FILE* miArchivo;

    if(path!=NULL&&pArrayListEmployee!=NULL)
    {
        miArchivo=fopen(path,"w");
        if(miArchivo!=NULL)
        {
            len=ll_len(pArrayListEmployee);
            fprintf(miArchivo,"ID_Llamada,Fecha,Numero_Cliente,ID_Problema,Solucionado\n");
            for(i=0; i<len; i++)
            {
                aux=(Llamada*)ll_get(pArrayListEmployee,i);
                fprintf(miArchivo,"%d,%s,%d,%d,%s\n",aux->idLlamada,aux->fecha,aux->numeroCliente,aux->idProblema,aux->solucionado);
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
    Llamada* aux;
    FILE* miArchivo;
    if(path!=NULL&&pArrayListEmployee!=NULL)
    {
        miArchivo=fopen(path,"wb");
        if(miArchivo!=NULL)
        {
            len=ll_len(pArrayListEmployee);
            for(i=0; i<len; i++)
            {
                aux=(Llamada*)ll_get(pArrayListEmployee,i);
                fwrite(aux,sizeof(Llamada),1,miArchivo);

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




int autoId(LinkedList* pArrayListEmployee,int inicio)
{
    int retorno;
    int idMayor;
    idMayor=buscarIdMayor(pArrayListEmployee);
    if(idMayor!=-1)
    {
        retorno=idMayor+1;
    }
    else
    {
        retorno=inicio;
    }

    return retorno;
}
int buscarIdMayor(LinkedList* pArrayListEmployee)
{
    Llamada* aux;
    int retorno=-1;
    int i;
    int flag=0;
    int mayor=0;
    int len;
    if(pArrayListEmployee != NULL){

    len=ll_len(pArrayListEmployee);
    for(i=0; i<len; i++)
    {
        aux=(Llamada* )ll_get(pArrayListEmployee,i);
        if(aux->idLlamada>mayor)
        {
            mayor=aux->idLlamada;
            flag=1;
        }
    }
    if(flag!=0)
    {
        retorno=mayor;
    }

    }
    return retorno;
}

int BuscarLlamadaPorId(LinkedList* pArrayListEmployee,int id)
    {
        Llamada* aux=NULL;
        int len;
        int numero=-1;
        int i;
        len=ll_len(pArrayListEmployee);
        for(i=0; i<len; i++)
        {
            aux=(Llamada*)ll_get(pArrayListEmployee,i);
            if(id==aux->idLlamada)
            {
                numero=ll_indexOf(pArrayListEmployee, aux);
                //printf("Numero %d \n",numero);
                break;
            }
        }
        return numero;
    }

int menuCargarArchivo(LinkedList*lista)
{
    int retorno;
    char nombre[50];
    while(getStringLetrasYpuntos(nombre,"Ingrese nombre del archivo: ","Error",1,50));
    retorno=controller_loadFromText(nombre,lista);
    return retorno;
}

int FiltrarLlamada(LinkedList* lista)
{
    LinkedList* auxLista=NULL;
    int retorno=-1;
    int opcion;
    int len;
    len=ll_len(lista);
    if(lista!=NULL&&len>0)
    {

        while(getIntValid(&opcion,"Menu filtrar, ingrese una opcion:\n1-No enciende PC\n2-No funciona mouse\n3-No funciona teclado\n4-No hay internet\n5-No funciona telefono\n6Salir\n","Error",1,6));
        switch(opcion)
        {
        case 1:
            auxLista=ll_filter(lista,fn1);
            if(auxLista!=NULL)
            {
            controller_saveAsText("PC.csv",auxLista);
            printf("El nombre del archivo es PC.csv\n");
            retorno=1;
            }
            break;
        case 2:
            auxLista=ll_filter(lista,fn2);
            if(auxLista!=NULL)
            {
            controller_saveAsText("MOUSE.csv",auxLista);
            printf("El nombre del archivo es MOUSE.csv\n");
            retorno=1;
            }
            break;
        case 3:
            auxLista=ll_filter(lista,fn3);
            if(auxLista!=NULL)
            {
            controller_saveAsText("TECLADO.csv",auxLista);
            printf("El nombre del archivo es TECLADO.csv\n");
            retorno=1;
            }
            break;
        case 4:
            auxLista=ll_filter(lista,fn4);
            if(auxLista!=NULL)
            {
            controller_saveAsText("INTERNET.csv",auxLista);
            printf("El nombre del archivo es INTERNET.csv\n");
            retorno=1;
            }
            break;
        case 5:
            auxLista=ll_filter(lista,fn5);
            if(auxLista!=NULL)
            {
            controller_saveAsText("TELEFONO.csv",auxLista);
            printf("El nombre del archivo es TELEFONO.csv\n");
            retorno=1;
            }
            break;
        case 6:
            printf("Saliendo\n");
            retorno=0;
            break;
        }
    }
    ll_clear(lista);
    return retorno;

}


/*
int menuModificarEmpleado(LinkedList* pArrayListEmployee,int index)
{
    int retorno=0;
    int opcion;
    char auxNombre[100];
    float auxSueldo;
    int auxHoras;
    Employee* aux;
    aux=(Employee*)ll_get(pArrayListEmployee,index);
    printf("Este es el empleado a modificar: \n");
    printf("ID \t\t     NOMBRE \t SUELDO \t\t HORAS\n");
    employee_list(aux);
    while(getIntValid(&opcion,"Que desea modificar?\n1.Nombre\n2.Horas trabajadas\n3.Sueldo\n4.Salir\nElija dato a modificar: ","Error",1,4)==-1);
    switch(opcion)
    {
    case 1:
        while(getStringLetras(auxNombre,"Ingrese nuevo nombre: ","Error",1,25)==-1);
        printf("Nombre : %s\n",auxNombre);
        if(confirm("Desea confirmar? s/n \n")==1)
        {
            employee_setNombre(aux,auxNombre);
            ll_set(pArrayListEmployee,index,(Employee*)aux);
            retorno=1;
        }
        break;
    case 2:
        while(getIntValid(&auxHoras,"Ingrese horas: ","Error",1,1000)==-1);
        printf("Horas : %d\n",auxHoras);
        if(confirm("Desea confirmar? s/n\n")==1)
        {
            employee_setHorasTrabajadas(aux,auxHoras);
            ll_set(pArrayListEmployee,index,(Employee*)aux);
            retorno=1;
        }
        break;

    case 3:
        while(getFloatValid(&auxSueldo,"Ingrese nuevo sueldo: ","Error",1,100000)==-1);
        printf("Sueldo : %d\n",auxHoras);
        if(confirm("Desea confirmar? s/n\n")==1)
        {
            employee_setSueldo(aux,auxSueldo);
            ll_set(pArrayListEmployee,index,(Employee*)aux);
            retorno=1;
        }
        break;
    case 4:
        printf("Saliendo\n");
        retorno=0;
        break;
    }

    return retorno;
}
*/
