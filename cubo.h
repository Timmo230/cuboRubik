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
#define done 3

typedef struct cara{
    char color[9];
}cara;

typedef struct cubo{
    cara caras[6];
} cubo;

typedef struct treenode{
    struct cubo actualPosition;
    int numMov;
    char movs[10];
    struct treenode *R;
    struct treenode *Rp;
    struct treenode *L;
    struct treenode *Lp;
    struct treenode *U;
    struct treenode *Up;
    struct treenode *D;
    struct treenode *Dp;
    struct treenode *F;
    struct treenode *Fp;
    struct treenode *B;
    struct treenode *Bp;
    struct treenode *M;
    struct treenode *Mp;
}treenodeV;

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
int amountEachColor(cubo micubo);
void igualarArrays(char primero[], char segundo[]);

cubo R(cubo micubo);
cubo Rp(cubo micubo);
cubo L(cubo micubo);
cubo Lp(cubo micubo);
cubo U(cubo micubo);
cubo Up(cubo micubo);
cubo D(cubo micubo);
cubo Dp(cubo micubo);
cubo F(cubo micubo);
cubo Fp(cubo micubo);
cubo B(cubo micubo);
cubo Bp(cubo micubo);
cubo M(cubo micubo);
cubo Mp(cubo micubo);

treenodeV* treenode(cubo actualPosition, treenodeV lastNode, char lastMove, int numMove);