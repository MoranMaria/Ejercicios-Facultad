/*Realizar un programa que tome el archivo Faltantes.dat del ejercicio anterior y unifique las cantidades
sumari�ndolas por art�culo (la empresa trabaja con 10 art�culos en total, pero no todos pueden estar en
falta). Generar una planilla Excel para enviar al proveedor con el pedido a realizar. Para ello se debe crear un
nuevo archivo llamado pedido.csv que contenga los registros por art�culo conteniendo:
� C�digo de art�culo (entero)
� Cantidad (entero)*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cod;
    int cant;
}FALTANTES;
int main()
{
    FALTANTES f;
    FILE*falt,*ped;
    falt=fopen("faltantes.dat","rb");
    ped=fopen("pedido.csv","wt");
    if(falt==NULL||ped==NULL)
    {
        printf("Error al abrir archivo.");
        exit(1);
    }
    fprintf(ped,"codigo;cantidad\n");

    fread(&f,sizeof(FALTANTES),1,falt);
    while(!feof(falt))
    {
        if(f.cant!=0)
        {

           fprintf(ped,"%d;%d\n",f.cod,f.cant);
        }

        fread(&f,sizeof(FALTANTES),1,falt);
    }

    fclose(falt);
    fclose(ped);
    return 0;
}
