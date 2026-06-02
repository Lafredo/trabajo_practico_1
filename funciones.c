#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define CANT_ARTICULOS 60

int main(){
    articulos_t art[CANT_ARTICULOS] = {0};
    int orden[CANT_ARTICULOS] = {0}, i = 0;

    while(orden[i]==0 && i < CANT_ARTICULOS) orden[i++] = i-1;

    CargarArticulos(art, CANT_ARTICULOS);
    ImpresionArticulos(art, CANT_ARTICULOS, orden);
    OrdenarArticulos(art, CANT_ARTICULOS, orden);
    ImpresionArticulos(art, CANT_ARTICULOS, orden);

    return 0;
}
