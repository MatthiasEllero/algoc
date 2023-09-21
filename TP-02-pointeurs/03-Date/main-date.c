#include "date.h"


int main(void){

    Date d1;
    initialiseDate(&d1); //Pourquoi a t-on ajouté un &?
    afficherDate(&d1);

    Date d2;
    d2 = creerDateParCopie();
    afficherDate(&d2);


    return 0;
}
