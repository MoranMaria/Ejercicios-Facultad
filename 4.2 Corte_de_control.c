/*Se dispone de un archivo con las ventas del mes de cada una de las sucursales de una empresa. El archivo se
encuentra ordenado por sucursal y contiene la siguiente estructura:
• Sucursal (15 caracteres máximo)
• Código de producto (entero)
• Cantidad (entero)
Por otro lado, se dispone de un archivo de los productos que vende la empresa y el estado del stock al mes
pasado con la siguiente estructura:
• Código de producto (entero)
• Descripción (20 caracteres máximo)
• Precio (float)
• Stock (entero)
• Punto de pedido (entero)
• Cantidad para pedido (entero)
No se sabe la cantidad exacta de productos, pero sí se sabe que no hay más de 200. Se desea:
a. Mostrar el importe total vendido en cada sucursal.
b. Mostrar la recaudación total de la empresa en el mes.
c. Determinar la sucursal que vendió mayor cantidad de productos.
d. Actualizar el archivo de productos con el nuevo stock.
e. Realizar un archivo llamado pedidos.dat que incluya aquellos productos que deben solicitarse
(código y cantidad) de aquellos productos que al finalizar de procesar las ventas del mes queden
con stock menor al punto de pedido.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char Sucursal[16];
    int codProd;
    int cantidad;
}Ventasdelmes;

typedef struct
{
    int codProd;
    char descripcion[21];
    float Precio;
    int Stock;
    int Punto_de_pedido;
    int cant_de_pedido;
}Stockdelmes;
typedef struct
{
    int cod;
    int cant;
}Pedidos;

int Cargar_Stock(Stockdelmes[],int);
int Buscar(Ventasdelmes,Stockdelmes[],int);
void Actualizar_Stock(Stockdelmes[],int);

int main()
{
    Ventasdelmes v;
    Stockdelmes st[200];
    Pedidos ped;
    char Msucur[16],Sucursal[16];
    float impSuc,impMes=0;
    int cantProd,Mayorcant,cant,band=0,pos;
    cantProd=Cargar_Stock(st,200);
    FILE*vent,*pedidos;
    vent=fopen("ventasdelmes.dat","rb");
    pedidos=fopen("pedidos.dat","wb");

    if(vent==NULL||pedidos==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(1);
    }
    fread(&v,sizeof(Ventasdelmes),1,vent);

    while(!feof(vent))
    {
        strcpy(Sucursal,v.Sucursal);
        cant=0;
        impSuc=0;
        while(!feof(vent)&&strcmpi(Sucursal,v.Sucursal)==0)
        {
            pos=Buscar(v,st,cantProd);
            impSuc+=v.cantidad*st[pos].Precio;
            cant+=v.cantidad;
            st[pos].Stock=st[pos].Stock-v.cantidad;
            if(st[pos].Stock<st[pos].Punto_de_pedido)
            {
                ped.cant=st[pos].cant_de_pedido;
                ped.cod=st[pos].codProd;
                fwrite(&ped,sizeof(Pedidos),1,pedidos);
            }
            fread(&v,sizeof(Ventasdelmes),1,vent);
        }
        printf("La Sucursal %s vendio %.2f\n",Sucursal,impSuc);//PUNTO A
        if(band==0||cant>Mayorcant)
        {
            strcpy(Msucur,Sucursal);
            Mayorcant=cant;
            band=1;
        }
        impMes+=impSuc;


    }
    Actualizar_Stock(st,cantProd);//PUNTO D
    printf("\nLa empresa vendio en total %.2f\n",impMes);//PUNTO B
    printf("Vendio la mayor cantidad de productos la Sucursal %s\n",Msucur);//PUNTO C
    fclose(vent);
    fclose(pedidos);
}

int Cargar_Stock(Stockdelmes vs[],int ce)
{
    Stockdelmes s;
    int i=0;
    FILE*stock=fopen("productosdelmes.dat","rb");

    if(stock==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(2);
    }

    fread(&s,sizeof(Stockdelmes),1,stock);

    while(!feof(stock))
    {
        vs[i]=s;
        i++;
        fread(&s,sizeof(Stockdelmes),1,stock);

    }
    fclose(stock);

    return i;
}
int Buscar(Ventasdelmes vent,Stockdelmes vst[],int ce)
{
    int pos=-1,i=0;

    while(i<ce&&pos==-1)
    {
        if(vent.codProd==vst[i].codProd)
        {
            pos=i;
        }else i++;
    }
    return pos;
}
void Actualizar_Stock(Stockdelmes st[],int ce)
{
    FILE*stock=fopen("productosdelmes.dat","wb");

    if(stock==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(2);
    }

    fwrite(&st,sizeof(Stockdelmes),ce,stock);
    fclose(stock);
}
