# include "biblio.h"
#include <time.h>

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


int afficherBibliotheque(const T_Bibliotheque  *ptrB)
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
            printf("Livre %d:\n", i);
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
    fgets(titre, 60, stdin);
    if (titre[strlen(titre)-1] == '\n')
    {
        titre[strlen(titre)-1] = '\0';
    }
    
    for (i=0;i<ptrB->nbLivres;i++)
    {
        if (strcmp (titre,ptrB->etagere[i].titre)== 0)
        {
            if (j == 0)
            {
                printf("trouvé à la position ");
            }
            j++;
            printf("%d, ",i);
        }
    }
    if (j>0)
    {
        printf ("pour un total de %d ",j);
    }
    if (j>1)
    {
        printf("livres avec le titre '%s'\n",titre);
    }
    if (j==1)
    {
        printf("livre avec le titre '%s'\n",titre);
    }
    printf("fini\n");
}

void rechercherauteur(T_Bibliotheque * ptrB)
{
    int i=0, j=0;
    char auteur[20];
    printf ("Qui est l'auteur(e) du livre ?\n");
    fgets(auteur, 20, stdin);
    if (auteur[strlen(auteur)-1] == '\n')
    {
        auteur[strlen(auteur)-1] = '\0';
    }
    for (i=0;i<ptrB->nbLivres;i++)
    {
        if (strcmp (auteur,ptrB->etagere[i].auteur) == 0)
        {
            if (j == 0)
            {
                printf("trouvé à la position ");
            }
            j++;
            printf("%d, ",i);
        }
    }
    if (j>0)
    {
        printf ("pour un total de %d ", j);
    }
    if (j>1)
    {
        printf("livres de l'auteur '%s'\n", auteur);
    }
    if (j==1)
    {
        printf("livre de l'auteur '%s'\n", auteur);
    }
    printf("fini\n");
}


void supprimer(T_Bibliotheque * ptrB)
{
    int pos=0;
    int i=0;
    printf("Quelle est la position du livre a supprimer ?\n");
    scanf("%d",&pos);
    getchar();

    for (i=0;i<ptrB->nbLivres;i++)
    {

        if (i>pos)
        {
            strcpy(ptrB->etagere[i-1].titre,ptrB->etagere[i].titre);
            strcpy(ptrB->etagere[i-1].auteur,ptrB->etagere[i].auteur);
            strcpy(ptrB->etagere[i-1].code,ptrB->etagere[i].code);
            strcpy(ptrB->etagere[i-1].editeur,ptrB->etagere[i].editeur);
            ptrB->etagere[i-1].annee = ptrB->etagere[i].annee;
            strcpy(ptrB->etagere[i-1].emprunteur.nomemprunteur,ptrB->etagere[i].emprunteur.nomemprunteur);
        }
    }
    printf("supression du livre...\n");

ptrB->nbLivres--;
printf("fini\n");
}



void emprunter(T_Bibliotheque * ptrB)
{
    int i=0;
    char emp[20];

    printf("Quelle est la position du livre a emprunter ?\n");
    scanf("%d",&i);
    getchar();
    if (strcmp(ptrB->etagere[i].emprunteur.nomemprunteur, "aucun") != 0)
    {
        printf("impossible d'emprunter ce livre, il est actuellement pris par '%s'\n", ptrB->etagere[i].emprunteur.nomemprunteur);
        return;
    }
    printf("Qui est l'emprunteur ?\n");
    fgets(emp, 20, stdin);
    system("date > ladate");
    strcpy(ptrB->etagere[i].emprunteur.nomemprunteur,emp);

    printf("fini\n");
}



void restituer(T_Bibliotheque * ptrB)
{
    int pos;
    printf("Quelle est la position du livre a restituer ?\n");
    scanf("%d",&pos);
    getchar();
    strcpy(ptrB->etagere[pos].emprunteur.nomemprunteur,"aucun");
    
    printf("fini\n");
}

