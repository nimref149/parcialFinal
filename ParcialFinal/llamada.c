#include <stdlib.h>
#include <string.h>
#include "llamada.h"
#include <stdio.h>
#include "input.h"

Llamada* Llamada_new()
{
    Llamada* this = (Llamada*) malloc(sizeof(Llamada));
    if( this != NULL)
    {
        this->idLlamada = 0;
        strcpy(this->fecha,"");
        this->numeroCliente = 0;
        this->idProblema = 0;
        strcpy(this->solucionado,"");
    }
    return this;
}

Llamada* Llamada_newParametros(char* idLlamadaStr,char* fechaStr,char* numeroClienteStr, char* idsolucionadoStr,char* solucionadoStr)
{

    Llamada* this;
    this  = Llamada_new();

    if (idLlamadaStr != NULL && fechaStr != NULL && numeroClienteStr != NULL && idsolucionadoStr != NULL&&solucionadoStr!=NULL)
    {

        if( this != NULL)
        {
                Llamada_setId(this, atoi(idLlamadaStr));
                Llamada_setFecha(this,fechaStr);
                Llamada_setNumeroCliente(this, atoi(numeroClienteStr));
                Llamada_setIdProblema(this, atoi(idsolucionadoStr));
                Llamada_setSolucionado(this,solucionadoStr);


        }else{

        printf("No se encontro memoria para el empleado\n");

        }
    }

    return this;
}

int Llamada_setId(Llamada* lista,int id)
{

    int todoOk = 0;

    if( lista != NULL && id > 0)
    {

        lista->idLlamada= id;
        todoOk = 1;
    }

    return todoOk;
}


int Llamada_getId(Llamada* lista,int* id)
{

    int todoOk = 0;

    if( lista != NULL && id != NULL )
    {

        *id = lista->idLlamada;
        todoOk = 1;
    }
    return todoOk;
}

int Llamada_setFecha(Llamada* this,char* fecha)
{

    int todoOk = 0;

    if( this != NULL && fecha != NULL && strlen(fecha) > 1)
    {

        strcpy(this->fecha, fecha);
        todoOk = 1;
    }

    return todoOk;

}

int Llamada_getFecha(Llamada* this,char* fecha)
{

    int todoOk = 0;

    if( this != NULL && fecha != NULL )
    {

        strcpy(fecha, this->fecha);
        todoOk = 1;
    }

    return todoOk;

}



int Llamada_setNumeroCliente(Llamada* this,int numeroCliente)
{

    int todoOk = 0;

    if( this != NULL && numeroCliente > 0)
    {

        this->numeroCliente = numeroCliente;
        todoOk = 1;
    }

    return todoOk;
}
int Llamada_getNumeroCliente(Llamada* this,int* numeroCliente)
{

    int todoOk = 0;

    if( this != NULL && numeroCliente != NULL )
    {

        *numeroCliente = this->numeroCliente;
        todoOk = 1;
    }
    return todoOk;

}

int Llamada_setIdProblema(Llamada* this,int idProblema)
{
    int estado=0;
    if(this!=NULL)
    {
        this->idProblema=idProblema;
        estado=1;
    }

    return estado;
}

int Llamada_getIdProblema(Llamada* this,int* idProblema)//devuelve un idProblema
{
    int todoOk = 0;

    if( this != NULL && idProblema != NULL )
    {

        *idProblema = this->idProblema;
        todoOk = 1;
    }
    return todoOk;
}


int Llamada_setSolucionado(Llamada* this,char* solucionado)
{

    int todoOk = 0;

    if( this != NULL && solucionado != NULL && strlen(solucionado) > 1)
    {

        strcpy(this->solucionado, solucionado);
        todoOk = 1;
    }

    return todoOk;

}

int Llamada_getSolucionado(Llamada* this,char* solucionado)
{

    int todoOk = 0;

    if( this != NULL && solucionado != NULL )
    {

        strcpy(solucionado, this->solucionado);
        todoOk = 1;
    }

    return todoOk;

}




int Llamada_list(Llamada* this)
{
    int numero;
    numero=this->idProblema;
    char problema1[]="No enciende PC";
    char problema2[]="No funciona mouse";
    char problema3[]="No funciona teclado";
    char problema4[]="No hay internet";
    char problema5[]="No funciona telefono";
    switch(numero)
    {
    case 1:
        printf("%5d %15s %10d   %25s %15s \n",this->idLlamada,this->fecha,this->numeroCliente,problema1,this->solucionado);
        break;
    case 2:
        printf("%5d %15s %10d   %25s %15s \n",this->idLlamada,this->fecha,this->numeroCliente,problema2,this->solucionado);
        break;
    case 3:
        printf("%5d %15s %10d   %25s %15s \n",this->idLlamada,this->fecha,this->numeroCliente,problema3,this->solucionado);
        break;
    case 4:
        printf("%5d %15s %10d   %25s %15s \n",this->idLlamada,this->fecha,this->numeroCliente,problema4,this->solucionado);
        break;
    case 5:
        printf("%5d %15s %10d   %25s %15s \n",this->idLlamada,this->fecha,this->numeroCliente,problema5,this->solucionado);
        break;
    }
    return 1;
}


