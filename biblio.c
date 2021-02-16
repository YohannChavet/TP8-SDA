# include "biblio.h"

void init (T_Bibliotheque *ptrB)
{

ptrB->nbLivres=0;
// ou (*ptrB).nbLivres=0;
}

int ajouterLivre(T_Bibliotheque  *ptrB)
{
if (ptrB->nbLivres<CAPACITE_BIBLIO)// reste t il de la place?
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
	return 0;
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

printf ("quel est le titre du livre\n");
scanf("%s", titre);
for (i=0;i<ptrB->nbLivres;i++)
{
	if (strcmp (titre,ptrB->etagere[i].titre)== 0)
	{
	j++;
		printf ("trouvé, à la position %d, et %d livre avec le titre %s\n",i,j,titre);
	}
}
printf("finie\n");
}

void rechercherauteur(T_Bibliotheque * ptrB)
{
int i=0;
char auteur[20];
printf ("quel est l'auteur du livre\n");
scanf("%s", auteur);
for (i=0;i<ptrB->nbLivres;i++)
{
	if (strcmp (auteur,ptrB->etagere[i].auteur) == 0)
	{
		printf ("trouvé, à la position %d, le livre %s avec l'auteur : %s\n",i,ptrB->etagere[i].titre,auteur);
	}
}
printf("finie\n");
}


void supprimer(T_Bibliotheque * ptrB)
{
int pos=0;
int i=0;
	printf("quelle livre suprimer(position) ?\n");
	scanf("%d",&pos);

	for (i=0;i<ptrB->nbLivres;i++)
	{

		if (i>pos)
		{
		strcpy(ptrB->etagere[i-1].titre,ptrB->etagere[i].titre);
		strcpy(ptrB->etagere[i-1].auteur,ptrB->etagere[i].auteur);

		printf("livre suprimer\n");
		
		}

	}

ptrB->nbLivres--;
printf("finie\n");
}



void emprunter(T_Bibliotheque * ptrB)
{
int i=0;
char titre[60];
char emp[20];

printf ("quel est le titre du livre\n");
scanf("%s",&titre);
for (i=0;i<ptrB->nbLivres;i++)
{
	if (strcmp (titre,ptrB->etagere[i].titre)== 0)
	{
	printf("quelle est le nom de l'emprunteur avec la date (jj/mm/aaaa");
	scanf("%s",&emp);
	strcpy(ptrB->etagere[i].emprunteur.nomemprunteur,emp);
	
	}
	i++;
}
printf("finie");
}



void restituer(T_Bibliotheque * ptrB)
{
int i=0;
char titre[60];
printf ("quel est le titre du livre\n");
scanf("%s",&titre);
for (i=0;i<ptrB->nbLivres;i++)
{
	if (strcmp (titre,ptrB->etagere[i].titre)== 0)
	{
		strcpy(ptrB->etagere[i].emprunteur.nomemprunteur,"\0");
	}
i++;
}
printf("finie");
}

void title_sort(T_Bibliotheque * ptrB)
{

    int i;
	char temp_titre[60];
	char temp_auteur[20];
	char temp_emprunteur[20];
	char temp_editeur[20];
	int temp_annee;
	char temp_code[20];
 
    for(i=0; ptrB->etagere[i].titre != '\0' || ptrB->etagere[i+1].titre != '\0'; i++)
    {
        if (ptrB->etagere[i].titre > ptrB->etagere[i+1].titre)
		{
           strcpy(temp_titre,ptrB->etagere[i].titre);
		   strcpy(temp_auteur,ptrB->etagere[i].auteur);
		   strcpy(temp_emprunteur,ptrB->etagere[i].emprunteur.nomemprunteur);
		   strcpy(temp_editeur,ptrB->etagere[i].editeur);
		   temp_annee = ptrB->etagere[i].annee;
		   strcpy(temp_code,ptrB->etagere[i].code);

		   strcpy(ptrB->etagere[i].titre,ptrB->etagere[i+1].titre);
		   strcpy(ptrB->etagere[i].auteur,ptrB->etagere[i+1].auteur);
		   strcpy(ptrB->etagere[i].emprunteur.nomemprunteur,ptrB->etagere[i+1].emprunteur.nomemprunteur);
		   strcpy(ptrB->etagere[i].editeur,ptrB->etagere[i+1].editeur);
		   ptrB->etagere[i].annee = ptrB->etagere[i+1].annee;		   
		   strcpy(ptrB->etagere[i].code,ptrB->etagere[i+1].code);

		   strcpy(ptrB->etagere[i+1].titre,temp_titre);
		   strcpy(ptrB->etagere[i+1].auteur,temp_auteur);
		   strcpy(ptrB->etagere[i+1].emprunteur.nomemprunteur,temp_emprunteur);
		   strcpy(ptrB->etagere[i+1].editeur,temp_editeur);
		   ptrB->etagere[i+1].annee = temp_annee;	
		   strcpy(ptrB->etagere[i+1].code,temp_code);
		}
	i++;
    }
}

