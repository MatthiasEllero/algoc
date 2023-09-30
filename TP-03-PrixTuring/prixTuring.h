

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

typedef struct
{
    char *annee;
    char *nom;
    char *travaux;
} PrixTuring;

FILE *lireFichier(char *name);
void fermerFichier(FILE *fichier);
int numberOfWinners(FILE *fichier);
char *readInfoJusque(char delimiteur, FILE *fichier, char *buffer);
char *creerBuffer(int tailleBuffer);
void reInitBuffer(char *buffer);
PrixTuring *creerPrixTuring(FILE *fichier);
PrixTuring **readWinners(FILE *fichier);
void printWinners(PrixTuring *unPrixTuring);
void detruireTableauPrixTuring(PrixTuring **tabPrixTuring, FILE *fichier);