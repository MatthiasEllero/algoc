#include "date.h"


int main(void){

    Date d;
    initialiseDate(&d); //Pourquoi a t-on ajouté un &?
    afficherDate(&d);

    return 0;
}
