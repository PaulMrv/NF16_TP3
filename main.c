#include <stdio.h>
#include <stdlib.h>
#include "TP3_A.h"


int main() {
    //constint taille_mot=20;

    t_mot chaine1;


    char* mot1=f_creer_mot();
    f_convertir_minuscule(mot1);
    printf("%s\n",mot1);

    char* mot2=f_creer_mot();
    f_convertir_minuscule(mot2);
    printf("%s\n",mot2);

    printf("%d\n",f_chainesup(mot1,mot2));


    //char mot[TAILLE_MOT];

    //mot="COUCOU\n";//demander au prof pk on en peut pas faire ça sans le char*
    //mot[0]='C';
    //mot[1]='\0';




    /*
    char choixMenu = '0' ;

    do {
        printf("\n========================================");
        printf("\n  [1] Afficher un lexique");
        printf("\n  [2] Ajouter un mot dans un lexique");
        printf("\n  [3] Retirer un mot d'un lexique");
        printf("\n  [4] Fusionner deux lexiques");
        printf("\n  [5] Charger un fichier dans un lexique");
        printf("\n  [6] Quitter");
        printf("\n========================================");
        printf("\nVotre choix : ");
        choixMenu = getchar();
        viderBuffer();

        switch (choixMenu) {
            case '1' :
                printf("\n\n\t<Faire Afficher un lexique>\n\n");
                break;
            case '2' :
                printf("\n\n\t<Faire Ajouter un mot dans un lexique>\n\n");
                break;
            case '3' :
                printf("\n\n\t<Faire Retirer un mot d'un lexique>\n\n");
                break;
            case '4' :
                printf("\n\n\t<Faire Fusionner deux lexiques>\n\n");
                break;
            case '5' :
                printf("\n\n\t<Faire Charger un fichier dans un lexique>\n\n");
                break;
        }
    } while (choixMenu != '6');


    printf("\n\n*** FIN DU PROGRAMME ***\n");
    */

    return 0;
}
