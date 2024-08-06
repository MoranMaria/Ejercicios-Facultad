 /*La empresa RED VIAL S.A. desea controlar el flujo vehicular en sus cabinas de peaje a lo largo del mes. Para
ello se debe procesar la información provista por las barreras que se encuentra almacenada en el archivo
barreras.dat que contiene la siguiente información:
• Día (entero)
• Hora (0 a 24)
• Número de barrera (entero)
Dentro del archivo la información se encuentra ordenada por día y hora. Determinar:
a. La cantidad de vehículos por cada hora.
b. La cantidad de vehículos de cada día.
c. Ingresar por teclado los precios del peaje para horario normal y horario pico (de 7 a 11 y de 17 a
19). Con esos valores guardar un archivo con la recaudación de cada día.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int dia;
    int hora;
    int nrobarrera;
}Barreras;
typedef struct
{
    int dia;
    float recaud;
}Rec;
float Mayor_a_cero(int);

int main()
{
    Barreras bar;
    Rec narch;
    int canthora,cantdia,dia,hora;
    float normal, pico;
    FILE*arch,*rec;
    arch=fopen("barreras.dat","rb");
    rec=fopen("RECAUDACION.dat","wb");
    if(arch==NULL||rec==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(2);
    }
    printf("Ingresar valor de horario normal\t");
    normal=Mayor_a_cero(0);
    printf("\nIngresar valor de horario pico\t");
    pico=Mayor_a_cero(0);
    fread(&bar,sizeof(Barreras),1,arch);
    while(!feof(arch))
    {
        cantdia=0;
        dia=bar.dia;
        narch.dia=dia;
        narch.recaud=0;
        while(dia==bar.dia&&!feof(arch))
        {
            canthora=0;
            hora=bar.hora;
            while(hora==bar.hora&&!feof(arch))
            {
                if(hora>=7&&hora<=11||hora>=17&&hora<=19)
                {
                    narch.recaud+=pico;
                }else
                {
                    narch.recaud+=normal;
                }
                cantdia++;
                canthora++;
                fread(&bar,sizeof(Barreras),1,arch);
            }

            printf("DIA: %d HORA: %d  CANTIDAD VEHICULOS: %d\n",dia,hora,canthora);
        }
        fwrite(&narch,sizeof(Rec),1,rec);
        printf("\nDIA: %d CANTIDAD TOTAL DE VEHICULOS %d\n\n",dia,cantdia);

    }

    fclose(arch);
    fclose(rec);

}

float Mayor_a_cero(int cero)
{
    float d;
    do
    {
        scanf("%f",&d);
        if(d<=cero)
        {
            printf("Error vuelva a ingresar.\n");
        }
    }while(d<=cero);
    return d;
}
