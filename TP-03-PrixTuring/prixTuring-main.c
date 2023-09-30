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
	FILE *fichier = lireFichier(filename);
	PrixTuring **tabPrixTuring = readWinners(fichier);
	printWinners(tabPrixTuring[0]);
	detruireTableauPrixTuring(tabPrixTuring, fichier);
	fermerFichier(fichier);
	return EXIT_SUCCESS;
}
