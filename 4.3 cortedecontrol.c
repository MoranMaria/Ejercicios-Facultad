/* Se dispone de un archivo con nombre Llamadas.dat que contiene llamadas telefónicas realizadas en una
empresa. Por cada llamada se dispone de la siguiente información:
• Sector (15 caracteres máximo)
• Duración en segundos (entero)
• Tipo de llamada (entero: 1 local, 2 larga distancia, 3 celular)
El archivo se encuentra organizado por Sector. Se solicita:
a. Calcular y mostrar por cada sector, la cantidad de llamadas realizadas de cada tipo.
b. Determinar cuál es el sector que habló la mayor cantidad de tiempo.
c. En un archivo llamado costos.dat hay un único registro que contiene los costos por segundo de los
tres tipos de llamadas (3 float). Se debe generar el archivo gastos.dat que totalice los gastos de
llamadas de cada sector.
d. Realizar una función que muestre los datos almacenados en gastos.dat en forma de listado.
Guía Práctica – V1.0 3 / 5
e. Generar un archivo para cada sector con el detalle de llamadas valorizado. El archivo se debe
generar con nombresector.dat y debe contener:
• Duración en segundos (entero)
• Tipo de llamada (entero)
• Costo de la llamada (float)


FALTA PUNTO E
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char sector[16];
    int duracion;
    int tipollamada;
}Llamadas;
typedef struct
{
    float local;
    float largadis;
    float celular;
}Costos;
typedef struct
{
    char sector[16];
    float gastos;
}gastos;
void Mostrar_gastos();

int main()
{
    Llamadas llam;
   Costos c;
    gastos g;

    char sector[16],Msector[16];
    int local,largad,celular,tiempo,Mtiempo,band=0;
    FILE*arch,*costos,*gast;
    arch=fopen("LLAMADAS.dat","rb");
    costos=fopen("COSTOS.dat","rb");
    gast=fopen("GASTOS.dat","wb");
    if(arch==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(1);
    }
    fread(&llam,sizeof(Llamadas),1,arch);
    fread(&c,sizeof(Costos),1,costos);
    while(!feof(arch))
    {
        strcpy(sector,llam.sector);
        local=0;
        largad=0;
        celular=0;
        tiempo=0;
        while(strcmpi(sector,llam.sector)==0&&!feof(arch))
        {
            if(llam.tipollamada==1)
            {
                local++;
            }else if(llam.tipollamada==2)
            {
                largad++;
            }else
            {
                celular++;
            }


            tiempo+=llam.duracion;
            fread(&llam,sizeof(Llamadas),1,arch);
        }
        strcpy(g.sector,sector);
        g.gastos=local*c.local+largad*c.largadis+celular*c.celular;

        fwrite(&g,sizeof(gastos),1,gast);

        printf("En el sector %s hubo %d llamada local, %d llamada de larga distancia y %d de celulares\n",sector,local,largad,celular);
        if(band==0||Mtiempo<tiempo)
        {
            strcpy(Msector,sector);
            Mtiempo=tiempo;
            band=1;
        }

    }
    printf("\nEl sector que hablo la mayor cantidad de tiempo fue %s\n",Msector);

    fclose(arch);
    fclose(costos);
    fclose(gast);
    Mostrar_gastos();
}
void Mostrar_gastos()
{
    FILE*arch;
    gastos g;
    arch=fopen("GASTOS.dat","rb");
    if(arch==NULL)
    {
        printf("Error al abrir archivo de gastos.");
        exit(1);
    }
    fread(&g,sizeof(gastos),1,arch);
    printf("SECTOR\tGASTO TOTAL\n");
    while(!feof(arch))
    {
        printf("%s\t%.2f\n",g.sector,g.gastos);
        fread(&g,sizeof(gastos),1,arch);
    }
    fclose(arch);
}
