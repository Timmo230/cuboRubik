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
    reedFace(&micubo->frontal);     
    printf("Giralo a la derecha y pon esa cara\n");
    reedFace(&micubo->derecha);     
    printf("Giralo a la derecha y pon esa cara\n");
    reedFace(&micubo->detras);      
    printf("Giralo a la derecha y pon esa cara\n");
    reedFace(&micubo->izquierda);   
    printf("Giralo hacia arriba y pon esa cara\n");
    reedFace(&micubo->arriba);
    printf("Ahora pon la cara restante\n");
    reedFace(&micubo->abajo);
}

void writeCube(cubo micubo){
    writeFace(micubo.frontal);
    writeFace(micubo.derecha);
    writeFace(micubo.detras);
    writeFace(micubo.izquierda);
    writeFace(micubo.arriba);
    writeFace(micubo.abajo);
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
        c = micubo.frontal.color[i];

    }

}