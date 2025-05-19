#define amarillo 'A'
#define azul 'a'
#define verde 'v'
#define naranja 'n'
#define blanco 'b'
#define rojo 'r'

typedef struct cara{
    char color[9];
}cara;

typedef struct cubo{
    cara frontal;
    cara derecha;
    cara izquierda;
    cara arriba;
    cara abajo;
    cara detras;
} cubo;

void  reedFace(cara *estaCara);