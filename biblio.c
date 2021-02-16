# include "biblio.h"

void init (T_Bibliotheque *ptrB)
{
    ptrB->nbLivres=0;
    // ou (*ptrB).nbLivres=0;
}

int ajouterLivre(T_Bibliotheque  *ptrB)
{
if (ptrB->nbLivres<CAPACITE_BIBLIO)// vérifie si la bibliothèque n'est pas pleine
    {
        saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
        ptrB->nbLivres++;
        return 1;
    }
return 0;
}


int  afficherBibliotheque(const T_Bibliotheque  *ptrB)
{
    int i;
    if(ptrB->nbLivres==0)
    {
        return 0;
    }
    else
    {
        for(i=0;i<ptrB->nbLivres;i++)
        {
            afficherLivre( &(ptrB->etagere[i])  );
        }
        return 1;
    }
}


void rechercherlivre(T_Bibliotheque * ptrB)
{
    int i=0;
    int j=0;
    char titre[60];

    printf ("Quel est le titre du livre ?\n");
    scanf("%s", titre);
    for (i=0;i<ptrB->nbLivres;i++)
    {
        if (strcmp (titre,ptrB->etagere[i].titre)== 0)
        {
            j++;
            printf ("trouvé à la position %d, et %d livre avec le titre %s\n",i,j,titre);
        }
    }
    printf("fini\n");
}

void rechercherauteur(T_Bibliotheque * ptrB)
{
    int i=0;
    char auteur[20];
    printf ("Qui est l'auteur(e) du livre ?\n");
    scanf("%s", auteur);
    for (i=0;i<ptrB->nbLivres;i++)
    {
        if (strcmp (auteur,ptrB->etagere[i].auteur) == 0)
        {
            printf ("trouvé à la position %d, le livre %s avec l'auteur : %s\n",i,ptrB->etagere[i].titre,auteur);
        }
    }
    printf("fini\n");
}


void supprimer(T_Bibliotheque * ptrB)
{
    int pos=0;
    int i=0;
    printf("Quelle est la position du livre à supprimer ?\n");
    scanf("%d",&pos);

    for (i=0;i<ptrB->nbLivres;i++)
    {

        if (i>pos)
        {
            strcpy(ptrB->etagere[i-1].titre,ptrB->etagere[i].titre);
            strcpy(ptrB->etagere[i-1].auteur,ptrB->etagere[i].auteur);
            printf("supression du livre...\n");
        }
    }

ptrB->nbLivres--;
printf("fini\n");
}



void emprunter(T_Bibliotheque * ptrB)
{
    int i=0;
    char titre[60];
    char emp[20];

    printf ("quel est le titre du livre ?\n");
    scanf("%s",titre);
    for (i=0;i<ptrB->nbLivres;i++)
    {
        if (strcmp (titre,ptrB->etagere[i].titre)== 0)
        {
            printf("Qui est l'emprunteur ? entrez aussi la date au format (jj/mm/aaaa), par exemple 'Jean 16/02/2021'\n");
            scanf("%s", emp);
            strcpy(ptrB->etagere[i].emprunteur.nomemprunteur,emp);
        }
    }
    printf("fini\n");
}



void restituer(T_Bibliotheque * ptrB)
{
    int i=0;
    char titre[60];
    printf ("quel est le titre du livre\n");
    scanf("%s",titre);
    for (i=0;i<ptrB->nbLivres;i++)
    {
        if (strcmp (titre,ptrB->etagere[i].titre)== 0)
        {
            strcpy(ptrB->etagere[i].emprunteur.nomemprunteur,"\0");
        }
    }
    printf("fini\n");
}

void title_sort(T_Bibliotheque * ptrB)
{

    int n;
 
    for(n=0; n <= ptrB->nbLivres ; n++)
    {
        if (ptrB->etagere[n].titre[0] > ptrB->etagere[n+1].titre[0])
        {
            swap(ptrB, &n, &n+1);
        }
        else if (ptrB->etagere[n].titre[0] == ptrB->etagere[n+1].titre[0])
        {
            for (int j=0; (ptrB->etagere[n].titre[j] != '\0' || ptrB->etagere[n+1].titre[j] != '\0') ; j++)
            {
                if (ptrB->etagere[n].titre[j] > ptrB->etagere[n+1].titre[j])
                {
                    swap(ptrB, &n, &n+1);
                    break;
                }
            }
        }
    }
}

void author_sort(T_Bibliotheque * ptrB)
{

    int n;

    for(n=0; n <= ptrB->nbLivres ; n++)
    {
        if (ptrB->etagere[n].titre[0] > ptrB->etagere[n+1].titre[0])
        {
            swap(ptrB, &n, &n+1);
        }
        else if (ptrB->etagere[n].titre[0] == ptrB->etagere[n+1].titre[0])
        {
            for (int j=0; (ptrB->etagere[n].titre[j] != '\0' || ptrB->etagere[n+1].titre[j] != '\0') ; j++)
            {
                if (ptrB->etagere[n].titre[j] > ptrB->etagere[n+1].titre[j])
                {
                    swap(ptrB, &n, &n+1);
                    break;
                }
            }
        }
    }
}

void year_sort(T_Bibliotheque * ptrB)
{
    int j, k, minimum, ref;
    for (k=0; k <= ptrB->nbLivres;k++)
    {
        //methode de tri par selection
        minimum = ptrB->etagere[k].annee;
        ref=k;
        for(j=k+1; j<ptrB->nbLivres; j++)
        {
            if (ptrB->etagere[j].annee < minimum)
            {
                minimum = ptrB->etagere[j].annee;
                ref = j;
            }
        }
        if (ref != k) // on permute les deux livres (variables d'incides ref et k)
        {
            swap(ptrB, &ref, &k);
        }
    }
}


void swap(T_Bibliotheque * ptrB, int * ind1, int * dest2)
{
    int temp;
    char tmp[202];

    strcpy(tmp, ptrB->etagere[*ind1].titre);
    strcpy(ptrB->etagere[*ind1].titre, ptrB->etagere[*dest2].titre);
    strcpy(ptrB->etagere[*dest2].titre, tmp);

    strcpy(tmp, ptrB->etagere[*ind1].auteur);
    strcpy(ptrB->etagere[*ind1].auteur,ptrB->etagere[*dest2].auteur);
    strcpy(ptrB->etagere[*dest2].auteur, tmp);

    strcpy(tmp, ptrB->etagere[*ind1].emprunteur.nomemprunteur);
    strcpy(ptrB->etagere[*ind1].emprunteur.nomemprunteur,ptrB->etagere[*dest2].emprunteur.nomemprunteur);
    strcpy(ptrB->etagere[*dest2].emprunteur.nomemprunteur, tmp);

    strcpy(tmp,ptrB->etagere[*ind1].editeur);
    strcpy(ptrB->etagere[*ind1].editeur,ptrB->etagere[*dest2].editeur);
    strcpy(ptrB->etagere[*dest2].editeur, tmp);

    temp = ptrB->etagere[*ind1].annee;
    ptrB->etagere[*ind1].annee = ptrB->etagere[*dest2].annee;
    ptrB->etagere[*dest2].annee = temp;

    strcpy(tmp, ptrB->etagere[*ind1].code);
    strcpy(ptrB->etagere[*ind1].code, ptrB->etagere[*dest2].code);
    strcpy(ptrB->etagere[*dest2].code, tmp);
}
/* à faire au prochain TP !!!!!!!!!!!   (il me fume togtog avec ses points d'exclamations partout)
void lister(T_Bibliotheque * ptrB)
{

}

void retard(T_Bibliotheque * ptrB)
{

}

*/
