/*Una fábrica produce como máximo 20 productos diferentes y necesita un reporte de la producción realizada
durante el año. Para ello se dispone del archivo “ARTICULOS.dat”, el cual contiene:
• Código de artículo (entero de 4 cifras no correlativo)
• Descripción del artículo (30 caracteres máximo)
• Cantidad de stock remanente del año anterior (entero)
A continuación, se procesa por teclado, la información correspondiente a todo el año:
• Número del mes de producción. Ingresar y controlar mediante la Función LEE_CONTROL.
• Código de artículo (entero de 4 cifras no correlativo) Ingresar y controlar un número de 4 cifras.
Función LEE_CONTROL.
• Cantidad de unidades que se produjeron en ese mes. Controlar si el número es mayor que 0.
Función MAYOR_CERO.
Esta información no se encuentra ordenada, y termina con número de mes igual a 0.
Se solicita construir un programa que determine e informe:
a. Para cada artículo, la cantidad de unidades producidas en cada uno de los 12 meses del año, de
acuerdo con el siguiente modelo:
Código Artículo Descripción Ene. Feb. … Oct. Nov. Dic.
XXX XXXXXXXXX XX XX … XX XX XX
XXX XXXXXXXXX XX XX … XX XX XX
b. Confeccionar un listado con el/los códigos y descripción de aquellos artículos que NO se produjeron
en todo el año.
c. Generar el archivo actualizado llamado “ARTI_ACTUALIZADO.dat” con la suma del stock remanente
del año anterior más la cantidad producida en el primer trimestre del presente año.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int cod;
    char descrip[31];
    int stock;
}Articulo;
void Cargar_Articulos(Articulo pro[]);
void Ingresar_Datos(int[][12],Articulo[],int[],int,int);
int LEE_CONTROL(int,int);
int Buscar(Articulo[],int,int);
int MAYOR_CERO(int);
void Mostrar_Matriz(int[][12],Articulo[],int,int);
void ListaArtNoprod(Articulo[],int[],int);

int main()
{
    Articulo prod[5];
    int art[5]={0},meses[5][12]={{0}};
    Cargar_Articulos(prod);
    Ingresar_Datos(meses,prod,art,5,12);
    printf("Cod Art\tDescrip\tENE\tFEBR\tMARZ\tABRI\tMAY\tJUN\tJUL\tAGOS\tSEP\tOCT\tNOV\tDIC\n");
    Mostrar_Matriz(meses,prod,5,12);
    printf("\nArticulos que no se producieron en el anio\n");
    ListaArtNoprod(prod,art,5);


}



void Cargar_Articulos(Articulo p[])
{
    Articulo art;
    int i=0;
    FILE*arch=fopen("ARTICULOS.dat","rb");
    if(arch==NULL)
       {
         printf("Error al abrir el archivo\n");
         exit(1);
       }
       fread(&art,sizeof(Articulo),1,arch);
       while(!feof(arch))
       {
           p[i]=art;
           i++;
           fread(&art,sizeof(Articulo),1,arch);
       }
       fclose(arch);
}
void Ingresar_Datos(int m[][12],Articulo v[],int art[],int f,int c)
{
    int i,cod,pos,mes,cant;

    printf("Ingrese numero de mes o '0' para terminar\n");
    mes=LEE_CONTROL(0,12);
    while(mes!=0)
    {
        printf("Ingrese cod del articulo\n");
        cod=LEE_CONTROL(1000,9999);
        pos=Buscar(v,cod,f);
        if(pos!=-1)
        {
            printf("Ingrese cantidad\n");
            cant=MAYOR_CERO(1);
            art[pos]++;
            m[pos][mes-1]=cant;
        }else printf("Codigo no existe\n");

         printf("Ingrese numero de mes o '0' para terminar\n");
         mes=LEE_CONTROL(0,12);

    }

}
int LEE_CONTROL(int lim1,int lim2)
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

int MAYOR_CERO(int mayorcero)
{
    int d;
    do
    {
        scanf("%d",&d);
        if(d<mayorcero)
            printf("Error vuelva a ingresar\n");
    }while(d<mayorcero);
    return d;
}
void Mostrar_Matriz(int m[][12],Articulo v[],int f,int c)
{
    int i,j;

    for(i=0;i<f;i++)
    {
        printf("%d\t%s\t\t",v[i].cod,v[i].descrip);
        for(j=0;j<c;j++)
            {
                printf("%d\t",m[i][j]);
            }
              printf("\n");
    }

}
void ListaArtNoprod(Articulo vp[],int vc[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
    {
        if(vc[i]==0)
        {
           printf("\n%d",vp[i].cod);
        }

    }
}
int Buscar(Articulo v[],int bus,int ce)
{
    int i=0,pos=-1;
    while(i<ce&&pos==-1)
    {
        if(v[i].cod==bus)
        {
            pos=i;
        }else i++;
    }
    return pos;
}
