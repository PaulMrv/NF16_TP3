#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP3_A.h"

// Création nouvelle cellule contenant le mot "mot"
t_mot* creerMot(char* mot) //marche
{
    t_mot* cellule=(t_mot*)malloc(sizeof(t_mot)); //faire un free lors de la supression de la cellule

    cellule->mot=malloc(TAILLE_MOT*sizeof(char));//ne pas oublier de faire un free à la fin
    strcpy(cellule->mot,mot);
    cellule->nombre_occurences=1;
    cellule->suivant=NULL;

    free(mot);

    return cellule;
}
/* ====== FIN creerMot ====== */

// Ajout mot dans une liste
//marche
t_mot *ajouterMot(t_liste liste, char *mot) //il faudra appeler la fonction f_creer_mot pour creer le mot avant l'appel de cette fonction
{

    t_mot* pointeurTete=liste;
    t_mot* nouvelleCellule;
    t_liste pred; //permet de garder l'adresse de la cellule avant liste

    nouvelleCellule=creerMot(mot); //permet de creer la cellule contenant le mot



    if(liste==NULL){
        nouvelleCellule->suivant=NULL;
        pointeurTete=nouvelleCellule;
    }
    else
        if(f_chaineSuperieur(liste->mot,nouvelleCellule->mot)){ //le nouveau mot est plus petit que celui de la tete de chaine
            pointeurTete=nouvelleCellule;
            nouvelleCellule->suivant=liste;
        }
        else
        {
            do{

                pred=liste;

                if(f_chaineEgale(nouvelleCellule->mot,liste->mot))
                {
                    liste->nombre_occurences++;
                    return pointeurTete;
                }

                liste=liste->suivant;

            } while(liste!=NULL&&f_chaineSuperieur(liste->mot,nouvelleCellule->mot)==0);

            nouvelleCellule->suivant=liste;
            pred->suivant=nouvelleCellule;

        }



    return pointeurTete;

}
/* ====== FIN  ====== */


// Retrait occurence mot d'une liste
//marche
t_mot *retirerMot(t_mot *liste, char *mot) { // Lucas
    t_mot* e=liste;
    t_mot* p=liste;

    if (liste == NULL)
    {
        printf("La liste est vide\n");
        return (liste);
    }

    if(strcmp(p->mot,mot)==0)
    {
        liste = p -> suivant;
        free(p);
        return (liste);
    }
    else
    {
        p=p->suivant;

        while(p!=NULL)
        {
            if (strcmp(p->mot,mot)==0)
            {
                if(p->nombre_occurences>1)
                {
                    p->nombre_occurences--;
                    return liste;
                }
                else
                {
                    e -> suivant = p ->suivant;
                    free(p);
                    return (liste);

                }

            }
            e=p ;
            p = p ->suivant;
        }
        printf("Le mot n'est pas dans la liste\n");
        return liste;
    }
}
/* ====== FIN ajouterMot ====== */


// Affichage mots d'un lexique
void afficherMots(t_mot *liste){ // Lucas

    int i=0;

    if(liste==NULL)
        printf("Le lexique est vide");

    while(liste!=NULL)
    {
        printf("Cellule(%d)=%s avec %d occurence\n",i,liste->mot,liste->nombre_occurences);
        liste=liste->suivant;
        i++;
    }

}
/* ====== FIN afficherMots ====== */


// Fusion listes
t_mot *fusionner(t_mot *listeA, t_mot *listeB){ // Lucas
    return NULL; // à remplacer par le code la fonctino
}
/* ====== FIN fusionner ====== */

// Import fichier de mots dans une liste
//marche si il n'y a pas de caracteres speciaux type  ( , ; : )
t_mot *importerFichier(t_mot *liste)
{
    FILE* fichier=fopen("fichier.txt","r");
    char c;
    char chaine[TAILLE_MOT];
    int i;

    do
    {
        do
        {
            //fscanf(fichier,"%c",&c);
            c=fgetc(fichier);
            //printf("$%d\n",c);
        } while((!((c>='a'&&c<='z')||(c>='A'&&c<='Z')))&&c!=EOF);
        fseek(fichier,-1,SEEK_CUR); //on revient de un en arriere avec le curseur

        i=0;
        while(((c>='a'&&c<='z')||(c>='A'&&c<='Z'))&&c!=EOF)
        {
            c=fgetc(fichier);
            if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
            {
                chaine[i++]=c;
                //printf("%c",c);
            }


            if(i>=TAILLE_MOT)
            {
                exit(EXIT_FAILURE); //le mot est trop grand pour la chaine
            }

        }
        fseek(fichier,-1,SEEK_CUR);
        chaine[i]='\0';
        if(i>0)
        liste=ajouterMot(liste,f_creer_mot_fichier(chaine,i));


    } while(c!=EOF);

    return liste;

}

/* ====== FIN importerFichier ====== */

char* f_creer_mot_fichier(char chaine[TAILLE_MOT],int taille) //taille= longueur du mot (ex: papa => n=4)
{

    char* mot=malloc(taille*sizeof(char));
    char c;
    int i=0, bool1=1;

    for(i=0;i<=taille;i++)
    {
        mot[i]=chaine[i];
    }

    f_convertir_minuscule(mot);
    return mot;
}


// fonction utile pour vider le tampon clavier
void viderBuffer() {
    int c = '0';
    while (c!='\n' && c != EOF) { c = getchar(); }
}

//fonction en plus

//crée un mot qui est rentré par l'utilisateur
char* f_creer_mot(void) //marche, mais ne s'arrete pas si on ne rentre pas autre chose que entrer
{
    char* mot=malloc(TAILLE_MOT*sizeof(char));
    char c;
    int i=0, bool1=1;

    printf("Rentrez un mot (terminer par entree):");
    do{
        c=getchar();

        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
            mot[i]=c;
            i++;
        }
        else{
            bool1=0;
            mot[i]='\0';
        }
    }while(bool1);

    f_convertir_minuscule(mot);
    return mot;
}

//converti un mot en un mot en minuscule
//marche
void f_convertir_minuscule(char* mot)
{
    int i=0;
    while(mot[i]!='\0'){
        //printf("%d  %c ",i,mot[i]);

        if (mot[i]>='A'&&mot[i]<='Z'){
            mot[i]+='a'-'A';
        }

        i++;
    }
}



//marche
int f_chaineSuperieur(char* mot1,char* mot2) //si mot1>mot2 alors 1 sinon 0
{

    int i=0;

    while(mot2[i]!='\0'){

        if(mot1[i]<mot2[i])
            return 0;
        if(mot1[i]>mot2[i])
            return 1;
        i++;
    }
    if(mot1[i]!='\0')
        return 1;

    return 0;
}


//marche
int f_chaineEgale(char* mot1,char* mot2) //si meme chaine alors 1, sinon 0
{
    int bol=1;
    int i=0;
    while ((mot1[i]!='\0')&&(bol==1)){
        if (mot1[i]!=mot2[i])
            bol=0;
        i++;
    }
    if(mot2[i]!='\0')
        bol=0;
    return bol;
}

//si on veut continuer (1) sinon (0)
int continuer(void) //marche
{
    int i;
    do{
        printf("voulez-vous continuer? [Oui=1 Non=0]");
        scanf("%d",&i);
        rewind(stdin); //vider le buffer
    }
    while (i!=1&&i!=0);

    return i;
}

