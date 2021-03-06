// TP GESTION D'UNE BIBLIOTHEQUE 
#include "biblio.h"

void lectureFichierTXT();

int menu()
{
    int choix;
// au programme du TP6 :
printf("\n\n 1 - ajouter un nouveau livre dans la bibliotheque "); 
printf("\n 2 - afficher tous les livres de la bibliotheque "); 
printf("\n 3 - rechercher un livre (par son titre)");  // il peut y avoir plusieurs livres de même titre. Dans ce cas, indiquez le nombre d'exemplaires disponibles
printf("\n 4 - rechercher et afficher tous les livres d'un auteur");
printf("\n 5 - supprimer un livre de la bibliotheque");
// si les 5 choix ci dessus sont bien codés, modifiez votre structure T_Livre et passez à 5 champs (avec cote,editeur et annee)


// au programme du TP7 :
// ajouter le champ emprunteur à votre structure T_Livre

printf("\n 6 - emprunter un livre de la bibliotheque");
printf("\n 7 - restituer/rendre un livre de la bibliotheque");
printf("\n 8 - trier les livres (par titre)");
printf("\n 9 - trier les livres (par auteur)");
printf("\n 10 - trier les livres (par annee)");

// si les 5 choix (6-10) sont bien codés, changez le type T_Emp et remplacez-le par la structure T_Emp visible dans livre.h
// vous pourrez alors faire les menus 11,12,etc...
printf("\n 11- lister les livres disponibles "); 
printf("\n 12 - lister les emprunts en retard "); //on suppose qu'un emprunt dure 7 jours.
//printf("\n 13 - lire la date systeme(bonus)");
//printf("\n 14 - changer la place de livres entre eux(bonus)");

printf("\n 0 - QUITTER");
printf("\n Votre choix : ");
scanf("%d",&choix);
getchar();
return choix;
}


void sauvegarde(T_Bibliotheque *ptrB)
{
    FILE *fic=NULL; //le type FILE
    int i;
    fic=fopen("baseLivres","w"); // w = le mode = write avec ECRASEMENT
    //fopen renvoie NULL si probleme (disque plein, disque non accessible ...
    if (fic!=NULL)
    {
        for(i=0;i<ptrB->nbLivres;i++)
        {
            //fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
            fwrite(&(ptrB->etagere[i]), sizeof(T_livre), 1, fic);
        }
        fclose(fic);
        puts("SAUVEGARDE REUSSIE ..............");
    }
        else 
        {
            puts("ECHEC DE SAUVEGARDE  !!!!!  ");
        }
}


void chargement(T_Bibliotheque *ptrB)
{
    FILE *fic=NULL; //le type FILE
    int i=0;
    fic=fopen("baseLivres","r"); // r = le mode read
    //fopen renvoie NULL si probleme (disque plein, disque non accessible ...
    if (fic!=NULL)
    {
        do
        {
            fread(  &(ptrB->etagere[i]) ,sizeof(T_livre),1,fic);
            i++;
        } while(!feof(fic));
        
        fclose(fic);
        ptrB->nbLivres=i-1;
        puts("CHARGEMENT  REUSSI ..............\n");
    }
    else
    {
        puts("ECHEC DE CHARGEMENT  !!!!!  \n");
    }

}




int main() // début de la fonction main
{ 
int reponse, choice;
//int dest;

T_Bibliotheque B; 
init( &B );

chargement(&B);

do
{

    choice = menu();

    switch(choice)
    {
        case 0 :
        {
            break;
        }
        case  1 :
        {
            reponse = ajouterLivre(   &B  );
            if (reponse==1)
            {
                printf(" ajout reussi !!");
            }
            else
            {
            printf("impossible d'ajouter (bibliotheque pleine)\n");
            }
            break;
        }

        case 2 :
        {
            reponse=afficherBibliotheque(&B);
            if (reponse==0)
            {
                printf("La bibliotheque est vide\n");
            }
            break;
        }
        
        case 3:
        {
            rechercherlivre(&B);
            break;
        }
        
        case 4:
        {
            rechercherauteur(&B);
            break;
        }
        
        case 5:
        {
            supprimer(&B);
            break;
        }
        
        case 6:
        {
            emprunter(&B);
            break;
        }
        
        case 7:
        {
            restituer(&B);
            break;
        }
        
        case 8:
        {
            title_sort(&B);
            break;
        }
        
        case 9:
        {
            author_sort(&B);
            break;
        }
        
        case 10:
        {
            year_sort(&B);
            break;
        }
        
        case 11:
        {
            lister(&B);
            break;
        }
        
        case 12:
        {
            retard(&B);
            break;
        }
        /*
        case 13:
        {
            lireDateSysteme(&B);
        }
        case 14:
        {
            printf("entrez les livres que vous voulez permuter sous la forme 'X Y' (par exemple pour permuter les livres 1 et 2 entrez '1 2'");
            scanf("%d %d", &reponse, &dest);
            getchar();
            swap(&B, &reponse, &dest);
        }*/
        default:
        {
            printf("Votre valeur n'a aucune correspondance avec celles disponibles.\n");
        }
    }

} while(choice != 0);

sauvegarde(&B);
} // fin de la fonction main

void lectureFichierTXT()
{
    FILE *fic=NULL; //le type FILE
    char c;
    fic=fopen("fic.txt","rt"); // r = le mode read   w = mode write (avec ecrasement)
    //fopen renvoie NULL si probleme (fichier effac� , disque non accessible ...
    if (fic!=NULL)
    {
        do
        {
            fscanf(fic,"%c",&c);
            printf(">%c<",c);
        } while(!feof(fic));

        fclose(fic);
        puts("\nLECTURE REUSSIE ..............");
    }
    else
    {
        puts("ECHEC DE LECTURE DU FICHIER TXT !!!!!  ");
    }
}

