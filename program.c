#include <stdio.h>
#include "cubo.h"

int main(){
    printf("Colores:\n\t%c: amarillo\n\t%c: azul\n\t%c: verde\n\t%c: naranja\n\t%c: blanco\n\t%c: rojo\n", amarillo, azul, verde, naranja, blanco, rojo);
    cubo micubo;
    int check = 0;
    reedCube(&micubo);
    check = checkCube(micubo);
    treenodeV primero;
    primero.actualPosition = micubo;
    primero.numMov = 0;
    for(int i = 0; i < 10; i++) primero.movs[i] = 0;
    treenode(micubo, primero, 'N', 0);
    return 1;
}