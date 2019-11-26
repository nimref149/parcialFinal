
#ifndef Datos_H_INCLUDED
#define Datos_H_INCLUDED
typedef struct
{
    char nombre[50];
    int edad;
    int legajo;
    char sexo[1];
}Datos;

Datos* Datos_new();
Datos* Datos_newParametros(char* dato1,char* dato2,char* dato3, char* dato4);
void Datos_delete();

int Datos_setDato1(Datos* this,char* dato);
int Datos_getDato1(Datos* this,char* dato);

int Datos_setDato2(Datos* this,int dato);
int Datos_getDato2(Datos* this,int* dato);

int Datos_setDato3(Datos* this,int dato);
int Datos_getDato3(Datos* this,int* dato);

int Datos_setDato4(Datos* this,char* dato);//carga un sueldo
int Datos_getDato4(Datos* this,char* dato);//devuelve un sueldo


int Datos_list(Datos* this );
int comprarPorDato2(void*,void*);

int fn(void* pElement);


#endif // Datos_H_INCLUDED

