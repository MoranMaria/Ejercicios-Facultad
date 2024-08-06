/*Una empresa que vende neumáticos desea realizar un programa para actualizar el total de ventas del mes
de sus productos. Para ello primeramente se ingresan la información de los productos formados por:
• Código (5 caracteres).
• Precio (real).
• Descripción (30 caracteres).
• Cantidad de unidades vendidas (al mes anterior, entero).
• Importe Total Vendido (al mes anterior, real).
Se sabe que la empresa no vende más de 50 productos. El ingreso de la carga de productos finaliza con un
producto con descripción “FIN”.
Luego ingresan las ventas del mes:
• Código de Producto (5 caracteres).
• Cantidad pedida.
El ingreso de datos de las ventas finaliza con una cantidad igual a 0. Se solicita:
a. Actualizar la información de los productos con las ventas realizadas en el mes.
b. Al finalizar, mostrar el listado de productos actualizado, informando:*/

#include <stdio.h>
#include <string.h>
typedef struct
{
    char codigo[6];
    float precio;
    char descripcion[31];
    int CantVend;
    float ImpTotal;
}Producto;
void CARGA_DE_PRODUCTOS(Producto[],int);
void CargaVentasMes(Producto[],int);
void CargarCodigo(Producto[],int);
int Buscar(Producto[],int);
int BuscarCod(Producto[],char[],int);
float MayoraCero(float);
int IngreseDatoVal(int);


int main()
{
    Producto prod[5];
    CARGA_DE_PRODUCTOS(prod,50);
    CargaVentasMes(prod,5);
    return 0;
}
void CARGA_DE_PRODUCTOS(Producto p[],int ce)
{
    int i=0;
    char descrip[31],codigo[6];
    float precio;
    printf("Ingrese la descripcion del productro o 'FIN' para finalizar\n");
    gets(descrip);
    while(strcmpi(descrip,"FIN")!=0&&i<5)
    {
        strcpy(p[i].descripcion,descrip);
        printf("Ingrese codigo del producto de 5 caracteres\n");
        CargarCodigo(p,i);
        printf("Ingrese el precio del producto\n");
        precio=MayoraCero(0.0);
        p[i].precio=precio;
        i++;
        printf("Ingrese la descripcion del productro o 'FIN' para finalizar\n");
        fflush(stdin);
        gets(descrip);
    }
}
void CargaVentasMes(Producto p[],int ce)
       {
        int pos,unvend;
        char cod[6];

        printf("Cantidad de unidades vendidas\n");
        unvend=IngreseDatoVal(0);
        while(unvend!=0)
        {
        printf("Ingrese codigo del producto\n");
        do
        {
           fflush(stdin);
           gets(cod);
           pos=BuscarCod(p,cod,ce);
           if(pos==-1)
            printf("Codigo no existe vuelva a ingresar\n");
        }while(pos==-1);
        p[pos].CantVend=unvend;
        p[pos].ImpTotal=p[pos].precio*unvend;
        printf("Cantidad de unidades vendidas\n");
        unvend=IngreseDatoVal(0);
        }
        }

void CargarCodigo(Producto p[],int i)
{
    char codigo[6];
    int pos=-1;
do
        {
        gets(codigo);
        if (strlen(codigo) != 5)
            printf("Error vuelva a ingresar\n");
            else
            {
                pos=Buscar(p,i);
                if(i!=0&&pos!=-1)
                    printf("Codigo ya existe vuelva a ingresar\n");
            }
        }while(strlen(codigo)!=5||pos!=-1);
        strcpy(p[i].codigo,codigo);
}
int Buscar(Producto p[],int ce)
{
    int i=0,pos=-1;
    while(i<ce&&pos==-1)
    {
        if(strcmpi(p[i].codigo,p[ce].codigo)==0)
        {
            pos=i;
        }else i++;
    }
    return pos;
}
float MayoraCero(float cero)
{
    float num;
    do
    {
        scanf("%f",&num);
        if(num<=cero)
            printf("Dato invalido vuelva a ingresar\n");
    }while(num<=cero);
    return num;
}
int IngreseDatoVal(int cero)
{
    int d;
    do
    {
        scanf("%d",&d);
        if(d<cero)
            printf("Dato invalido vuelva a ingresar\n");
    }while(d<cero);
    return d;
}
int BuscarCod(Producto p[],char bus[],int ce)
{
	{
    int i=0,pos=-1;
    while(i<ce||pos==-1)
    {
        if(strcmpi(p[i].codigo,bus)==0)
        {
            pos=i;
        }else i++;
    }
    return pos;
}
}





