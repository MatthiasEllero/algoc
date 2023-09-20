#include "echangeContenu.h"
#include <stdio.h>
#include <stdint.h>


void echangeContenu(int* a,int* b){

        int stock = *a;
        *a = *b;        
        *b = stock;      
}