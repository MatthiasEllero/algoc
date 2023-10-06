#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "vaccins_covid.h"

// =========
// = Types =
// =========

const char NUCLEOTIDES[] = "ATCG";

typedef struct {
	int index;
	int distance;
} Difference ;

// =============
// = Fonctions =
// =============


bool isNucleotide(char c) {
    return (c==NUCLEOTIDES[0] || c==NUCLEOTIDES[1] || c==NUCLEOTIDES[2] || c==NUCLEOTIDES[3]);
}

int indexOf(char nucleotide) {
	switch(nucleotide) {
		case 'A': return 0;
		case 'T': return 1;
		case 'C': return 2;
		case 'G': return 3;
		default:
			return -1;
	}
}

int distanceBetweenNucleotides(char n1, char n2) {
    return indexOf(n1)-indexOf(n2);
}

int* statistics(char* seqGen){
	int seqGenSize = sequenceSize(seqGen);
	int* statistics = calloc(4,sizeof(int));
	char n;
	for(int i=0;i<seqGenSize;i++){
		n = seqGen[i];
		statistics[indexOf(n)]=statistics[indexOf(n)] + 100;
	}
	for(int i=0;i<4;i++){
		(statistics[i])=(int) (statistics[i])/seqGenSize;
	}
	return statistics;
}

// Permet d'obtenir la taille de la séquence analysée

int sequenceSize(char* seqGen){
	int i = 0;
	char c = seqGen[0];
	while(isNucleotide(c)){
		i++;
		c = seqGen[i];
	}
	return i;
}

// Permet d'obtenir une liste de différences entre deux séquences génétiques (distance passée à l'absolue pour que ce soit positif)

Difference** computeDifferenceBeetween(char* seqGen1, char* seqGen2){

	int seqGenSize = sequenceSize(seqGen1);
	Difference** buffer = calloc(seqGenSize,sizeof(Difference*));
	int c = 0;

	for(int i=0; i<seqGenSize; i++){
		if(seqGen1[i] != seqGen2[i]){
			Difference* difference = malloc(sizeof(Difference));
			difference->index=i;
			difference->distance= abs(distanceBetweenNucleotides(seqGen1[i], seqGen2[i]));
			buffer[i] = difference;
			c++;
			}
	}

	Difference** tabDifference = malloc(c*sizeof(Difference));
	c = 0;
	for(int i=0; i<seqGenSize;i++){
		if(buffer[i] != 0){
			tabDifference[c] = buffer[i];
			c++;
		}
	}

	free(buffer);
	return tabDifference;
}


// ========
// = Main =
// ========

int main(void){

	char sequenceDeNucleotides[]="ATGCATCCATCATGCATGTA";

    //printf("%s\n",code_proteine_spike_moderna);

	
	char* seq1 = "ATGC";
	char* seq2 = "ATCG";


	// Test sur la fonction statistics
	int* statistiques = statistics(seq1);
	for(int i=0; i<4;i++){
		printf("%i ", statistiques[i]);
	}
	free(statistiques);

	// Test sur la fonction Difference entre deux séquences simples
	Difference** tabDifference1 = computeDifferenceBeetween(seq1,seq2);
	printf("<%i,%i>\n",tabDifference1[0]->index,tabDifference1[0]->distance);
	printf("<%i,%i>\n",tabDifference1[1]->index,tabDifference1[1]->distance);
	free(tabDifference1);
	

	// Fonction Difference sur les codes des deux vaccins
	Difference** tabDifference = computeDifferenceBeetween(code_proteine_spike_moderna,code_proteine_spike_pfizer);
	for(int i=0; i<359;i++){
		printf("<%i,%i>\n",tabDifference[i]->index,tabDifference[i]->distance);
		free(tabDifference[i]);
	}
	free(tabDifference);

	return EXIT_SUCCESS;

	/*
	La fonction computeDifferenceBeetween serait plus pratique si elle permettait aussi de retourner la taille du tableau (ou si on avait
	une fonction permettant de la trouver), afin de pouvoir créer efficacement une fonction pour libérer l'espace allouée
	*/
}

