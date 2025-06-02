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

#define error -1
#define noWin -2
#define sucessful 1
#define win 2

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
int checkCube(cubo micubo);
void rotateFace(cubo copia, cubo *cubo, int lado, int patron[]);
void changeColumns(cubo copia, cubo *micubo, int lado1, int lado2, int lado3, int lado4,int inicio);
void inicializeArray(int array[][3], int index1, int index2);
int checkWin(cubo micubo);
int checkCenter(cubo micubo);

void R(cubo *micubo);
void Rp(cubo *micubo);
void L(cubo *micubo);
void Lp(cubo *micubo);
void U(cubo *micubo);
void Up(cubo *micubo);
void D(cubo *micubo);
void Dp(cubo *micubo);
void F(cubo *micubo);
void Fp(cubo *micubo);
void B(cubo *micubo);
void Bp(cubo *micubo);
void M(cubo *micubo);
void Mp(cubo *micubo);