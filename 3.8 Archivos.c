/*Se dispone de un archivo denominado INSCRIPTOS.dat que contiene la información de los inscriptos a un
curso de programación. El curso tiene una capacidad máxima para 60 personas. El archivo aún no está
completo ya que la inscripción se realiza por partes. Por cada inscripto se tiene la siguiente información:
• DNI (entero)
• Apellido y Nombres (texto de 20 caracteres máximo)
• Pagado (campo entero donde 1 indica que pagó y 0 que aún adeuda la matrícula)
Se desea realizar un programa que cumpla con dos funciones:
a. Registrar los pagos de los alumnos ya inscriptos.
b. SI hay cupo, agregar nuevos inscriptos.
Guía Práctica – V1.0 4 / 8
El programa solicitará el ingreso del DNI y lo buscará entre los inscriptos, en caso de que lo encuentre dará
la opción para registrar el pago (si es que no está pago ya). En caso de que no lo encuentre dará la opción
para inscribirlo al curso (el pago se realiza luego). En el momento que ya no quede cupo en el curso si llega
un nuevo inscripto se le preguntará si desea quedar registrado para un curso futuro, y en caso afirmativo
se le solicitará el teléfono y se guardará el nombre, DNI y teléfono en un archivo Interesados.dat.
El ingreso de datos finaliza con un DNI negativo. 2
Al finalizar se debe actualizar el archivo de inscriptos con los cambios realizados.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int dni;
    char NomApe[21];
    int Pagado;
}Alumnos;
typedef struct
{
    char Nombre[21];
    int dni;
    int telefono;
}INTERESADOS;
void COPIAR_INSCRIPTOS(Alumnos[]);
void Registro(Alumnos[],int);
int IngreseDatoVal(int,int,int);
int Buscar(Alumnos[],int,int);
void CargaDeInteresados();
int DatoValido(int ,int );
int BuscarCupos(Alumnos[],int);
char DatoVal();
void Actualizar_inscriptos(Alumnos[],int);

int main()
{
	Alumnos alum[60]={0};
    FILE*arch=fopen("Interesados.dat","wb");
    if(arch==NULL)
    {
        printf("Error al abrir el archivo primero.");
        exit(1);
    }
    fclose(arch);



    COPIAR_INSCRIPTOS(alum);
    Registro(alum,60);
    Actualizar_inscriptos(alum,60);


}
void COPIAR_INSCRIPTOS(Alumnos al[])
{
    Alumnos info;
    int i=0;
    FILE*incr=fopen("INSCRIPTOS.dat","rb");
    if(incr==NULL)
    {
        printf("Error al abrir el archivo segundo.");
        exit(1);
    }
    fread(&info,sizeof(Alumnos),1,incr);
    while(!feof(incr))
    {
        al[i]=info;
        i++;
        fread(&info,sizeof(Alumnos),1,incr);
    }


    fclose(incr);
}
void Registro(Alumnos al[],int ce)
{
    int dni,i=0,pos,cupo;
    char registro;
    printf("Ingrese dni o negativo para terminar\n");
    dni=IngreseDatoVal(10000000,99999999,0);

    while(dni>0)
    {
        pos=Buscar(al,dni,ce);
        if(pos==-1)
        {
           cupo=BuscarCupos(al,ce);
           if(cupo==-1)
           {
               printf("No hay mas cupo, quisiera quedar registradoen un curso futuro? s(si) n(no)\n");
               registro=DatoVal();
               fflush(stdin);
               if(registro=='s'||registro=='S')
               {
                 CargaDeInteresados();
               }
           }else {
           printf("Desea inscribirse? s(si) n(no) \n");
           registro=DatoVal();
           if (registro=='s'||registro=='S')
           {
               al[cupo].dni=dni;
               printf("Ingrese nombre y apellido\n");
               fflush(stdin);
               gets(al[cupo].NomApe);
           }

        }}else{
               if(al[pos].Pagado==0)
        {
            printf("Quisiera registrar el pago? s(si) n(no) \n");
            registro=DatoVal();
            if(registro=='s'||registro=='S')
            al[pos].Pagado=1;
         }else printf("Ya esta pago\n");
        printf("Ingrese dni o negativo para terminar\n");
        dni=IngreseDatoVal(10000000,99999999,0);
    }
}

}
int IngreseDatoVal(int lim1,int lim2,int negativo)
{
    int d;
    do
    {
        scanf("%d",&d);
        if((d<lim1||d>lim2)&&d>negativo)
            printf("Dato incorrecto vuelva a ingresar\n");
    }while((d<lim1||d>lim2)&&d>negativo);
    return d;
}

int Buscar(Alumnos al[],int bus,int ce)
{
    int i=0,pos=-1;
    while(i<ce&&pos==-1)
    {
        if(al[i].dni==bus)
        {
            pos=i;
        }else i++;
    }
    return pos;
}
void CargaDeInteresados()
{
    INTERESADOS alum;
    printf("Ingrese Nombre y Apellido\n");
    gets(alum.Nombre);
    fflush(stdin);
    printf("Ingrese dni\n");
    alum.dni=DatoValido(10000000,99999999);
    printf("Ingrese Numero de telefono\n");
    alum.telefono=DatoValido(10000000,999999999);

    FILE*arch=fopen("Interesados.dat","ab");
    if(arch==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(4);
    }
    fwrite(&alum,sizeof(INTERESADOS),1,arch);
    fclose(arch);
}
int DatoValido(int lim1,int lim2)
{
    int d;
    do
    {
        scanf("%d",&d);
        if(d<lim1||d>lim2)
            printf("Dato incorrecto vuelva a ingresar\n");
    }while(d>lim1||d>lim2);
    return d;
}
int BuscarCupos(Alumnos al[],int ce)
{
    int i=0,cupo=-1;
    while(i<ce&&cupo==-1)
    {
        if( al[i].dni==0)
        {
            cupo=i;
        }else i++;
    }
    return cupo;

}
char DatoVal()
{
    char d;
 do
 {
    fflush(stdin);
    scanf("%c",&d);

    if(d!='s'&&d!='S'&&d!='n'&&d!='N')
        printf("Opcion incorrecta vuelva a ingresar\n");
 }while(d!='s'&&d!='S'&&d!='n'&&d!='N');
 return d;
}
void Actualizar_inscriptos(Alumnos alum[],int ce)
{
    FILE*arch=fopen("INSCRIPTOS.dat","wb");
    if(arch==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(1);
    }
    fwrite(alum,sizeof(Alumnos),ce,arch);

    fclose(arch);
}
