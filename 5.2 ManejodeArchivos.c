/*5.2 Dado el archivo EMPLEADOS.DAT con el siguiente formato de registro:
� Legajo (entero)
� Apellido (texto de 15 caracteres m�ximo)
� Nombre (texto de 30 caracteres m�ximo)
� Fecha de Ingreso (Estructura con 3 enteros d�a, mes y a�o)
� Categor�a (entero del 1 al 4)
Se solicita ingresar la fecha del d�a y realizar un proceso que actualice la categor�a de los empleados seg�n la
antig�edad en la empresa seg�n la siguiente escala:
Categor�a 1: de 0 a 2 a�os de antig�edad
Categor�a 2: de 3 a 5 a�os de antig�edad
Categor�a 3: de 6 a 10 a�os de antig�edad
Categor�a 5: m�s de 10 a�os de antig�edad*/
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
int Datoval(int,int);
int main()
{
    Registro regis;
    Fecha fActual;
    FILE*arch=fopen("empleados.dat","r+b");
    if(arch==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(2);
    }
    printf("Ingrese fecha actual\n");
    printf("Ingrese dia\n");
    fActual.dia=Datoval(1,31);
    printf("Ingrese mes\n");
    fActual.mes=Datoval(1,12);
    printf("Ingrese anio\n");
    fActual.anio=Datoval(1000,2023);
    fread(&regis,sizeof(Registro),1,arch);
    while(!feof(arch))
    {
        if((fActual.anio-regis.fecha.anio)<=2)
        {
          regis.categoria=1;
          fseek(arch,-sizeof(Registro),SEEK_CUR);
          fwrite(&regis,sizeof(Registro),1,arch);
          fflush(arch);
        }else if((fActual.anio-regis.fecha.anio)<=5)
        {
            regis.categoria=2;
            fseek(arch,-sizeof(Registro),SEEK_CUR);
            fwrite(&regis,sizeof(Registro),1,arch);
            fflush(arch);
        }else if((fActual.anio-regis.fecha.anio)<=10)
        {
            regis.categoria=3;
            fseek(arch,-sizeof(Registro),SEEK_CUR);
            fwrite(&regis,sizeof(Registro),1,arch);
            fflush(arch);
        }else
        {
            regis.categoria=5;
            fseek(arch,-sizeof(Registro),SEEK_CUR);
            fwrite(&regis,sizeof(Registro),1,arch);
            fflush(arch);
        }
         fread(&regis,sizeof(Registro),1,arch);
    }
    fclose(arch);

}
int Datoval(int lim1,int lim2)
{
    int d;
    do
    {
        scanf("%d",&d);
        if(d<lim1||d>lim2)
            printf("Dato incorrecto vuelva a ingresar\n");
    }while(d<lim1||d>lim2);
    return d;
}
