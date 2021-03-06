#ifndef TP3_H_INCLUDED
#define TP3_H_INCLUDED
#define TAILLE_MOT 20
#define MAX_CARACTERE 1000

struct s_mot {
    char* mot;
    int nombre_occurences;
    struct s_mot* suivant; //il y avait une erreur dans le fichier de base
};

typedef struct s_mot t_mot;
typedef t_mot* t_liste; //type des pointeurs tetes de listes


t_mot *creerMot(char *mot);

t_mot *ajouterMot(t_mot *liste, char *mot); //un pointeur vers la tete de la liste

t_mot *retirerMot(t_mot *liste, char *mot);

void afficherMots(t_mot *liste);

t_mot *fusionner(t_mot *listeA, t_mot *listeB);

t_mot *importerFichier(t_mot *liste);

void liberationliste(t_liste liste); //a faire



// fonction utile pour vider le tampon clavier
void viderBuffer() ;

char* f_creer_mot(void);
void f_convertir_minuscule(char* mot);
int f_chaineSuperieur(char* mot1,char* mot2);
int f_chaineEgale(char* mot1,char* mot2);
int continuer(void);

char* f_creer_mot_fichier(char chaine[TAILLE_MOT],int taille);

#endif // TP3_H_INCLUDED
