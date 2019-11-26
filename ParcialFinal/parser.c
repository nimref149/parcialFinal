#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "llamada.h"
#include "parser.h"
#include "input.h"
int parser_DatosFromText(FILE* pFile,LinkedList* pArrayList)
{
    int retorno;
    char idLlamada[100],fecha[100],numeroCliente[100],idProblema[100],solucionado[100];
    Llamada* aux=NULL;;
    if(pFile!=NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idLlamada,fecha,numeroCliente,idProblema,solucionado);//lectura falsa
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idLlamada,fecha,numeroCliente,idProblema,solucionado);

            aux=Llamada_newParametros(idLlamada,fecha,numeroCliente,idProblema,solucionado);

            ll_add(pArrayList,aux);

        }
        retorno=1;
    }else
    {
        retorno=0;
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_DatosFromBinary(FILE* pFile,LinkedList* pArrayList)
{
    int retorno;
    Llamada* aux;
    int respuesta;
    if(pFile != NULL && pArrayList != NULL)
    {
        //aux = (Llamada*) malloc(sizeof(Llamada));
        while(!feof(pFile))
        {
            aux=Llamada_new();
            respuesta=fread(aux, sizeof(Llamada), 1, pFile);
            if(respuesta == 1 && aux != NULL)
            {
                ll_add(pArrayList, aux);
            }
        }
        retorno=1;
    }
    else
    {
        retorno=0;
    }

    return retorno;
}


































































/*


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno;

    char id[100],nombre[100], horasTrabajadas[51], sueldo[20];
    Employee* aux=NULL;;
    if(pFile!=NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,nombre,horasTrabajadas,sueldo);//lectura falsa
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,nombre,horasTrabajadas,sueldo);

            aux=employee_newParametros(id,nombre,horasTrabajadas,sueldo);

            ll_add(pArrayListEmployee,aux);

            //printf("\n%d\n",ll_len(pArrayListEmployee));


        }
        retorno=1;
    }else
    {
        retorno=0;
    }
    return retorno;
}


int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno;
    Employee* aux;
    int respuesta;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        //aux = (Employee*) malloc(sizeof(Employee));
        while(!feof(pFile))
        {
            aux= employee_new();
            respuesta=fread(aux, sizeof(Employee), 1, pFile);
            if(respuesta == 1 && aux != NULL)
            {
                ll_add(pArrayListEmployee, aux);
            }
        }
        retorno=1;
    }
    else
    {
        retorno=0;
    }

    return retorno;
}

*/
