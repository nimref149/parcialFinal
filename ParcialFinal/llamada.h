#ifndef Llamada_H_INCLUDED
#define Llamada_H_INCLUDED
typedef struct
{
    int idLlamada;
    char fecha[50];
    int numeroCliente;
    int idProblema;
    char solucionado[10];
}Llamada;

Llamada* Llamada_new();
Llamada* Llamada_newParametros(char* idLlamadaStr,char* fechaStr,char* numeroClienteStr, char* idProblemaStr,char* solucionadoStr);
void Llamada_delete();

int Llamada_setId(Llamada* this,int id);
int Llamada_getId(Llamada* this,int* id);

int Llamada_setFecha(Llamada* this,char* fecha);
int Llamada_getFecha(Llamada* this,char* fecha);

int Llamada_setNumeroCliente(Llamada* this,int numeroCliente);
int Llamada_getNumeroCliente(Llamada* this,int* numeroCliente);

int Llamada_setIdProblema(Llamada* this,int idProblema);//carga un sueldo
int Llamada_getIdProblema(Llamada* this,int* idProblema);//devuelve un sueldo

int Llamada_setSolucionado(Llamada* this,char* solucionado);
int Llamada_getSolucionado(Llamada* this,char* solucionado);


int Llamada_list(Llamada* this );

int fn1(void* pElement);
int fn2(void* pElement);
int fn3(void* pElement);
int fn4(void* pElement);
int fn5(void* pElement);

/*
int compararPorLegajo(void*,void*);
int compararPorSueldo(void*,void*);
int compararPorNombre(void*,void*);
int compararPorHoras(void* ,void *);
*/

#endif // Llamada_H_INCLUDED

