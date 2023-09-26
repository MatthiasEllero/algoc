/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/
#include "prixTuring.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";
	FILE* fichier = lireFichier(filename);
	char** tabLignes = stockerLignes(fichier);
	//PrixTuring* unPrixTuring = creerPrixTuring(tabLignes[0]);
	//lirePrixTuring(unPrixTuring);
	detruireTableauLigne(tabLignes, fichier);
    //detruirePrixTuring(unPrixTuring);
	printf("%s",tabLignes[0]);
	return EXIT_SUCCESS;
}
