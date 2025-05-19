#include <stdio.h>
#include "cubo.h"

int main(){
    printf("Colores:\n\t%c: amarillo\n\t%c: azul\n\t%c: verde\n\t%c: naranja\n\t%c: blanco\n\t%c: rojo\n", amarillo, azul, verde, naranja, blanco, rojo);
    cubo micubo;
    char c;

    printf("Pon una cara del cubo\n");
    reedFace(&micubo.frontal);
    printf("Giralo a la derecha y pon esa cara\n");
    reedFace(&micubo.derecha);
    printf("Giralo a la derecha y pon esa cara\n");
    reedFace(&micubo.detras);
    printf("Giralo a la derecha y pon esa cara\n");
    reedFace(&micubo.izquierda);
    printf("Giralo hacia arriba y pon esa cara\n");
    reedFace(&micubo.arriba);
    printf("Ahora pon la cara restante\n");
    reedFace(&micubo.abajo);
    
}