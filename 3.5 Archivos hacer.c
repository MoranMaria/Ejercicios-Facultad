/*Se dispone de un archivo llamado Stock.dat que contiene la información de los 10 productos que vende una
fábrica. En el archivo se guarda:
• Código de artículo (entero)
• Descripción (50 caracteres máximo)
• Stock (entero)
Guía Práctica – V1.0 3 / 8
Luego se ingresan por teclado las ventas a realizar indicando:
• Código de artículo
• Cantidad
 La carga por teclado de las ventas finaliza con un código de artículo igual a 0.
Por cada venta se debe controlar si hay stock suficiente y si lo hay, restar el stock de dicho producto, sino
hay stock se debe vender lo que quede disponible y grabar un registro en un archivo Faltantes.dat con la
cantidad que no pudo venderse, dicho registro debe contener:
• Código de artículo
• Cantidad
Se genera un registro por cada venta que no pudo concretarse, pudiendo quedar en el archivo varios
registros faltantes del mismo producto.
Al finalizar actualizar el archivo Stock.dat con el stock actualizado luego de procesar las ventas.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
   int cod;
   char descrip[51];
   int stock;
}productos;
typedef struct
{
    int cod;
    int cant;
}FALTANTES;
void Cargar_productos(productos[]);
void Cargar_ventas(productos[],FALTANTES[],int);
void ARCHIVO_FALTANTES(FALTANTES[],int);
int Bucar(productos[],int,int);
int DatoVal(int);
void ACTUALIZAR_STOCK(productos[],int);

int main()
{
    productos p[11];
    FALTANTES falt[11]={0};
    Cargar_productos(p);
    Cargar_ventas(p,falt,11);
    ARCHIVO_FALTANTES(falt,11);
    ACTUALIZAR_STOCK(p,11);
}
void Cargar_productos(productos p[])
{
    productos prod;
    int i=0;
    FILE*arch=fopen("STOCK.dat","rb");
    if(arch==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(1);
    }
    fread(&prod,sizeof(productos),1,arch);
    while(!feof(arch))
    {
        p[i]=prod;
        i++;
        fread(&prod,sizeof(productos),1,arch);
    }
    fclose(arch);
}
void Cargar_ventas(productos p[],FALTANTES falt[],int ce)
{
    int cod,pos,cant,resto;

    printf("Ingrese codigo del articulo o '0' para terminar\n");
    scanf("%d",&cod);
    while(cod!=0)
    {
        pos=Bucar(p,cod,ce);
        if(pos!=-1)
        {
            printf("Ingrese cantidad\n");
            cant=DatoVal(1);
            if(p[pos].stock<cant)
            {
                falt[pos].cod=cod;
                falt[pos].cant+=(cant-p[pos].stock);
                p[pos].stock=0;
                printf("No hubo stock suficiente\n");
            }else if(p[pos].stock>cant||p[pos].stock==cant)
            {
                falt[pos].cod=cod;
                resto=p[pos].stock-cant;
                p[pos].stock=resto;
            }

        }else printf("Codigo no existe\n");
        printf("Ingrese codigo del articulo o '0' para terminar\n");
        scanf("%d",&cod);
    }
}
void ARCHIVO_FALTANTES(FALTANTES v[],int ce)
{
    FILE*f=fopen("Faltantes.dat","wb");
    if(f==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(1);
    }
    fwrite(v,sizeof(FALTANTES),ce,f);

    fclose(f);
}
int Bucar(productos p[],int bus,int ce)
{
    int i=0,pos=-1;
    while(i<ce&&pos==-1)
    {
        if(p[i].cod==bus)
        {
            pos=i;
        }else i++;
    }
    return pos;
}
int DatoVal(int nocero)
{
    int d;
    do
    {
        scanf("%d",&d);
        if(d<nocero)
            printf("Dato incorrecto vuelva a ingresar\n");
    }while(d<nocero);
    return d;
}
void ACTUALIZAR_STOCK(productos p[],int ce)
{
    FILE*arch=fopen("STOCK.dat","wb");
    if(arch==NULL)
    {
        printf("Error no se pudo abrir el archivo.");
        exit(1);
    }
    fwrite(p,sizeof(productos),ce,arch);
    fclose(arch);
}
