 Realizar un sistema completo de agenda telefónica básico donde por cada contacto se guarda el nombre y el
número de teléfono. Las funcionalidades a desarrollar son:
• Mostrar la cantidad de contactos guardados
• Alta de nuevos contactos
• Búsqueda secuencial de contactos por nombre
• Modificación de contactos
• Borrado de contactos (a elección si desea realizar borrado físico o lógico)
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    char Nombre[17];
    int Nrotelefono;
}Contacto;
char Datoval(char,char);
int main()
{
    Contacto contac;
    int cont=0,tel=-1;
    char SIoNO;
    char Nombus[17];
    FILE*arch=fopen("Agenda.dat","r+b");
    if(arch==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(2);
    }
    printf("Desea agregar un contacto 'S'(SI) 'N'(NO)\n");
    SIoNO=Datoval(s,n);

    while(SIoNO=='S')
    {
        printf("Ingrese Nombre\n");
        scanf("%s",&contac.Nombre);
        printf("Ingrese Numero de telefono\n");
        scanf("%d",&contac.Nrotelefono);
        fwrite(&contac,sizeof(Contacto),1,arch);
        printf("Desea agregar un contacto 'S'(SI) 'N'(NO)\n");
        SIoNO=Datoval(s,n);
    }
    fflush(arch);
    printf("Desea Buscar un contacto'S'(SI) 'N'(NO)\n");
    SIoNO=Datoval(s,n);
    while(SIoNO=='S')
    {
        printf("Ingrese Nombre que desea buscar\n");
        scanf("%s",Nombus);
        tel=BuscarContacto(Nombus);
        if(tel!=-1)
        {
            printf("Numero de Telefono %d\n",tel);

        }else printf("No se encontro");
        printf("Desea Buscar un contacto'S'(SI) 'N'(NO)\n");
        SIoNO=Datoval(s,n);
    }
    fread(&contac,sizeof(Contacto),1,arch);
    while(!feof(arch))
    {
        cont++;
        fread(&contac,sizeof(Contacto),1,arch);
    }
    printf("La cantidad de contactos guardados es %d\n",cont);
}
char Datoval(char si, char no)
{
    char d;
    do
    {
        scanf("%c",&d);
        d=toupper(d);
        if(d!=si&&d!=no)
            prinf("Opcion incorrecta vuelva a ingresar\n");
    }while(d!=si&&d!=no);
    return d;
}