void author_sort(T_Bibliotheque * ptrB)
{
    int i;
	char temp_titre[60];
	char temp_auteur[20];
	char temp_emprunteur[20];
	char temp_editeur[20];
	int temp_annee;
	char temp_code[20];
 
    for(i=0; ptrB->etagere[i].auteur != '\0' || ptrB->etagere[i+1].auteur != '\0'; i++)
    {
        if (ptrB->etagere[i].auteur > ptrB->etagere[i+1].auteur)
		{
           strcpy(temp_titre,ptrB->etagere[i].titre);
		   strcpy(temp_auteur,ptrB->etagere[i].auteur);
		   strcpy(temp_emprunteur,ptrB->etagere[i].emprunteur.nomemprunteur);
		   strcpy(temp_editeur,ptrB->etagere[i].editeur);
		   temp_annee = ptrB->etagere[i].annee;
		   strcpy(temp_code,ptrB->etagere[i].code);

		   strcpy(ptrB->etagere[i].titre,ptrB->etagere[i+1].titre);
		   strcpy(ptrB->etagere[i].auteur,ptrB->etagere[i+1].auteur);
		   strcpy(ptrB->etagere[i].emprunteur.nomemprunteur,ptrB->etagere[i+1].emprunteur.nomemprunteur);
		   strcpy(ptrB->etagere[i].editeur,ptrB->etagere[i+1].editeur);
		   ptrB->etagere[i].annee = ptrB->etagere[i+1].annee;		   
		   strcpy(ptrB->etagere[i].code,ptrB->etagere[i+1].code);

		   strcpy(ptrB->etagere[i+1].titre,temp_titre);
		   strcpy(ptrB->etagere[i+1].auteur,temp_auteur);
		   strcpy(ptrB->etagere[i+1].emprunteur.nomemprunteur,temp_emprunteur);
		   strcpy(ptrB->etagere[i+1].editeur,temp_editeur);
		   ptrB->etagere[i+1].annee = temp_annee;	
		   strcpy(ptrB->etagere[i+1].code,temp_code);
		}
		i++;
	}
}

void year_sort(T_Bibliotheque * ptrB)
{
    int temp, j, k;
    char tmp[202]
    for (k=0; k <= ptrB->nblivres)
    {
        //methode de tri par selection
            minimum = ptrB->etagere[k].annee;
            ref=k;
            for(j=k+1; j<nb; j++)
            {
                if (ptrB->etagere[j].annee < minimum)
                {
                    minimum = ptrB->etagere[j].annee;
                    ref = j;
                }
            }
            if (ref != k) // on permute les deux livres (variables d'incides k et ref)
            {
                /*temp = ptrB->etagere[k].annee;
                ptrB->etagere[k].annee = ptrB->etagere[ref].annee
                ptrB->etagere[ref].annee = temp
                *///copie ton truc pour swap tout sauf année
            }
        }
    }
}

/* à faire au prochain TP !!!!!!!!!!!   (il me fume togtog avec ses points d'exclamations partout)
void lister(T_Bibliotheque * ptrB)
{

}

void retard(T_Bibliotheque * ptrB)
{

}

*/
