/*Se ingresan código y precio unitario de los productos que vende un negocio. No se sabe la cantidad
exacta de productos, pero sí se sabe que son menos de 50. El código es alfanumérico de 3 caracteres y
la carga de los datos de productos termina con un código igual al “FIN”. Luego se registran las ventas del
día y por cada venta se ingresa el código de producto y cantidad de unidades vendidas terminando con
una cantidad igual a 0. Se solicita:
c. Calcular la recaudación total del día y el producto del cual se vendió menor cantidad de unidades.
d. Mostrar el listado de productos con su precio ordenado en forma alfabética por código de
producto.*/
#include <stdio.h>
int Cargadecodigos(char[][4],int);
int Buscar(char[][4],char,int);
int main()
{
    char cod[50][4];
    int udv[50],cant;
    cant=Cargadecodigos(cod,50);
}
int Cargadecodigos(char m[][4],int ce)
{
    int i=0,pos=-1;
    char cod[4];
    printf("Ingrese codigo de tres caracteres(FIN para terminar)\n");
    do
    {
     fgets(cod,4,stdin);
     if(strcmpi(cod,4)>0)
        printf("Error vuelva a ingresar\n");
    }while(strcmpi(cod,4)>0);
    while(strcmpi(cod!='FIN')&&i<ce)
    {
        pos=Buscar(m,cod,ce);
        if(pos==-1)
        {
        strcpy(m[i],i);
        i++;
        }else printf("codigo ya existe vuelva a ingresar\n");

        printf("Ingrese codigo de tres caracteres(FIN para terminar)\n");
    do
    {
     fgets(cod,4,stdin);
     if(strcmpi(cod,4)>0)
        printf("Error vuelva a ingresar\n");

    }while(strcmpi(cod,4)>0);
    }
    return i;
}
int Buscar(char m[][4],char bus,int ce)
{
    int i=0,pos=-1;
    while(pos==1&&i<ce)
    {
        if(strcmpi(m[i],bus)==0)
            pos=i;
    }
    return pos;
}
