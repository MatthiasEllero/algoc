#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


// constructs a new (empty) list
List *list_create(void) {
    List *l = malloc(sizeof(List));
    l->first = l->last = NULL;
    return l;
}

// counts the items on a list
size_t list_count(const List *list) {
    size_t count = 0;

    ListNode *p=list->first;
    while(p!=NULL) {
        count++;
        p=p->next;
    }

    return count;
}

// inserts item_data at *end* of a list
void list_addlast(List *list, data_t item_data) {

    ListNode* listNode = malloc(sizeof(ListNode));
    listNode->prev=NULL, listNode->next=NULL, listNode->data=item_data;

    if(list->last == NULL){
        list->last = listNode;
        list->first = listNode;
    }

    else{
        list->last->next=listNode;
        listNode->prev=list->last;
        list->last = listNode;
    }

}

// removes the item from *end* of the list and returns its value
data_t list_rmlast(List *list) {

    ListNode* lastNode = list->last;
    data_t data = lastNode->data;

    list->last=lastNode->prev;
    lastNode->prev->next=NULL;
    if(lastNode->prev == NULL){
        list->first = NULL;
    }

    destroyNode(lastNode);
    return data;

}

// permet de détruire une ListNode afin de réallouer la mémoire
void destroyNode(ListNode* listNode){
    destroyData(listNode->data);
    free(listNode);
}

// permet de détruire l'élément d'une ListNode, ici ne fait rien car data_t = int
void destroyData(data_t data){}

// permet de détruire tout une liste
void destroyList(List* list){

    ListNode* listNode = list->first;

    if(listNode == NULL){
        free(list);
    }

    else{
        while(listNode->next != NULL){
        listNode = listNode->next;
        destroyNode(listNode->prev);
        }

        destroyNode(list->last);
        free(list);
    }

}

// permet d'afficher tout les éléments d'une liste
void list_print(List* list){
    ListNode* listNode = list->first;
    printf("\n");
    print_data(listNode);
    while(listNode->next!=NULL){
        listNode = listNode->next;
        print_data(listNode);
    }
}

// permet d'afficher l'élément d'une ListNode, ici un int
void print_data(ListNode* listNode){
    printf("%i ",listNode->data);
}

int main(void) {

    List *l = list_create();

    assert(list_count(l)==0);

    list_addlast(l,10);
    list_addlast(l,20);
    list_addlast(l,30);
    list_addlast(l,40);

    assert(list_count(l)==4);

    list_print(l);

    data_t t =  list_rmlast(l);

    assert(t==40);
    list_print(l);

    destroyList(l);

    return 0;
}