#include "prixTuring.h"

FILE *lireFichier(char *nomfichier)
{

    FILE *fichier;
    fichier = fopen(nomfichier, "r");
    return fichier;
}

void fermerFichier(FILE *fichier)
{

    fclose(fichier);
}

int numberOfWinners(FILE *fichier)
{

    int nombreDeLignes = 0;
    char ligne[500]; // Une ligne de 500 caractères max

    while (fgets(ligne, sizeof(ligne), fichier))
    {
        nombreDeLignes++;
    };

    return nombreDeLignes;
}

char *readInfoJusque(char delimiteur, FILE *fichier, char *buffer)
{
    char character;
    int compteur = 0;
    while (character = !delimiteur)
    {
        character = fgetc(fichier);
        buffer[compteur] = character;
        compteur++;
    }

    char *info = (char *)malloc(compteur * sizeof(char));
    for (int i = 0; i < compteur; i++)
    {
        info[i] = buffer[i];
    }

    return info;
}

char *creerBuffer(int tailleBuffer)
{
    return ((char *)malloc(tailleBuffer * sizeof(char)));
}

void reInitBuffer(char *buffer)
{
    char character;
    int compteur = 0;
    while (character = !'\0')
    {
        buffer[compteur] = '\0';
        compteur++;
        character = buffer[compteur];
    }
}

PrixTuring *creerPrixTuring(FILE *fichier)
{

    PrixTuring *unPrixTuring = (PrixTuring *)malloc(sizeof(PrixTuring *));

    char *buffer = creerBuffer(500);
    unPrixTuring->annee = readInfoJusque(';', fichier, buffer);
    reInitBuffer(buffer);

    unPrixTuring->nom = readInfoJusque(';', fichier, buffer);
    reInitBuffer(buffer);

    unPrixTuring->travaux = readInfoJusque('\n', fichier, buffer);
    free(buffer);

    return unPrixTuring;
}

PrixTuring **readWinners(FILE *fichier)
{

    int nombreLignes = numberOfWinners(fichier);
    PrixTuring **tabPrixTuring = (PrixTuring **)malloc(nombreLignes * sizeof(PrixTuring));
    for (int i = 0; i < nombreLignes; i++)
    {

        tabPrixTuring[i] = creerPrixTuring(fichier);
    }
    return tabPrixTuring;
}

void printWinners(PrixTuring *unPrixTuring)
{

    printf("%s\n", unPrixTuring->annee);
    printf("%s\n", unPrixTuring->nom);
    printf("%s\n", unPrixTuring->travaux);
}

void detruireTableauPrixTuring(PrixTuring **tabPrixTuring, FILE *fichier)
{

    for (int i = 0; i < numberOfWinners(fichier); i++)
    {

        PrixTuring *unPrixTuring = tabPrixTuring[i];
        free(unPrixTuring->annee);
        free(unPrixTuring->nom);
        free(unPrixTuring->travaux);
        free(unPrixTuring);
    }
}