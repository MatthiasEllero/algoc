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

int main(int argc, char **argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";

	FILE *fichier = fopen(filename, "r");
	int nombreLignes = numberOfWinners(fichier);
	PrixTuring **tabPrixTuring = readWinners(fichier);

	//printf("%s",tabPrixTuring[0]->nom);
	//printWinners(tabPrixTuring[0]);

	FILE *nouveauFichier = fopen(outputFilename,"w");
	ecrireToutPrixTuringFichierCSV(nouveauFichier, tabPrixTuring, nombreLignes);

	detruireTableauPrixTuring(tabPrixTuring, nombreLignes);

	fclose(nouveauFichier);
	fclose(fichier);
	return EXIT_SUCCESS;
}
