#include <stdio.h>
#include "cubo.h"

int patron1[] = {6, 3, 0, 7, 4, 1, 8, 5, 2};
int patron2[] = {2, 5, 8, 1, 4, 7, 0, 3, 6};
int patron3[] = {6, 3, 0};

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

//PENDIENTE
int checkCube(cubo micubo){
    int a, A, r, b, n, v;
    char c;
    for(int i = 0;i < 9; i++){
        c = micubo.caras[frontal].color[i];

    }

}

void rotateFace(cubo copia, cubo *cubo,  int lado, int patron[]){ 
    for(int i = 0; i < 9; i++){
        cubo->caras[lado].color[i] = copia.caras[lado].color[patron[i]];
    }
}

void changeColumns(cubo copia, cubo *micubo, int lado1, int lado2, int lado3, int lado4,int inicio){
    for(int i = inicio; i<9; i = i+3){
        micubo->caras[lado1].color[i] = copia.caras[lado2].color[i];
        micubo->caras[lado3].color[i] = copia.caras[lado1].color[i];
    }
    for(int i = 0; i < 3; i++){
        if(inicio == 2){
            micubo->caras[lado4].color[patron3[i]] = copia.caras[lado3].color[i * 3 + 2];
            micubo->caras[lado2].color[i * 3 + 2] = copia.caras[lado4].color[patron3[i]];
        }else{
            micubo->caras[lado4].color[i * 3 + 2] = copia.caras[lado3].color[patron3[i]];
            micubo->caras[lado2].color[patron3[i]] = copia.caras[lado4].color[i * 3 + 2];
        }
    }
}

void R(cubo *micubo){
    cubo copia = *micubo;
    //Todas las caras menos la derecha
    changeColumns(copia, micubo, frontal, abajo, arriba, detras, 2);
    //Cara derecha
    rotateFace(copia, micubo, derecha, patron1);
}

void Rp(cubo *micubo){
    cubo copia = *micubo;
    //Todas las caras menos la derecha
    changeColumns(copia, micubo, frontal, arriba, abajo, detras, 2);
    //Rotas derecha
    rotateFace(copia, micubo, derecha, patron2);
}

void L(cubo *micubo){
    cubo copia = *micubo;
    //Todas las caras menos la izquierda
    changeColumns(copia, micubo, frontal, arriba, abajo, detras, 0);
    //Cara izquierda
    rotateFace(copia, micubo, izquierda, patron1);
}

void Lp(cubo *micubo){
    cubo copia = *micubo;
    //Todas las caras menos la izquierda
    changeColumns(copia, micubo,  frontal, abajo, arriba, detras, 0);
    //Cara izquierda
    rotateFace(copia, micubo, izquierda, patron2);
}

void U(cubo *micubo){
    cubo copia = *micubo;
    for(int i = 0; i < 3; i++){
        micubo->caras[izquierda].color[i] = copia.caras[frontal].color[i];
        micubo->caras[frontal].color[i] = copia.caras[derecha].color[i];
        micubo->caras[detras].color[i] = copia.caras[izquierda].color[i];
        micubo->caras[derecha].color[i] = copia.caras[detras].color[i]; 
    }

    rotateFace(copia, micubo, arriba, patron1);
}

void Up(cubo *micubo){
    cubo copia = *micubo;
    for(int i = 0; i < 3; i++){
        micubo->caras[izquierda].color[i] = copia.caras[detras].color[i];
        micubo->caras[frontal].color[i] = copia.caras[izquierda].color[i];
        micubo->caras[detras].color[i] = copia.caras[derecha].color[i];
        micubo->caras[derecha].color[i] = copia.caras[frontal].color[i]; 
    }

    rotateFace(copia, micubo, arriba, patron2);
}

void D(cubo *micubo){
    cubo copia = *micubo;
    for(int i = 6; i < 9; i++){
        micubo->caras[izquierda].color[i] = copia.caras[detras].color[i];
        micubo->caras[frontal].color[i] = copia.caras[izquierda].color[i];
        micubo->caras[detras].color[i] = copia.caras[derecha].color[i];
        micubo->caras[derecha].color[i] = copia.caras[frontal].color[i]; 
    }

    rotateFace(copia, micubo, abajo, patron1);
}

void Dp(cubo *micubo){
    cubo copia = *micubo;
    for(int i = 6; i < 9; i++){
        micubo->caras[izquierda].color[i] = copia.caras[frontal].color[i];
        micubo->caras[frontal].color[i] = copia.caras[derecha].color[i];
        micubo->caras[detras].color[i] = copia.caras[izquierda].color[i];
        micubo->caras[derecha].color[i] = copia.caras[detras].color[i]; 
    }

    rotateFace(copia, micubo, abajo, patron2);
}

void F(cubo *micubo){
    cubo copia = *micubo;

    micubo->caras[derecha].color[0] = copia->caras[arriba].color[6];
    micubo->caras[derecha].color[3] = copia->caras[arriba].color[7];
    micubo->caras[derecha].color[6] = copia->caras[arriba].color[8];

    micubo->caras[arriba].color[6] = copia->caras[izquierda].color[2];
    micubo->caras[arriba].color[7] = copia->caras[izquierda].color[5];
    micubo->caras[arriba].color[8] = copia->caras[izquierda].color[8];

    micubo->caras[izquierda].color[2] = copia->caras[abajo].color[0];
    micubo->caras[izquierda].color[5] = copia->caras[abajo].color[1];
    micubo->caras[izquierda].color[8] = copia->caras[abajo].color[2];

    micubo->caras[abajo].color[0] = copia->caras[derecha].color[0];
    micubo->caras[abajo].color[1] = copia->caras[derecha].color[3];
    micubo->caras[abajo].color[2] = copia->caras[derecha].color[6];
}