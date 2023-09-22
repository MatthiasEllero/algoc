#include "date.h"

void afficherDate( Date *d){

        printf("Jour :%u, Mois :%u, Annee :%u",(*d).jour,(*d).mois,(*d).annee);

}

void initialiseDate( Date *d){

        scanf("%d", &(*d).jour);
        scanf("%d", (int *) &(*d).mois);
        scanf("%d", &(*d).annee);

}

Date creerDateParCopie(){

        Date date;
        scanf("%d", &(date.jour));
        scanf("%d", (int*) &(date.mois));
        scanf("%d", &(date.annee));
        return date;

}

Date* newDate(){

        Date* p1 ;
        p1 = (Date*) malloc(sizeof(Date));
        scanf("%d", &(p1->jour));
        scanf("%d", (int*) &(p1->mois));
        scanf("%d", &(p1->annee));
        return p1;

}
