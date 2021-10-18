#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP3_A.h"

// Création nouvel élément
t_mot* creerMot(char* mot)
{
    t_mot* cellule=(t_mot*)malloc(sizeof(t_mot)); //faire un free lors de la supression de la cellule
    if(cellule!=NULL){
        cellule->mot=malloc(TAILLE_MOT*sizeof(char));
        strcpy(cellule->mot,mot); //ne pas oublier de faire un free à la fin
        cellule->nombre_occurences=1;
        cellule->suivant=NULL;
    }
    free(mot);

    return cellule;
}
/* ====== FIN creerMot ====== */

// Ajout mot dans une liste
t_mot *ajouterMot(t_mot *liste, char *mot)
{





    return NULL; // à remplacer par le code la fonctino
}
/* ====== FIN  ====== */


// Retrait occurence mot d'une liste
t_mot *retirerMot(t_mot *liste, char *mot) {
    return NULL; // à remplacer par le code la fonctino
}
/* ====== FIN ajouterMot ====== */


// Affichage mots d'un lexique
void afficherMots(t_mot *liste){
    // à remplacer par le code la fonctino
}
/* ====== FIN afficherMots ====== */


// Fusion listes
t_mot *fusionner(t_mot *listeA, t_mot *listeB){
    return NULL; // à remplacer par le code la fonctino
}
/* ====== FIN fusionner ====== */


// Import fichier de mots dans une liste
t_mot *importerFichier(t_mot *liste)
{
    return NULL; // à remplacer par le code la fonctino
}
/* ====== FIN importerFichier ====== */




// fonction utile pour vider le tampon clavier
void viderBuffer() {
    int c = '0';
    while (c!='\n' && c != EOF) { c = getchar(); }
}

//fonction en plus

char* f_creer_mot(void) //marche
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
    return mot;
}

void f_convertir_minuscule(char* mot)//marche
{
    int i=0;
    while(mot[i]!='\0'){
        //printf("%d  %c ",i,mot[i]);

        if (mot[i]>='A'&&mot[i]<='Z'){
            mot[i]+='a'-'A'; //ici ça ne marche pas
            //printf("%c\n",mot[i]);
        }

        i++;
    }
}

int f_chainesup(char* mot1,char* mot2) //si mot1>=mot2 alors 1 sinon 0, on peut regarder si c'est le même mot (si oui retourn 2 par exemple)
{
    int bol=1; //booleen
    int i=0;
    while((mot1[i]!='\0'&&mot2[i]!='\0')&&(i=1)){
        if(mot1[i]<mot2[i]){
            bol=0;
        }
        printf("%d",i);
        i++;
    }

    return bol;
}
