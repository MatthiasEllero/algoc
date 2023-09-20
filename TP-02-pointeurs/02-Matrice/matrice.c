#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

#define SIZE 5

void matrix_mult(int64_t matriceResultat[][SIZE],int64_t m1[][SIZE], int64_t m2[][SIZE]){

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){

            int64_t somme = 0;
            for(int k=0; k<SIZE;k++){

                somme += m1[i][k] * m2[k][j];

            }

            matriceResultat[i][j] = somme;

        }
    }

}

void matrix_print(int64_t matrice[][SIZE]){

    for(int i=0;i<SIZE;i++){

        for(int j=0;j<SIZE;j++){

            printf("%"PRIu64" ",matrice[i][j]);

        }

        printf("\n");

    }

}

int main(void) {

//matrices en ligne * colonne

int64_t matrice1[][SIZE]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
int64_t matrice2[][SIZE]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};

int64_t matriceResultat[SIZE][SIZE];

matrix_mult(matriceResultat,matrice1,matrice2);
matrix_print(matriceResultat);

return EXIT_SUCCESS;
}