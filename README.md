# Trabajo Práctico N°1 :desktop_computer:
Para este trabajo práctico, teniendo en cuenta las consignas, el ejemplo de resolución compartido y aplicando lógicas similares, ustéd podra vislumbrar que el repositorio cuenta con dos archivos principales `funciones.h` y `funciones.c`.

## funciones.h :books:
En la libreria creada van a encontrar las funciones utilizadas por el codigo principal y el tipo de dato articulos_t el cual utilizaremos mas adelante. 
> Todas las funciones utilizadas vinculadas a cadenas de caracteres se encuentran definidas en la librería <string.h>.
  
Yo por mi parte, decidí dividir el código en tres funciones principales:
- Una para que el usuario pueda cargar los articulos, nombrada `void CargarArticulos(articulos_t, int);`.
- Una que imprima la lista de articulos cargados, nombrada `void ImpresionArticulos(articulos_t, int, int []);`.
- Una que los ordene, nombrada `void OrdenarArticulos(articulos_t [], int, int []);`.
  
Como mencioné antes la lógica aplicada en las primeras partes es similar al código ejemplo en la mayoría de pasos, el único cambio realizado fue en el metodo de ordenamiento ya que en vez de BubbleSort utilice un vector paralelo para ordenar en base al total reutilizando la función impresión.
### void CargarArticulos(articulos_t, int);
```
void CargarArticulos(articulos_t art[], int cant){
    int opc = 0, i,sucursal,index;
    char articulo[90];
    printf("Bienvendio al final de Info 1\n\n");

    do{
        printf("Ingrese el nombre del articulo: ");
        scanf("%s", articulo);

        i=0;
        while (art[i].descripcion[0] && strcmp(articulo, art[i].descripcion) && i < cant) i++;
        index = i;
        strcpy(art[index].descripcion, articulo);

        printf("\nArticulo a cargar: %s | Indice: %d", art[index].descripcion, index+1);

        printf("\nPara que sucursal va a realizar la carga? (1,2,3)\n");
        scanf("%d", &sucursal);
        printf("\nIngrese la cantidad a cargar: ");
        scanf("%d", &art[index].cantidad_sucursal[sucursal-1]);

        art[index].total = 0;
        for(i=0; i<3; i++) art[index].total += art[index].cantidad_sucursal[i];
        printf("\nTotal de unidades del articulo %s en todas las sucursales: %d\n", art[index].descripcion, art[index].total);

        printf("\nDesea cargar otro articulo? (1-Si, 0-No)\n");
        scanf("%d", &opc);

    }while(opc==1);
}
```
### void ImpresionArticulos(articulos_t, int, int []);
```
void ImpresionArticulos(articulos_t art[], int cant, int orden[]){
    int i=0;
    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while(i< cant && art[orden[i]].descripcion[0]){
        printf("%s\t%d\t%d\t%d\t%d\n", art[orden[i]].descripcion, art[orden[i]].cantidad_sucursal[SUCURSAL_1], art[orden[i]].cantidad_sucursal[SUCURSAL_2], art[orden[i]].cantidad_sucursal[SUCURSAL_3],art[orden[i]].total);
        i++;
    }
}
```
### void OrdenarArticulos(articulos_t [], int, int []);
```
void OrdenarArticulos(articulos_t art[], int cant, int orden[]){
    int i, j, aux;

    for(i=1; i<cant; i++){
        for(j=0; j<cant-1; j++){
            if(art[orden[j]].total < art[orden[i]].total){
                aux = orden[j];
                orden[j] = orden[i];
                orden[i] = aux;
            }
        }
    }

    printf("\n###################################");
    printf("\n##############ORDENADO#############");
    printf("\n###################################\n\n");
}
```
## funciones.c :bulb:
En el código principal incluí las mismas librerias utilizadas en funciones.h y la mencionada, además definí la variable global `#DEFINE CANT_ARTICULOS 60` la cual nos permite, en caso de que la cantidad de articulos varie, no tener que reemplazar los nuevos valores término por término en la función. El main() no se anda con rodeos, define las variables principales y ejecuta las tres funciones importadas desde `"funciones.h"`. Lo único a explicar es lo mencionado anteriormente, que es el tipo de dato que utilizamos como vector de estructuras `articulos_t` y como funciona el vector entero `orden[]`.
### articulo_t
Es un tipo de dato de estructuras el cual utilizamos para definir las partes de nuestro articulo, contamos con una componente char que nos indica su nombre, con un vector de tipo entero de tres espacios el cual nos indica cantidad de ese articulo por sucursal, y una componente entera que representa la suma del mismo articulo en las tres sucursales.
```
typedef struct {
    char descripcion[90]; //Nombre del artículo
    int cantidad_sucursal[3]; // Cantidad de unidades por sucursal
    int total; // Total de unidades en las 3 sucursales
}articulos_t;
```
> Su definición la encontrarán en funciones.h, en el main lo utilizaremos de la siguiente manera ---> `articulos_t art[CANT_ARTICULOS] = {0};`
### orden[]
Es un vector de caracter entero, cada parte de este cuenta con un dato que es equivalente a la posición en la que se encuentra. Con esto en mente es facil darse cuenta que orden[0] = 0; orden[1] = 1; ... ; orden[n] = n. En este caso el main inicializa cada dato con la siguiente línea:
```
int orden[CANT_ARTICULOS] = {0}, i = 0;
while(orden[i]==0 && i < CANT_ARTICULOS) orden[i++] = i-1;
```
Este vector lo utilizaremos en la función ImpresiónArticulos y OrdenarArticulos.
