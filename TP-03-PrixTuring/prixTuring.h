

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

typedef struct {
    int annee;
    char* nom;
    char* travaux;
} PrixTuring;

FILE* lireFichier(char *name);
void fermerFichier(FILE* fichier);
int nombreLigneFichier(FILE* fichier);
char** stockerLignes(FILE* fichier);
PrixTuring* creerPrixTuring(char* uneLigne);
void lirePrixTuring(PrixTuring* unPrixTuring);
void detruireTableauLigne(char** tableauLignes, FILE* fichier);
void detruirePrixTuring(PrixTuring* unPrixTuring);