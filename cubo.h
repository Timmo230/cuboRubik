#define amarillo 'A'
#define azul 'a'
#define verde 'v'
#define naranja 'n'
#define blanco 'b'
#define rojo 'r'

typedef struct cubo{
    char frontal[9];
    char derecha[9];
    char izquierda[9];
    char arriba[9];
    char abajo[9];
    char detras[9];
} cubo;