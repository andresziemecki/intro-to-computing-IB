#include <stdio.h>
#include <stdlib.h>
#include "arbolgen.h"
#include "lista.h"

int main()
{
    ArbolGen_t coco;
    ArbolGen_t pepe;

    coco = CreaArbolGen("coco.txt");
    pepe = CreaArbolGen("pepe.txt");
    printf("El coeficiente de Relacion entre coco y pepe es: %lf\n",CoefRelacion(coco,pepe));

    DestruyeArbolGen(coco);
    DestruyeArbolGen(pepe);
    return 0;
}

