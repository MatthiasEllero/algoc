#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l)
{
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v)
{
	Cellule *uneCellule = (Cellule *)malloc(sizeof(Cellule));
	uneCellule->suiv = NULL;
	uneCellule->val = v;
	return uneCellule;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l)
{
	Cellule *suiv = l;
	l = creer(v);
	l->suiv = suiv;
	return l;
}

void afficheElement(Element e)
{
	printf("%i ", e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l)
{
	if (estVide(l) == false)
	{
		Cellule uneCellule = *l;
		afficheElement(uneCellule.val);
		while (uneCellule.suiv != NULL)
		{
			uneCellule = *uneCellule.suiv;
			afficheElement(uneCellule.val);
		}
	}
}

// version recursive
void afficheListe_r(Liste l)
{
	if (estVide(l) == false)
	{
		afficheElement(l->val);
		if (l->suiv != NULL)
		{
			afficheListe_r(l->suiv);
		}	
	}
}

void detruireElement(Element e) {}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l)
{
	Cellule cellule = *l;
	Cellule celluleSuivante = *cellule.suiv;
	Cellule celluleADetruire;
	while(celluleSuivante.suiv!=NULL){

		celluleADetruire = cellule;
		cellule = celluleSuivante;
		celluleSuivante = *cellule.suiv;
		detruireElement(celluleADetruire.val);
		free(celluleADetruire.suiv);

	}
	free(l);
}

// version récursive
void detruire_r(Liste l)
{
	while(l->suiv!=NULL){
		detruire_r(l->suiv);
	}
	detruireElement(l->val);
	free(l);
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l)
{	
	Cellule* cellule = l;
	while(cellule->suiv!=NULL){

		cellule = cellule->suiv;
	}
	cellule->suiv = creer(v);
}

// version recursive
Liste ajoutFin_r(Element v, Liste l)
{
	if(estVide(l)){
		return creer(v);
	}
	return(ajoutFin_r(v, l->suiv));
}

// compare deux elements
bool equalsElement(Element e1, Element e2)
{
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v, Liste l)
{
	Cellule* cellule = l;
	if(equalsElement(cellule->val, v)){
		return l;
	}
	while(cellule->suiv!=NULL){
		cellule =cellule->suiv;
		if(equalsElement(cellule->val, v)){
		return cellule;
	}
}
}

// version récursive
Liste cherche_r(Element v, Liste l)
{
	Cellule* cellule = l;
	if(cellule->suiv==NULL){
		if(!equalsElement(cellule->val, v)){
		return NULL;
	}
	}
	if(!equalsElement(cellule->val, v)){
		cherche_r(v, cellule->suiv);
	}
	return(l);
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l)
{
	Cellule cellule = *l;
	if(equalsElement(cellule.val, v)){
		return cellule.suiv;
	}
	Cellule celluleSuivante = *cellule.suiv;
	while(!equalsElement(cellule.val, v)){
		if(celluleSuivante.suiv == NULL){
			return l;
		}
		cellule = celluleSuivante;
		celluleSuivante = *celluleSuivante.suiv;
	}
	Cellule* celluleADetruire = &celluleSuivante;
	cellule.suiv = celluleSuivante.suiv;
	free(celluleADetruire);
	return(l);
}

// version recursive
Liste retirePremier_r(Element v, Liste l)
{
	Cellule* cellule = l;
	if(cellule->suiv==NULL){
		if(!equalsElement(cellule->val, v)){
		return l;
	}
	}
	if(!equalsElement(cellule->val, v)){
		cherche_r(v, cellule->suiv);
	}
	if(equalsElement((cellule->suiv)->val, v)){
		Cellule* celluleADetruire = l->suiv;
		l->suiv = l->suiv->suiv;
		free(celluleADetruire);
	}
	return(l);
}

void afficheEnvers_r(Liste l)
{
	TODO;
}
