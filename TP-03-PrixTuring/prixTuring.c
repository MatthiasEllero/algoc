#include "prixTuring.h"


void fermerFichier(FILE *fichier)
{

    fclose(fichier);
}

int numberOfWinners(FILE *fichier)
{

    rewind(fichier);
    int nombreDeLignes = 0;
    char ligne[500]; // Une ligne de 500 caractères max

    while (fgets(ligne, sizeof(ligne), fichier))
    {
        nombreDeLignes++;
    };

    rewind(fichier);
    return nombreDeLignes;
}

char *readInfoJusque(char delimiteur, FILE *fichier, char *buffer)
{
    char character;
    int compteur = 0;
    character = (char) fgetc(fichier);
    while (character !=delimiteur)
    {
        buffer[compteur] = character;
        character = (char) fgetc(fichier);
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
    while (character !='\0')
    {
        buffer[compteur] = '\0';
        compteur++;
        character = buffer[compteur];
    }
}

PrixTuring *creerPrixTuring(FILE *fichier)
{

    PrixTuring *unPrixTuring = (PrixTuring *)malloc(sizeof(PrixTuring));

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

void detruireTableauPrixTuring(PrixTuring **tabPrixTuring, int nombreLignes)
{

    for (int i = 0; i < nombreLignes; i++)
    {

        PrixTuring *unPrixTuring = tabPrixTuring[i];
        free(unPrixTuring->annee);
        free(unPrixTuring->nom);
        free(unPrixTuring->travaux);
        free(unPrixTuring);
    }
}

void ecrireUnPrixTuringFichierCSV(FILE* fichier, PrixTuring* unPrixTuring){

    fprintf(fichier, "%s;%s;%s\n", unPrixTuring->annee, unPrixTuring->nom, unPrixTuring->travaux);

}

void ecrireToutPrixTuringFichierCSV(FILE* fichier, PrixTuring** tabPrixTuring, int nombreLignes){

    for(int i=0;i<nombreLignes;i++){

        ecrireUnPrixTuringFichierCSV(fichier, tabPrixTuring[i]);

    }

}