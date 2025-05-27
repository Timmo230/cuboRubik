#include <stdio.h>
#include "cubo.h"

void  reedFace(cara *estaCara){
    int c;
    for(int i = 0; i < 9; i++){
        c = getchar();
        getchar();
        estaCara->color[i] = c;
    }
}

void reedCube(cubo *micubo){
    printf("Pon una cara del cubo\n");
    reedFace(&micubo->caras[frontal]);     
    printf("Giralo a la derecha y pon esa cara\n");
    reedFace(&micubo->caras[derecha]);     
    printf("Giralo a la derecha y pon esa cara\n");
    reedFace(&micubo->caras[detras]);      
    printf("Giralo a la derecha y pon esa cara\n");
    reedFace(&micubo->caras[izquierda]);   
    printf("Giralo hacia arriba y pon esa cara\n");
    reedFace(&micubo->caras[arriba]);
    printf("Ahora pon la cara restante\n");
    reedFace(&micubo->caras[abajo]);
    printf("\n\n");
}

void writeCube(cubo micubo){
    for(int i = frontal; i<6; i++){
        writeFace(micubo.caras[i]);
    }
}

void writeFace(cara lacara){
    for(int i = 0; i < 9; i++){
        printf("%c ", lacara.color[i]);

        if(i == 2 || i == 5 || i == 8) printf("\n");
    }

    printf("\n\n");
}

int checkCube(cubo micubo){
    int a, A, r, b, n, v;
    char c;
    for(int i = 0;i < 9; i++){
        c = micubo.caras[frontal].color[i];

    }

}

void R(cubo *micubo){
    cubo copia = *micubo;

    //Todas las caras menos la derecha
    for(int i = 2; i<9; i = i+3){
        micubo->caras[frontal].color[i] = copia.caras[abajo].color[i];
        micubo->caras[arriba].color[i] = copia.caras[frontal].color[i];
    }
    micubo->caras[detras].color[0] = copia.caras[arriba].color[8];
    micubo->caras[detras].color[3] = copia.caras[arriba].color[5];
    micubo->caras[detras].color[6] = copia.caras[arriba].color[2];

    micubo->caras[abajo].color[8] = copia.caras[detras].color[0];
    micubo->caras[abajo].color[5] = copia.caras[detras].color[3];
    micubo->caras[abajo].color[2] = copia.caras[detras].color[6];

    //Cara derecha
    micubo->caras[derecha].color[1] = copia.caras[derecha].color[3];
    micubo->caras[derecha].color[3] = copia.caras[derecha].color[7];
    micubo->caras[derecha].color[5] = copia.caras[derecha].color[1];
    micubo->caras[derecha].color[7] = copia.caras[derecha].color[5];
    micubo->caras[derecha].color[0] = copia.caras[derecha].color[6];
    micubo->caras[derecha].color[2] = copia.caras[derecha].color[0];
    micubo->caras[derecha].color[6] = copia.caras[derecha].color[8];
    micubo->caras[derecha].color[8] = copia.caras[derecha].color[2];
}

void Rp(cubo *micubo){
    cubo copia = *micubo;

    //Todas las caras menos la derecha
    for(int i = 2; i<9; i = i+3){
        micubo->caras[frontal].color[i] = copia.caras[arriba].color[i];
        micubo->caras[abajo].color[i] = copia.caras[frontal].color[i];
    }
    
    micubo->caras[detras].color[0] = copia.caras[abajo].color[8];
    micubo->caras[detras].color[3] = copia.caras[abajo].color[5];
    micubo->caras[detras].color[6] = copia.caras[abajo].color[2];

    micubo->caras[arriba].color[8] = copia.caras[detras].color[0];
    micubo->caras[arriba].color[5] = copia.caras[detras].color[3];
    micubo->caras[arriba].color[2] = copia.caras[detras].color[6];

    //Cara derecha
    micubo->caras[derecha].color[1] = copia.caras[derecha].color[5];
    micubo->caras[derecha].color[3] = copia.caras[derecha].color[1];
    micubo->caras[derecha].color[5] = copia.caras[derecha].color[7];
    micubo->caras[derecha].color[7] = copia.caras[derecha].color[3];
    micubo->caras[derecha].color[0] = copia.caras[derecha].color[2];
    micubo->caras[derecha].color[2] = copia.caras[derecha].color[8];
    micubo->caras[derecha].color[6] = copia.caras[derecha].color[0];
    micubo->caras[derecha].color[8] = copia.caras[derecha].color[6];
}