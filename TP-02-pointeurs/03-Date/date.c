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


        int jour;
        int mois;
        int annee;
        scanf("%d", &jour);
        scanf("%d", &mois);
        scanf("%d", &annee);
        Date date;
        date.jour = jour;
        date.mois = mois;
        date.annee = annee;
        return date;

}