/*Realizar un programa que permite actualizar una lista de precios en forma masiva, ingresando un porcentaje
de incremento. El archivo original se llama precios.dat y fue generado utilizando la siguiente estructura:
• Código (entero)
• Precio (float)
• Descripción (de hasta 50 caracteres)
No se sabe la cantidad de registros del archivo.
Se solicita generar un nuevo archivo llamado Precios_actualizados.dat.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int codigo;
    float precio;
    char descripcion[51];
}Producto;
void Cargar(Producto);
void Actualizar_precios(Producto,float);


int main()
{
    Producto p;
    int cant;
    float aumento;
    Cargar(p);
    aumento=1.10;
    Actualizar_precios(p,aumento);
    return 0;
}

void Cargar(Producto p)
{
    FILE*arch,*narch;
    int i=0;
    arch=fopen("PRECIOS.dat","rb");
    narch=fopen("Precios_actualizados.dat","wb");
    if(arch==NULL||narch==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(1);
    }
    fread(&p,sizeof(Producto),1,arch);
    while(!feof(arch))
    {
     fwrite(&p,sizeof(Producto),1,narch);
     fread(&p,sizeof(Producto),1,arch);
    }
    fclose(arch);
    fclose(narch);
}
void Actualizar_precios(Producto p,float aum)
{
    FILE*a;
    a=fopen("Precios_actualizados.dat","rb");
    if(a==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(2);
    }
    fread(&p,sizeof(p),1,a);
    while(!feof(a))
    {
        p.precio*aum;
        fread(&p,sizeof(p),1,a);
    }
    fclose(a);
}
