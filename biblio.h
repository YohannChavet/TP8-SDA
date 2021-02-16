#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H


#include "livre.h"

#define CAPACITE_BIBLIO 20 // nb maximum de livres ds la bibliotheque

typedef T_livre T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
    T_tabloDeLivres etagere;
    int nbLivres;  //nb de livres actuellement ds la bibliotheque

} T_Bibliotheque;




//prototypes
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int afficherBibliotheque(const T_Bibliotheque  *ptrB);

void rechercherlivre(T_Bibliotheque * ptrB);
void rechercherauteur(T_Bibliotheque * ptrB);
void supprimer(T_Bibliotheque * ptrB);

void emprunter(T_Bibliotheque * ptrB);
void restituer(T_Bibliotheque * ptrB);

void title_sort(T_Bibliotheque * ptrB);
void author_sort(T_Bibliotheque * ptrB);
void year_sort(T_Bibliotheque * ptrB);
void swap(T_Bibliotheque * ptrB, int * index1, int * index2);

/* à faire au prochain TP !!!!!!!!!!!
void lister(T_Bibliotheque * ptrB);
void retard(T_Bibliotheque * ptrB);
*/

#endif
