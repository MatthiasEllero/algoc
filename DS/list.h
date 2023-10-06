#pragma once

#include <stddef.h>

typedef int data_t;

struct list_node {
   struct list_node *prev, *next;
   data_t data;
};

typedef struct list_node ListNode;

struct list {
   ListNode *first, *last;
};

typedef struct list List;

// constructs a new (empty) list
List *list_create(void);

// counts the items on the list
size_t list_count(const List *list);

// inserts item_data at *end* of the list
void list_addlast(List *list, data_t item_data);

// removes the item from *end* of the list and returns its value
data_t list_rmlast(List *list);

// permet d'afficher tout les éléments d'une liste
void list_print(List* list);

// permet d'afficher l'élément d'une ListNode
extern void print_data(ListNode* listNode);

// permet de détruire tout une liste
void destroyList(List* list);

// permet de détruire l'élément d'une ListNode
extern void destroyData(data_t data);

// permet de détruire une ListNode afin de réallouer la mémoire
void destroyNode(ListNode* listNode);
