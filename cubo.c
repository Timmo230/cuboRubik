#include <stdio.h>
#include "cubo.h"

int patron1[] = {6, 3, 0, 7, 4, 1, 8, 5, 2};
int patron2[] = {2, 5, 8, 1, 4, 7, 0, 3, 6};
int patron3[] = {6, 3, 0};

void reedFace(cara *estaCara){
    int c;
    for(int i = 0; i < 9; i++){
        c = getchar();
        getchar();
        estaCara->color[i] = c;
    }
}

void reedCube(cubo *micubo){
    printf("Pon la cara en la que este el color blanco en el centro\n");
    reedFace(&micubo->caras[frontal]);     
    printf("Ahora con el azul\n");
    reedFace(&micubo->caras[derecha]);     
    printf("Ahora con el amarillo\n");
    reedFace(&micubo->caras[detras]);      
    printf("Ahora con el verde\n");
    reedFace(&micubo->caras[izquierda]);   
    printf("Ahora con el naranja\n");
    reedFace(&micubo->caras[arriba]);
    printf("Ahora con el rojo\n");
    reedFace(&micubo->caras[abajo]);
    printf("\n\n");
}

int checkWin(cubo micubo){
    for(int i = 0; i < 6; i++){
        char c = micubo.caras[i].color[0];
        for(int j = 1; j < 9; j++) if(micubo.caras[i].color[j] != c) return noWin;
    }
    return win;
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

void inicializeArray(int array[][3], int index1, int index2){
    for(int i = 0; i<index1;i++){
        for(int j = 0; j<index2; j++){
            array[i][j] = 0;
        }
    }
}

int amountEachColor(cubo micubo){
    int colors[6][3];
    inicializeArray(colors, 6, 3);
    char c;
    for(int j = 0; j<6; j++){
        for(int i = 0;i < 9; i++){
            c = micubo.caras[j].color[i];
            switch (c){
                case 'a':
                    if(i == 0 || i == 2 || i == 6 || i == 8) colors[0][0]++;
                    else if(i == 1 || i == 3 || i == 5 || i == 7) colors[0][1]++;
                    else colors[0][2]++;
                break;
                case 'A':
                    if(i == 0 || i == 2 || i == 6 || i == 8) colors[1][0]++;
                    else if(i == 1 || i == 3 || i == 5 || i == 7) colors[1][1]++;
                    else colors[1][2]++;
                break;
                case 'r':
                    if(i == 0 || i == 2 || i == 6 || i == 8) colors[2][0]++;
                    else if(i == 1 || i == 3 || i == 5 || i == 7) colors[2][1]++;
                    else colors[2][2]++;
                break;
                case 'b':
                    if(i == 0 || i == 2 || i == 6 || i == 8) colors[3][0]++;
                    else if(i == 1 || i == 3 || i == 5 || i == 7) colors[3][1]++;
                    else colors[3][2]++;
                break;
                case 'n':
                    if(i == 0 || i == 2 || i == 6 || i == 8) colors[4][0]++;
                    else if(i == 1 || i == 3 || i == 5 || i == 7) colors[4][1]++;
                    else colors[4][2]++;
                break;
                case 'v':
                    if(i == 0 || i == 2 || i == 6 || i == 8) colors[5][0]++;
                    else if(i == 1 || i == 3 || i == 5 || i == 7) colors[5][1]++;
                    else colors[5][2]++;
                break;
            }
        }
    }

    for(int i = 0; i < 6; i++) if(colors[i][0] != 4 || colors[i][1] != 4 || colors[i][2] != 1) return error;
    return 1;
}

int checkCenter(cubo micubo){
    if(micubo.caras[frontal].color[4] != blanco || micubo.caras[derecha].color[4] != azul || 
        micubo.caras[detras].color[4] != amarillo || micubo.caras[izquierda].color[4] != verde ||
        micubo.caras[arriba].color[4] != naranja || micubo.caras[abajo].color[4] != rojo) return error;
    return 1;
}

int checkCube(cubo micubo){
    int check = amountEachColor(micubo);
    if(check != error && checkWin(micubo) == win) check = error;
    if(check != error && checkCenter(micubo) == error) check = error;
    
    return check;
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

    micubo->caras[derecha].color[0] = copia.caras[arriba].color[6];
    micubo->caras[derecha].color[3] = copia.caras[arriba].color[7];
    micubo->caras[derecha].color[6] = copia.caras[arriba].color[8];

    micubo->caras[arriba].color[6] = copia.caras[izquierda].color[8];
    micubo->caras[arriba].color[7] = copia.caras[izquierda].color[5];
    micubo->caras[arriba].color[8] = copia.caras[izquierda].color[2];

    micubo->caras[izquierda].color[2] = copia.caras[abajo].color[0];
    micubo->caras[izquierda].color[5] = copia.caras[abajo].color[1];
    micubo->caras[izquierda].color[8] = copia.caras[abajo].color[2];

    micubo->caras[abajo].color[0] = copia.caras[derecha].color[6];
    micubo->caras[abajo].color[1] = copia.caras[derecha].color[3];
    micubo->caras[abajo].color[2] = copia.caras[derecha].color[0];

    rotateFace(copia, micubo, frontal, patron1);
}

void Fp(cubo *micubo){
    cubo copia = *micubo;

    micubo->caras[derecha].color[0] = copia.caras[abajo].color[2];
    micubo->caras[derecha].color[3] = copia.caras[abajo].color[1];
    micubo->caras[derecha].color[6] = copia.caras[abajo].color[0];

    micubo->caras[arriba].color[6] = copia.caras[derecha].color[0];
    micubo->caras[arriba].color[7] = copia.caras[derecha].color[3];
    micubo->caras[arriba].color[8] = copia.caras[derecha].color[6];

    micubo->caras[izquierda].color[2] = copia.caras[arriba].color[8];
    micubo->caras[izquierda].color[5] = copia.caras[arriba].color[7];
    micubo->caras[izquierda].color[8] = copia.caras[arriba].color[6];

    micubo->caras[abajo].color[0] = copia.caras[izquierda].color[2];
    micubo->caras[abajo].color[1] = copia.caras[izquierda].color[5];
    micubo->caras[abajo].color[2] = copia.caras[izquierda].color[8];

    rotateFace(copia, micubo, frontal, patron2);
}

void B(cubo *micubo){
    cubo copia = *micubo;

    micubo->caras[arriba].color[0] = copia.caras[derecha].color[2];
    micubo->caras[arriba].color[1] = copia.caras[derecha].color[5];
    micubo->caras[arriba].color[2] = copia.caras[derecha].color[8];

    micubo->caras[derecha].color[2] = copia.caras[abajo].color[8];
    micubo->caras[derecha].color[5] = copia.caras[abajo].color[7];
    micubo->caras[derecha].color[8] = copia.caras[abajo].color[6];

    micubo->caras[abajo].color[6] = copia.caras[izquierda].color[0];
    micubo->caras[abajo].color[7] = copia.caras[izquierda].color[3];
    micubo->caras[abajo].color[8] = copia.caras[izquierda].color[6];

    micubo->caras[izquierda].color[0] = copia.caras[arriba].color[2];
    micubo->caras[izquierda].color[3] = copia.caras[arriba].color[1];
    micubo->caras[izquierda].color[6] = copia.caras[arriba].color[0];

    rotateFace(copia, micubo, detras, patron1);
}

void Bp(cubo *micubo){
    cubo copia = *micubo;

    micubo->caras[arriba].color[0] = copia.caras[izquierda].color[6];
    micubo->caras[arriba].color[1] = copia.caras[izquierda].color[3];
    micubo->caras[arriba].color[2] = copia.caras[izquierda].color[0];

    micubo->caras[derecha].color[2] = copia.caras[arriba].color[0];
    micubo->caras[derecha].color[5] = copia.caras[arriba].color[1];
    micubo->caras[derecha].color[8] = copia.caras[arriba].color[2];

    micubo->caras[abajo].color[6] = copia.caras[derecha].color[8];
    micubo->caras[abajo].color[7] = copia.caras[derecha].color[5];
    micubo->caras[abajo].color[8] = copia.caras[derecha].color[2];

    micubo->caras[izquierda].color[0] = copia.caras[abajo].color[6];
    micubo->caras[izquierda].color[3] = copia.caras[abajo].color[7];
    micubo->caras[izquierda].color[6] = copia.caras[abajo].color[8];

    rotateFace(copia, micubo, detras, patron2);
}

void M(cubo *micubo){
    cubo copia = *micubo;

    micubo->caras[arriba].color[1] = copia.caras[detras].color[7];
    micubo->caras[arriba].color[4] = copia.caras[detras].color[4];
    micubo->caras[arriba].color[7] = copia.caras[detras].color[1];

    micubo->caras[frontal].color[1] = copia.caras[arriba].color[1];
    micubo->caras[frontal].color[4] = copia.caras[arriba].color[4];
    micubo->caras[frontal].color[7] = copia.caras[arriba].color[7];

    micubo->caras[abajo].color[1] = copia.caras[frontal].color[1];
    micubo->caras[abajo].color[4] = copia.caras[frontal].color[4];
    micubo->caras[abajo].color[7] = copia.caras[frontal].color[7];

    micubo->caras[detras].color[1] = copia.caras[abajo].color[7];
    micubo->caras[detras].color[4] = copia.caras[abajo].color[4];
    micubo->caras[detras].color[7] = copia.caras[abajo].color[1];
}

void Mp(cubo *micubo){
    cubo copia = *micubo;

    micubo->caras[arriba].color[1] = copia.caras[frontal].color[1];
    micubo->caras[arriba].color[4] = copia.caras[frontal].color[4];
    micubo->caras[arriba].color[7] = copia.caras[frontal].color[7];

    micubo->caras[frontal].color[1] = copia.caras[abajo].color[1];
    micubo->caras[frontal].color[4] = copia.caras[abajo].color[4];
    micubo->caras[frontal].color[7] = copia.caras[abajo].color[7];

    micubo->caras[abajo].color[1] = copia.caras[detras].color[7];
    micubo->caras[abajo].color[4] = copia.caras[detras].color[4];
    micubo->caras[abajo].color[7] = copia.caras[detras].color[1];

    micubo->caras[detras].color[1] = copia.caras[arriba].color[7];
    micubo->caras[detras].color[4] = copia.caras[arriba].color[4];
    micubo->caras[detras].color[7] = copia.caras[arriba].color[1];
}
