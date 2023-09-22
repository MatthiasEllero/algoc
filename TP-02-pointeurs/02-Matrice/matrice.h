#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

#define SIZE 5

typedef struct {

        uint16_t nbLignes;
        uint16_t nbColonnes;
        int** valeurs;

} Matrice;

Matrice* matrix_mult(Matrice* matriceA, Matrice* matriceB);
void matrix_print(Matrice* matrice);
Matrice* creerMatrice(int nbInit, int nbLignes, int nbColonnes);
void detruireMatrice(Matrice* matrice);
