/*Tomar el archivo de empleados del punto 5.2 y ordenarlo en forma ascendente por legajo y mostrarlo en
forma de listado.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int dia;
    int mes;
    int anio;
}Fecha;
typedef struct
{
    int legajo;
    char Apellido[16];
    char Nombre[31];
    Fecha fecha;
    int categoria;
}Registro;
int main()
{
    Registro rAnterior,rActual;
    int ordenado;
    FILE*arch=fopen("empleados.dat","r+b");
    if(arch==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(2);
    }
    do
    {
         ordenado=1;
         fseek(arch,0,SEEK_SET);
         fread(&rActual,sizeof(Registro),1,arch);
         while(!feof(arch))
         {
             rAnterior=rActual;
             fread(&rActual,sizeof(Registro),1,arch);
             if(rActual.legajo<rAnterior.legajo)
             {
                 fseek(arch,-2*sizeof(Registro),SEEK_CUR);
                 fwrite(&rActual,sizeof(Registro),1,arch);
                 fwrite(&rAnterior,sizeof(Registro),1,arch);
                 fflush(arch);
                 rActual=rAnterior;
                 ordenado=0;
             }
         }
    }while(!ordenado);
    fclose(arch);
}
