#include "matrice.h"

int main(void) {

    Matrice* matrice1 = creerMatrice(1,3,3);
    Matrice* matrice2 = creerMatrice(2,3,3);
    matrix_print(matrice1);
    matrix_print(matrice2);
    detruireMatrice(matrice1),detruireMatrice(matrice2);
}