/*Se dispone de un archivo llamado Rating.dat que guarda la información de los puntos obtenidos de rating en
los distintos programas de canales de cable a lo largo del día. Cada registro contiene:
• Número de canal (entero)
• Programa (texto de 35 caracteres máximo)
• Rating (float)
El archivo se encuentra ordenado por canal.
Se solicita informar:
a. Aquellos canales que obtengan menos de 15 puntos en total.
b. El canal más visto.
c. Generar un archivo con el promedio de rating de cada canal que incluya dos campos:
• Número de canal.
• Promedio.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int NroCanal;
    char Programa[36];
    float Rating;
}Programas;

typedef struct
{
    int Nrocanal;
    float Prom;
}Promedio;

int main()
{
    int cont,mayor,masvisto,band=0;
    float acum;
    Programas pro;
    Promedio p;
    FILE*arch,*promc;
    arch=fopen("Rating.dat","rb");
    promc=fopen("PromediosdeRating.dat","wb");
    if (arch==NULL||promc==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(2);
    }
    fread(&pro,sizeof(Programas),1,arch);
    while(!feof(arch))
    {
        p.Nrocanal=pro.NroCanal;
        cont=0;
        acum=0;
        do
        {
            cont++;
            acum+=pro.Rating;
            fread(&pro,sizeof(Programas),1,arch);
        }while(!feof(arch)&&pro.NroCanal==p.Nrocanal);
        if(acum<15)
        {
            printf("El canal %d obtuvo menos de 15 puntos de raiting\n",p.Nrocanal);
        }
        if(band==0||acum>mayor)
        {
            masvisto=p.Nrocanal;
            mayor=acum;
            band=1;
        }
        p.Prom=acum/cont;
        fwrite(&p,sizeof(Promedio),1,promc);
    }
    printf("El canal mas visto fue %d",masvisto);
    fclose(arch);
}

