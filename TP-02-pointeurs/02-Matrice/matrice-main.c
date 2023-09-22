#include "matrice.h"

int main(void) {

    Matrice* matrice1 = creerMatrice(1,3,2);
    Matrice* matrice2 = creerMatrice(2,3,3);
    matrix_print(matrice1);
    matrix_print(matrice2);
    Matrice* matrice3 = matrix_mult(matrice1,matrice2);
    matrix_print(matrice3);
    detruireMatrice(matrice1),detruireMatrice(matrice2),detruireMatrice(matrice3);
}