/*
int Llamada_list(Llamada* this)
{
    char problema1[]="problema de pc";
    if(this!=NULL){

    printf("%5d %15s %10d   %10d %15s \n",this->idLlamada,this->fecha,this->numeroCliente,problema,this->solucionado);

    }
    return 1;
}

int Llamada_list(Llamada* this)
{
    printf("%5d %25s %10d   %10d %15s\n",this->idLlamada,this->fecha,this->numeroCliente,this->idProblema,this->solucionado);

    return 1;
}

*/

int fn1(void* pElement)
{
    {
        int compara = 0;
        Llamada* llamada=(Llamada*)pElement;
        int id;
        Llamada_getIdProblema(llamada,&id);

        if(id==1)
        {
            compara=1;
        }
        return compara;
    }
}

int fn2(void* pElement)
{
    {
        int compara = 0;
        Llamada* llamada=(Llamada*)pElement;
        int id;
        Llamada_getIdProblema(llamada,&id);
        if(id==2)
        {
            compara=1;
        }
        return compara;
    }
}
int fn3(void* pElement)
{
    {
        int compara = 0;
        Llamada* llamada=(Llamada*)pElement;
        int id;
        Llamada_getIdProblema(llamada,&id);
        if(id==3)
        {
            compara=1;
        }
        return compara;
    }
}
int fn4(void* pElement)
{
    {
        int compara = 0;
        Llamada* llamada=(Llamada*)pElement;
        int id;
        Llamada_getIdProblema(llamada,&id);
        if(id==4)
        {
            compara=1;
        }
        return compara;
    }
}

int fn5(void* pElement)
{
    {
        int compara = 0;
        Llamada* llamada=(Llamada*)pElement;
        int id;
        Llamada_getIdProblema(llamada,&id);
        if(id==5)
        {
            compara=1;
        }
        return compara;
    }
}


































/*
int compararPorLegajo(void* emple1,void* emple2)
{
    int compara=-1;
    int id1;
    int id2;

    Llamada* empleado1=(Llamada*)emple1;
    Llamada* empleado2=(Llamada*)emple2;
    Llamada_getId(empleado1,&id1);
    Llamada_getId(empleado2,&id2);

    if(id1>id2)
    {
        compara=1;
    }
    else
    {

        if(id1==id2)
        {
            compara=0;

        }
    }

    return compara;

}



int compararPoridsolucionado(void* e1,void* e2)
{
    int compara=-1;
    float idsolucionado1;
    float idsolucionado2;

    Llamada* empleado1=(Llamada*)e1;
    Llamada* empleado2=(Llamada*)e2;

    Llamada_getidsolucionado(empleado1,&idsolucionado1);
    Llamada_getidsolucionado(empleado2,&idsolucionado2);
    if(idsolucionado1>idsolucionado2)
    {
        compara=1;
    }
    else
    {

        if(idsolucionado1==idsolucionado2)
        {
            compara=0;

        }
    }
    return compara;
}

int compararPorfecha(void* emple1,void* emple2)
{
    int compara;

    Llamada* empleado1=(Llamada*)emple1;
    Llamada* empleado2=(Llamada*)emple2;

    char fechaEmpleado1[50];
    Llamada_getfecha(empleado1,fechaEmpleado1);
    char fechaEmpleado2[50];
    Llamada_getfecha(empleado2,fechaEmpleado2);
    compara=stricmp(fechaEmpleado1,fechaEmpleado2);

    return compara;

}
int compararPorHoras(void* emple1,void* emple2)
{
    int compara=-1;
    int horasEmpleado1;
    int horasEmpleado2;

    Llamada* empleado1=(Llamada*)emple1;
    Llamada* empleado2=(Llamada*)emple2;

    Llamada_getnumeroCliente(empleado1,&horasEmpleado1);
    Llamada_getnumeroCliente(empleado2,&horasEmpleado2);
    if(horasEmpleado1>horasEmpleado2)
    {
        compara=1;
    }
    else
    {

        if(horasEmpleado1==horasEmpleado2)
        {
            compara=0;

        }
    }
    return compara;
}
*/

