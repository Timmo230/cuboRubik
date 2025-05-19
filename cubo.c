#include <stdio.h>
#include "cubo.h"

void  reedFace(cara *estaCara){
    int c;
    for(int i = 0; i < 9; i++){
        //while((c = getchar()) != ' ');
        c = getchar();
        getchar();
        estaCara->color[i] = c;
    }
}