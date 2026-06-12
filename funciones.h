#include <stdio.h>
#include <string.h>

#define SUCURSAL_1 0
#define SUCURSAL_2 1
#define SUCURSAL_3 2
#define CANT_ARTICULOS 60

typedef struct {
    char descripcion[90]; //Nombre del artículo
    int cantidad_sucursal[3]; // Cantidad de unidades por sucursal
    int total; // Total de unidades en las 3 sucursales
}articulos_t;

void CargarArticulos(articulos_t *art, int cant);
void ImpresionArticulos(articulos_t *art, int cant, int *orden);
void OrdenarArticulos(articulos_t *art, int cant, int *orden);