#include "linkedList.h"

typedef char* Element;

bool equalsElement(Element e1, Element e2){

    int c = 0;
    char char1 = e1[c];
    char char2 = e2[c];
    while(char1 != "\0" && char2 != "\0" ){

        if(char1 != char2){
            return false;
        }
        c++;
        char char1 = e1[c];
        char char2 = e2[c];
    }
    return true;
}

void afficheElement(Element e){

    printf("%s", e);
}

void detruireElement(Element e){}