#include "prixTuring.h"


FILE* lireFichier(char* nomfichier){

    FILE* fichier;
    fichier = fopen(nomfichier, "r");
    return fichier;

}

void fermerFichier(FILE* fichier){

    fclose(fichier);

}

int nombreLigneFichier(FILE* fichier){

    int nombreDeLignes = 0;
    char ligne[500]; // Une ligne de 500 caractères max

    while (fgets(ligne, sizeof(ligne), fichier)) {
        nombreDeLignes++;
    };

    return nombreDeLignes;
}


/*int nombreInfoLigne(char* uneLigne){

    int nombreInfo = 0;
    char info[100]; // Une info de 500 caractères max

    while (fgetc(info, sizeof(info), uneLigne)) {
        nombreInfo++;
    };

    return nombreInfo;

}*/

char** stockerLignes(FILE* fichier){


    int nombreLignes = nombreLigneFichier(fichier);
    char** tableauLignes = (char**)malloc(sizeof(char*) * 57);
    
    for(int i=1;i<nombreLignes;i++){

            char* ligne =(char*) malloc(sizeof(char)*500);
            fgets(ligne, 500,fichier);
            tableauLignes[i] = ligne;
    }
    return tableauLignes;

}

PrixTuring* creerPrixTuring(char* uneLigne){

    PrixTuring* unPrixTuring =(PrixTuring*) malloc(sizeof(PrixTuring*));
    //
    return unPrixTuring;

}

void lirePrixTuring(PrixTuring* unPrixTuring){

        printf("%d\n", unPrixTuring->annee);
        printf("%s\n", unPrixTuring->nom);
        printf("%s\n", unPrixTuring->travaux);

}

void detruireTableauLigne(char** tableauLignes, FILE* fichier){

    for(int i=1; i<nombreLigneFichier(fichier);i++){

        free(tableauLignes[i]);
    }

}

void detruirePrixTuring(PrixTuring* unPrixTuring){

    free(unPrixTuring);

}