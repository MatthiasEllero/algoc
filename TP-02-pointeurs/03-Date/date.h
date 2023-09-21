#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

enum Mois {jan = 1, fev, mars, avr, mai, juin, juil, aout, sept, oct, nov, dec};

typedef struct  {
    int jour;
    enum Mois mois;
    int annee;
} Date;

void initialiseDate(Date *d);
void afficherDate(Date *d);
Date creerDateParCopie();


