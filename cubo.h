#define amarillo 'A'
#define azul 'a'
#define verde 'v'
#define naranja 'n'
#define blanco 'b'
#define rojo 'r'

#define frontal 0
#define derecha 1
#define detras 2
#define izquierda 3
#define arriba 4
#define abajo 5

typedef struct cara{
    char color[9];
}cara;

typedef struct cubo{
    cara caras[6];
} cubo;

typedef struct treenode{
    int numMov;
    int movs[50];
}treenode;

void reedCube(cubo *micubo);
void reedFace(cara *estaCara);
void writeFace(cara lacara);
void writeCube(cubo micubo);
void R(cubo *micubo);
void Rp(cubo *micubo);
int checkCube(cubo micubo);