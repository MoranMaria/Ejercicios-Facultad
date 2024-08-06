/*Se sabe que como máximo en una comisión de Elementos de Programación hay 80 alumnos. De cada
alumno se conoce:
• Número de DNI (entero).
• Apellido y Nombre (80 caracteres).
• Nota1, Nota2 (entero).
• Nota Promedio (real, calculado según Nota1 y Nota2).
Se solicita:
a. Declarar un tipo de dato que contenga la información del alumno.
b. Declarar un vector de estructuras del tipo de dato creado en el punto a.
c. Cargar en un vector de estructuras, los datos referentes a los alumnos de la comisión, esta
información termina con DNI igual al 0. Función INGRESO.
d. Indicar cuántos alumnos aprobaron (ambos parciales con nota >= 4 y cuántos reprobaron la
materia. Función RESULTADO.
e. Informar los datos de los alumnos de (DNI – Apellido y Nombre – Nota Promedio) de los alumnos.
PROMOCIONADOS (ambas notas >= 7). Función INFORME_PROMO.*/
#include <stdio.h>
#include <string.h>
typedef struct
{
    int dni;
    char NomApe[81];
    int Nota1;
    int Nota2;
    float NotaProm;
}Alumno;//P a
int INGRESO(Alumno[],int);
void RESULTADO(Alumno[],int);
void INFORME_PROMO(Alumno[],int);
int IngreseDatoVal(int,int,int);
int buscar(Alumno[],int,int);
int DatoVal(int,int);

int main()
{
    Alumno alum[80];//P b
    int cant;
    cant=INGRESO(alum,80);
    RESULTADO(alum,cant);
    INFORME_PROMO(alum,cant);
}
int INGRESO(Alumno a[],int ce)//P c
{
    int dni,i=0,pos;
    float notas=0;
    printf("Ingrese dni o '0' para terminar\n");
    dni=IngreseDatoVal(10000000,99999999,0);
    while(dni!=0&&i<ce)
    {
        notas=0;
        do
        {
           pos=buscar(a,dni,i);
           if(pos==-1)
            a[i].dni=dni;
           else{
            printf("Error dni ya existe vuelva a ingresar dni o '0' para terminar\n");
            dni=IngreseDatoVal(10000000,99999999,0);
           }

       }while(pos!=-1&&dni!=0);
       printf("Ingrese Nombre y Apellido\n");
       fflush(stdin);
       gets(a[i].NomApe);
       printf("Ingrese Primer Nota\n");
       a[i].Nota1=DatoVal(1,10);
       notas+=a[i].Nota1;
       printf("Ingresa Segunda Nota\n");
       a[i].Nota2=DatoVal(1,10);
       notas+=a[i].Nota2;
       a[i].NotaProm=notas/2;
       i++;
       printf("Ingrese dni o '0' para terminar\n");
       dni=IngreseDatoVal(10000000,99999999,0);
    }
    return i;
}
void RESULTADO(Alumno a[],int ce)//d
{
    int i,apro=0,desapro=0;
    for(i=0;i<ce;i++)
    {
        if((a[i].Nota1>4)&&(a[i].Nota2>4))
            apro++;
            else
                desapro++;
    }
    printf("Aprobaron %d Alumos\nDesaprobaron %d Alumnos \n\n",apro,desapro);
}
void INFORME_PROMO(Alumno a[],int ce)
{
    int i;
    printf("DNI\t\tNOMBRE Y APELLIDO\tPROMEDIO\n");
    for(i=0;i<ce;i++)
    {
        if((a[i].Nota1>=7)&&(a[i].Nota2>=7))
        {
            printf("%d\t%s\t\t%.2f\n",a[i].dni,a[i].NomApe,a[i].NotaProm);
        }
    }
}
int IngreseDatoVal(int lim1,int lim2,int fin)
{
    int d;
    do
    {
        scanf("%d",&d);
        if((d<lim1||d>lim2)&&d!=fin)
        {
            printf("Dato incorrecto vuelva a ingresar\n");
        }
    }while((d<lim1||d>lim2)&&d!=fin);
    return d;
}
int buscar(Alumno a[],int bus,int ce)
{
    int i=0,pos=-1;
    while(i<ce&&pos==-1)
    {
        if(a[i].dni==bus)
        {
            pos=i;
        }else i++;
    }
    return pos;
}
int DatoVal(int lim1,int lim2)
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
