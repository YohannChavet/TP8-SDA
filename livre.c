#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
   lireChaine("CODE :", (ptrL->code), MAX);
    lireChaine("TITRE :", (ptrL->titre), MAX_TITRE);
    lireChaine("AUTEUR :", (ptrL->auteur), MAX);
    lireChaine("EDITEUR :", (ptrL->editeur), MAX);
    scanf("%d", &ptrL->annee);
    lireChaine("EMPRUNTEUR :", (ptrL->emprunteur.nomemprunteur), MAX);
}

void afficherLivre(const T_livre *ptrL)
{
    afficherChaine("TITRE :", (ptrL->titre));
    printf(" - ");
    afficherChaine("AUTEUR :", (ptrL->auteur));
    printf(" - ");
    afficherChaine("EDITEUR :", (ptrL->editeur));
    printf("\n");

    printf("ANNEE : %d", (ptrL->annee));
    printf(" - ");
    afficherChaine("EMPRUNTEUR :", (ptrL->emprunteur.nomemprunteur));
    printf(" - ");
    afficherChaine("CODE :", (ptrL->code));
    printf("\n");
}

