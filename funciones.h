#include <stdio.h>
#include <string.h>

#define SUCURSAL_1 0
#define SUCURSAL_2 1
#define SUCURSAL_3 2

typedef struct {
    char descripcion[90]; //Nombre del artículo
    int cantidad_sucursal[3]; // Cantidad de unidades por sucursal
    int total; // Total de unidades en las 3 sucursales
}articulos_t;

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

void ImpresionArticulos(articulos_t art[], int cant, int orden[]){
    int i=0;
    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while(i< cant && art[orden[i]].descripcion[0]){
        printf("%s\t%d\t%d\t%d\t%d\n", art[orden[i]].descripcion, art[orden[i]].cantidad_sucursal[SUCURSAL_1], art[orden[i]].cantidad_sucursal[SUCURSAL_2], art[orden[i]].cantidad_sucursal[SUCURSAL_3],art[orden[i]].total);
        i++;
    }
}

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
