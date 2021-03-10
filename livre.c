#include "livre.h"

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void saisirLivre(T_livre * ptrL)
{
    lireChaine("CODE :", (ptrL->code), MAX);
    lireChaine("TITRE :", (ptrL->titre), MAX_TITRE);
    lireChaine("AUTEUR :", (ptrL->auteur), MAX);
    lireChaine("EDITEUR :", (ptrL->editeur), MAX);
    printf("ANNEE : ");
    scanf("%d", &ptrL->annee);
    viderBuffer();
    strcpy(ptrL->emprunteur.nomemprunteur, "aucun");
    //lireChaine("EMPRUNTEUR :", (ptrL->emprunteur.nomemprunteur), MAX);
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
    printf("\n\n");
}

void lireSecondSysteme(T_Emp *E)
{

system("date > ladate"	);
FILE * fic=NULL;  // pointeur de fichier
fic=fopen("ladate","r"); //fileOpen en mode 'r'EAD
}


