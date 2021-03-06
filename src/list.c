/**
 * \file list.c
 * \brief Source de liste
 */

#include "list.h"

Element * creerElement(Sommet * x, int l) {
	Element * new = (Element *) malloc(sizeof(Element));
	new->x = x;
	new->l = l;
	new->next = NULL;
	return new;
}

Liste * creerListe() {
	Liste * new = (Liste *) malloc(sizeof(Liste));
	new->hd = NULL;
	return new;
}

void freeElement(Element * e) {
	if (e) {
		freeElement(e->next);
		free(e);
	}
}

void freeListe(Liste * list) {
	if (list) {
		freeElement(list->hd);
		free(list);
	}
}

void displayListe(Liste * list) {
	if (!list) {
		fprintf(stderr, "displayListe : liste non initialisée");
		return;
	}
	Element * current = list->hd;
	while (current) {
		fprintf(stdout, "%d %d %d %d\n", current->x->numero, current->x->x,
				current->x->y, current->l);
		current = current->next;
	}
	printf("\n");
}

Liste * initialiserListe() {
	return creerListe();
}

int estVideListe(Liste * list) {
	return list && list->hd == NULL ;
}

void ajouterElementListe(Liste * list, Sommet * x, int l) {
	if (!list) {
		fprintf(stderr, "ajouterElementListe : liste non initialisée");
		return;
	}
	Element * e = creerElement(x, l);
	// empty
	if (estVideListe(list)) {
		list->hd = e;
		return;
	}
	// before current hd
	if (list->hd->l > e->l) {
		e->next = list->hd;
		list->hd = e;
		return;
	}
	Element * prev = list->hd;
	Element * current = list->hd->next;
	while (current && current->l < e->l) {
		prev = current;
		current = current->next;
	}
	prev->next = e;
	e->next = current;
}

void supprimerElementListe(Liste * list, Sommet * x) {
	if (!list) {
		fprintf(stderr, "supprimerElementListe : liste non initialisée");
		return;
	}
	if (list->hd->x == x) {
		Element * mem = list->hd;
		list->hd = list->hd->next;
		free(mem);
		return;
	}
	Element * previous = list->hd;
	Element * current = previous->next;
	while (current) {
		if (current->x == x) {
			previous->next = current->next;
			free(current);
			return;
		}
		previous = current;
		current = current->next;

	}
}

void supprimerElementListeMem(Liste * list, Sommet * x) {
	if (!list) {
		fprintf(stderr, "supprimerElementListeMem : liste non initialisée");
		return;
	}

	if (list->hd->x == x) {
		list->hd = list->hd->next;
		return;
	}
	Element * previous = list->hd;
	Element * current = previous->next;
	while (current) {
		if (current->x == x) {
			previous->next = current->next;
			return;
		}
		previous = current;
		current = current->next;

	}
}

Element * recupMinListe(Liste * list) {
	if (!list) {
		fprintf(stderr, "recupMinListe : liste non initialisée");
		return NULL ;
	}
	Element * rem = list->hd;
	supprimerElementListeMem(list, list->hd->x);
	rem->next = NULL;
	return rem;
}

