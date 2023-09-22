#include "matrice.h"

Matrice* matrix_mult(Matrice* matriceA, Matrice* matriceB){

    if(matriceA ->nbColonnes != matriceB->nbLignes){

            printf("Impossible car tailles des matrices incompatibles");
            return NULL;

    };

    Matrice* matriceResultat = creerMatrice(0,matriceA->nbLignes,matriceB->nbColonnes);
    for(int i=0;i<matriceResultat->nbLignes;i++){
        for(int j=0;j<matriceResultat->nbColonnes;j++){
            int64_t somme = 0;
            for(int k=0; k<matriceA->nbColonnes;k++){
                somme += matriceA->valeurs[i][k] * matriceB->valeurs[k][j];
            }
            matriceResultat->valeurs[i][j] = somme;
        }
    }
    return matriceResultat;
}

void matrix_print(Matrice* matrice){

    for(int i=0;i<matrice->nbLignes;i++){
        for(int j=0;j<matrice->nbColonnes;j++){
            printf("%u ",matrice->valeurs[i][j]);
        }
        printf("\n");
    }
};

Matrice* creerMatrice(int nbInit, int nbLignes, int nbColonnes){

    Matrice* m1;
    m1 = (Matrice*) malloc(sizeof(Matrice));
    m1->nbColonnes = nbColonnes, m1->nbLignes = nbLignes;
    m1->valeurs = (int**) malloc(nbLignes*sizeof(int*));
    for(int i=0;i<nbLignes;i++){
        m1->valeurs[i] = (int*) malloc(nbColonnes*sizeof(int));
        for(int j=0;j<nbColonnes;j++){
            m1->valeurs[i][j]=nbInit;
        }
    }
    return m1;
    
};

void detruireMatrice(Matrice* matrice){

    for(int i=0;i<matrice->nbLignes;i++){
        free(matrice->valeurs[i]);
    };
    free(matrice->valeurs);
    free(matrice);
}