void title_sort(T_Bibliotheque * ptrB)
{

    int n;
 
    for(n=0; n < ptrB->nbLivres ; n++)
    {
        if (ptrB->etagere[n].titre[0] > ptrB->etagere[n+1].titre[0])
        {
            swap(ptrB, &n, &n+1);
        }
        else if (ptrB->etagere[n].titre[0] == ptrB->etagere[n+1].titre[0])
        {
            for (int j=0; (ptrB->etagere[n].titre[j] != '\0' && ptrB->etagere[n+1].titre[j] != '\0') ; j++)
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

    for(n=0; n < ptrB->nbLivres ; n++)
    {
        if (ptrB->etagere[n].auteur > ptrB->etagere[n+1].auteur)
        {
            swap(ptrB, &n, &n+1);
        }
        else if (ptrB->etagere[n].auteur[0] == ptrB->etagere[n+1].auteur[0])
        {
            for (int j=0; (ptrB->etagere[n].auteur[j] != '\0' && ptrB->etagere[n+1].auteur[j] != '\0') ; j++)
            {
                if (ptrB->etagere[n].auteur[j] > ptrB->etagere[n+1].auteur[j])
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

void lister(T_Bibliotheque * ptrB)
{

    int i=0;
    for (i=0;i<ptrB->nbLivres;i++)
    {
        if (strcmp ("aucun",ptrB->etagere[i].emprunteur.nomemprunteur)== 0)
        {
            
            afficherLivre( &(ptrB->etagere[i])  );
        }
    }
    printf("fini\n");
}




void retard(T_Bibliotheque * ptrB)
{

    int i=0;
    for (i=0;i<ptrB->nbLivres;i++)
    {
        if (ptrB->etagere[i].emprunteur.lannee > ptrB->etagere[i].emprunteur.lannee+1)
        {
            
            afficherLivre( &(ptrB->etagere[i]) );
        }

        else if (ptrB->etagere[i].emprunteur.lemois > (ptrB->etagere[i].emprunteur.lemois+1))
        {
            
            afficherLivre( &(ptrB->etagere[i]) );
        }

        else if (ptrB->etagere[i].emprunteur.lemois > (ptrB->etagere[i].emprunteur.lemois+1) && (ptrB->etagere[i].emprunteur.lejour))
        {
            
            afficherLivre( &(ptrB->etagere[i]) );
        }

        else if (ptrB->etagere[i].emprunteur.lejour > (ptrB->etagere[i].emprunteur.lejour+7))
        {
            
            afficherLivre( &(ptrB->etagere[i]) );
        }
    }
    printf("fini\n");
}

/*
void retard(T_Bibliotheque * ptrB)
{

    int i=0;
    for (i=0;i<ptrB->nbLivres;i++)
    {
        if (system("date") > (lireSecondSysteme(E)+604800))
        {
            
            afficherLivre( &(ptrB->etagere[i]) );
        }

    }
    printf("fini\n");
}

*/
void lireDateSysteme(T_Emp *E)
{
    char j[9],m[10],h[9],mer[11],vir[2];
    int d,a;
    

    system("date > ladate"	);
    FILE * fic=NULL;  // pointeur de fichier
    fic=fopen("ladate","r"); //fileOpen en mode 'r'EAD

    //ici , si fic vaut NULL, alors le fopen a indiqué
    //que le fichier ladate n'est pas accessible
    
    if (fic == NULL)
    {
        printf("probleme de date systeme !!");
        //on range une date irréelle 
        E->lejour=dimanche;
        E->ladate=99;
        E->lemois=decembre;
        E->lannee=-999;
    }
    else
    {
        while(!feof(fic))	
        {
            fscanf(fic,"%s %d %s %d %s %s %s",j,&d,m,&a,vir,h,mer);		
            if (!feof(fic))
            {
                printf("\n-->LU : %s- %d- %s- %d- %s- %s",j,d,m,a,h,mer);		
            }
        }
     }
     fclose(fic);
	
    if (strcmp(j,"lundi")==0) E->lejour=lundi;
    if (strcmp(j,"mardi")==0) E->lejour=mardi;
    if (strcmp(j,"mercredi")==0) E->lejour=mercredi;
    if (strcmp(j,"jeudi")==0) E->lejour=jeudi;
    if (strcmp(j,"vendredi")==0) E->lejour=vendredi;
    if (strcmp(j,"samedi")==0) E->lejour=samedi;
    if (strcmp(j,"dimanche")==0) E->lejour=dimanche;

    E->ladate=d;

    if (strcmp(m,"janvier")==0) E->lemois=janvier;
    if (strcmp(m,"fevrier")==0) E->lemois=fevrier;
    if (strcmp(m,"mars")==0) E->lemois=mars;
    if (strcmp(m,"avril")==0) E->lemois=avril;
    if (strcmp(m,"mai")==0) E->lemois=mai;
    if (strcmp(m,"juin")==0) E->lemois=juin;
    if (strcmp(m,"juillet")==0) E->lemois=juillet;
    if (strcmp(m,"aout")==0) E->lemois=aout;
    if (strcmp(m,"septembre")==0) E->lemois=septembre;
    if (strcmp(m,"octobre")==0) E->lemois=octobre;
    if (strcmp(m,"novembre")==0) E->lemois=novembre;
    if (strcmp(m,"decembre")==0) E->lemois=decembre;

    E->lannee=a;

	

}
