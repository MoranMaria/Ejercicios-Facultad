/*5.1 Se dispone del archivo binario PRECIOS.DAT con datos de productos seg�n la siguiente estructura:
� C�digo de Producto (entero)
� Descripci�n (texto de 20 caracteres m�ximo)
� Precio (float)
Realizar un programa que permita modificar el precio y/o la descripci�n de productos dado su c�digo.
El programa debe permitir modificar varios precios finalizando con un c�digo de producto igual a 0.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int cod;
    char descripcion[21];
    float precio;
}Productos;

int main()
{
    Productos prod;
    int codigo;
    float nuevoprecio;
    FILE*arch=fopen("precios2.dat","r+b");
    if(arch==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(1);
    }
    printf("Ingrese codigo que quiere modificar o '0' para terminar\n");
    scanf("%d",&codigo);
    while(codigo!=0)
    {
    printf("Ingrese nuevo precio\n");
    scanf("%f",&nuevoprecio);
    fseek(arch,0,SEEK_SET);
    fread(&prod,sizeof(Productos),1,arch);
    while(!feof(arch)&&prod.cod!=codigo)
    fread(&prod,sizeof(Productos),1,arch);

    if(!feof(arch))
    {
        prod.precio=nuevoprecio;
        fseek(arch,-sizeof(Productos),SEEK_CUR);
        fwrite(&prod,sizeof(Productos),1,arch);
        fflush(arch);
    }else printf("Codigo no encontrado\n");

    printf("Ingrese codigo que quiere modificar o '0' para terminar\n");
    scanf("%d",&codigo);
    }
    fclose(arch);
}
