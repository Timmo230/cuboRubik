#include <stdio.h>
#include <string.h>
#include "cubo.h"

static int tests_run = 0;
static int tests_failed = 0;

static void check(const char *name, int condition) {
    tests_run++;
    if (!condition) {
        tests_failed++;
        printf("FAIL: %s\n", name);
    } else {
        printf("ok:   %s\n", name);
    }
}

static cubo solved_cube() {
    cubo c;
    memset(c.caras[frontal].color,  blanco,   9);
    memset(c.caras[derecha].color,  azul,     9);
    memset(c.caras[detras].color,   amarillo, 9);
    memset(c.caras[izquierda].color,verde,    9);
    memset(c.caras[arriba].color,   naranja,  9);
    memset(c.caras[abajo].color,    rojo,     9);
    return c;
}

static int cubes_equal(cubo a, cubo b) {
    for (int i = 0; i < 6; i++)
        if (memcmp(a.caras[i].color, b.caras[i].color, 9) != 0) return 0;
    return 1;
}

/* move applied 4 times = identity */
static void test_4x_identity(const char *name, cubo (*move)(cubo), cubo base) {
    cubo c = base;
    c = move(c); c = move(c); c = move(c); c = move(c);
    check(name, cubes_equal(c, base));
}

/* move followed by inverse = identity */
static void test_inverse(const char *name, cubo (*fwd)(cubo), cubo (*inv)(cubo), cubo base) {
    cubo c = fwd(base);
    c = inv(c);
    check(name, cubes_equal(c, base));
}

static void test_checkwin() {
    cubo s = solved_cube();
    check("checkWin solved", checkWin(s) == win);

    cubo u = solved_cube();
    u.caras[frontal].color[0] = rojo;
    check("checkWin unsolved", checkWin(u) == noWin);
}

static void test_checkcenter() {
    cubo s = solved_cube();
    check("checkCenter valid", checkCenter(s) == 1);

    cubo bad = solved_cube();
    bad.caras[frontal].color[4] = rojo;
    check("checkCenter bad center", checkCenter(bad) == error);
}

/* solver must find 1-move scrambles */
extern int continuar;

static void test_solver_1move(const char *name, cubo (*scramble)(cubo)) {
    cubo base = solved_cube();
    cubo scrambled = scramble(base);
    continuar = noWin;

    treenodeV first;
    first.actualPosition = scrambled;
    first.numMov = 0;
    for (int i = 0; i < 10; i++) first.movs[i] = 0;

    treenodeV *root = treenode(scrambled, first, 'N', 0);
    freeTree(root);
    check(name, continuar == done);
    continuar = noWin;
}

int main() {
    cubo s = solved_cube();

    /* 4x identity */
    test_4x_identity("R x4 = identity",  R,  s);
    test_4x_identity("Rp x4 = identity", Rp, s);
    test_4x_identity("L x4 = identity",  L,  s);
    test_4x_identity("Lp x4 = identity", Lp, s);
    test_4x_identity("U x4 = identity",  U,  s);
    test_4x_identity("Up x4 = identity", Up, s);
    test_4x_identity("D x4 = identity",  D,  s);
    test_4x_identity("Dp x4 = identity", Dp, s);
    test_4x_identity("F x4 = identity",  F,  s);
    test_4x_identity("Fp x4 = identity", Fp, s);
    test_4x_identity("B x4 = identity",  B,  s);
    test_4x_identity("Bp x4 = identity", Bp, s);
    test_4x_identity("M x4 = identity",  M,  s);
    test_4x_identity("Mp x4 = identity", Mp, s);

    /* inverse pairs */
    test_inverse("R + Rp = identity",   R,  Rp, s);
    test_inverse("Rp + R = identity",   Rp, R,  s);
    test_inverse("L + Lp = identity",   L,  Lp, s);
    test_inverse("U + Up = identity",   U,  Up, s);
    test_inverse("D + Dp = identity",   D,  Dp, s);
    test_inverse("F + Fp = identity",   F,  Fp, s);
    test_inverse("B + Bp = identity",   B,  Bp, s);
    test_inverse("M + Mp = identity",   M,  Mp, s);

    /* checkWin / checkCenter */
    test_checkwin();
    test_checkcenter();

    /* solver: 1-move scrambles */
    test_solver_1move("solver finds R",  R);
    test_solver_1move("solver finds Rp", Rp);
    test_solver_1move("solver finds L",  L);
    test_solver_1move("solver finds U",  U);
    test_solver_1move("solver finds D",  D);
    test_solver_1move("solver finds F",  F);
    test_solver_1move("solver finds B",  B);
    test_solver_1move("solver finds M",  M);

    printf("\n%d/%d passed\n", tests_run - tests_failed, tests_run);
    return tests_failed > 0 ? 1 : 0;
}
