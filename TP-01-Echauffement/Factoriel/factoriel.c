/* Mon programme Hello World */

#include <stdio.h>
#include <stdint.h>


typedef long long unsigned TypeEntier;

TypeEntier factoriel(TypeEntier N) {
        
        if(N == 1){
                return 1;
        }
        else{
                return N*factoriel(N-1);
        }
};

void afficher15factoriels() {

        for(int i=1;i<16;i++){
                printf("%u\n",factoriel(i));
        }
}



int main(void) {

        
        /*TypeEntier N;
        scanf("%u",&N);
        TypeEntier unfactoriel = factoriel(N);
        printf("%u",unfactoriel);*/
        afficher15factoriels();

};
