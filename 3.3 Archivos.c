/*Se desea realizar un programa que permita actualizar la lista de precios de una empresa en forma individual
a cada uno de sus productos.
La empresa trabaja con a lo sumo 100 productos que están guardados en el archivo productos.dat con la
siguiente estructura:
• Código (entero)
• Precio (float)
• Descripción (de hasta 50 caracteres)
Para modificar un precio se ingresa por teclado el código del producto y el nuevo precio. La modificación
de precios finaliza con un código de producto igual a 0.
Al finalizar:
a. Actualizar el archivo de productos con los nuevos precios
b. Exportar a un archivo con formato de texto (.csv) para que la lista de precios pueda ser visualizada
directamente utilizando un programa de planillas de cálculo como por ejemplo el Excel.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int codigo;
    float precio;
    char descripcion[51];
}PRODUCTO;
int CARGAR_PRODUCTO();
void Nuevos_precios(PRODUCTO[],int);
void Actualizar_Archivo(PRODUCTO[],int);
int Buscar(PRODUCTO[],int,int);
void exportar(PRODUCTO[],int);

int main()
{
    PRODUCTO prod[100];
    int cant;
    cant=CARGAR_PRODUCTO(prod,100);
    Nuevos_precios(prod,cant);
    Actualizar_Archivo(prod,cant);
    exportar(prod,cant);

}
int CARGAR_PRODUCTO(PRODUCTO p[],int ce)
{
    PRODUCTO prod;
    int i=0;
    FILE*arch;
    arch=fopen("PRODUCTOS.dat","rb");
    if(arch==NULL)
    {
        printf("Error no se pudo abrir archivo.");
        exit(2);
    }
    fread(&prod,sizeof(PRODUCTO),1,arch);
    while(!feof(arch))
    {
        p[i]=prod;
        i++;
        fread(&prod,sizeof(PRODUCTO),1,arch);
    }
    fclose(arch);
    return i;
}

void Nuevos_precios(PRODUCTO p[],int ce)
{
    int cod,precio,pos;
    float nprecio;
    printf("Ingrese codigo del producto o '0' para terminar\n");
    scanf("%d",&cod);
    while(cod!=0)
    {
      pos=Buscar(p,cod,ce);
      if(pos!=-1)
      {
          printf("Ingrese nuevo precio\n");
          scanf("%f",&nprecio);
          p[pos].precio=nprecio;
      }else
      {
          printf("Codigo no existe vuelva a ingresar\n");
      }
      printf("Ingrese codigo del producto o '0' para terminar\n");
      scanf("%d",&cod);
    }

}

void Actualizar_Archivo(PRODUCTO p[],int ce)
{
    FILE*arch;
    arch=fopen("PRODUCTOS.dat","wb");
    if(arch==NULL)
    {
        printf("Error al abrir archivo.");
        exit(1);
    }
    fwrite(&p,sizeof(PRODUCTO),ce,arch);
    fclose(arch);
}
int Buscar(PRODUCTO p[],int bus,int ce)
{
    int i=0,pos=-1;
    while(i<ce&&pos==-1)
    {
        if(p[i].codigo==bus)
        {
            pos=i;
        }else i++;
    }
    return pos;
}
void exportar(PRODUCTO p[],int ce)
{
    FILE*a;
    a=fopen("PRODUCTOS.csv","wt");
    if(a==NULL)
    {
         printf("Error no se puede abrir archivo\n");
         exit(2);
    }
    int i;
    for(i=0;i<ce;i++)
        fprintf(a,"%d;%.2f;%s\n",p[i].codigo,p[i].precio,p[i].descripcion);
    fclose(a);
}
