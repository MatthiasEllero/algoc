#include "date.h"


int main(void){

    Date d1;
    initialiseDate(&d1); //Pourquoi a t-on ajouté un &?
    afficherDate(&d1);

    Date d2 = creerDateParCopie();
    afficherDate(&d2);

    Date* pdate = newDate();
    afficherDate(pdate);
    free(pdate);


    return 0;
}
