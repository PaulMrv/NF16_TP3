#include <stdio.h>
#include <stdlib.h>
#include "TP3_A.h"
#include "TP3_B.h"
#define TAILLE_TABLEAU 10


int main() {

    int i;
    t_liste tabLexique[TAILLE_TABLEAU];
    for(i=0;i<TAILLE_TABLEAU;i++)
        tabLexique[i]=NULL;

    char choixMenu = '0' ;
    int choixLexique;


    do {
        system("cls");
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

                printf("\n\n\t<Faire Afficher le lexique>\n\n");
                do{
                printf("Lexique numero:");
                scanf("%d",&choixLexique);
                rewind(stdin);
                } while (!(choixLexique<=TAILLE_TABLEAU&&choixLexique>0));

                afficherMots(tabLexique[choixLexique-1]);

                getchar();
                break;
            case '2' :

                printf("\n\n\t<Faire Ajouter un mot dans un lexique>\n\n");
                do{
                printf("Dans le lexique numero:");
                scanf("%d",&choixLexique);
                rewind(stdin);
                } while (!(choixLexique<=TAILLE_TABLEAU&&choixLexique>0));

                do{
                tabLexique[choixLexique-1]=ajouterMot(tabLexique[choixLexique-1],f_creer_mot());
                } while(continuer());

                getchar();
                break;

            case '3' :

                printf("\n\n\t<Faire Retirer un mot d'un lexique>\n\n");
                do{
                printf("Dans le lexique numero:");
                scanf("%d",&choixLexique);
                rewind(stdin);
                } while (!(choixLexique<=TAILLE_TABLEAU&&choixLexique>0));

                do{
                tabLexique[choixLexique-1]=retirerMot(tabLexique[choixLexique-1],f_creer_mot());
                } while(continuer());

                getchar();
                break;

            case '4' :

                printf("\n\n\t<Faire Fusionner deux lexiques>\n\n");
                getchar();
                break;

            case '5' :

                printf("\n\n\t<Faire Charger un fichier dans un lexique>\n\n");
                do{
                printf("Dans le lexique numero:");
                scanf("%d",&choixLexique);
                rewind(stdin);
                } while (!(choixLexique<=TAILLE_TABLEAU&&choixLexique>0));


                tabLexique[choixLexique-1]=importerFichier(tabLexique[choixLexique-1]);

                printf("Fichier sauvegarde dans le lexique numero %d",choixLexique);

                getchar();
                break;
        }
    } while (choixMenu != '6');


    printf("\n\n*** FIN DU PROGRAMME ***\n");


    return 0;
}


