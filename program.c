#include <stdio.h>
#include "cubo.h"

int main(){
    printf("Colores:\n\t%c: amarillo\n\t%c: azul\n\t%c: verde\n\t%c: naranja\n\t%c: blanco\n\t%c: rojo\n", amarillo, azul, verde, naranja, blanco, rojo);
    cubo micubo;
    
    reedCube(&micubo);
    B(&micubo);
    writeCube(micubo);

    return 1;
}

