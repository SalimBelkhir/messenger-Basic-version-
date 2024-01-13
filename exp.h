/*#include <stdio.h>
#include <stdlib.h>

//structure et liste chainée auteurs
typedef struct auteur {
    int id_auteur;
    char * nom;
}Auteur;

typedef struct maillon_auteur{
    Auteur auteur;
    struct maillon_auteur* next;
} M_Auteur;

//structure et liste chainée message
typedef struct message {
    int id_message;
    char * titre;
    char* textes;
    char type; // "r" (réponse) ou "o" (original)
    int id_original;
    Auteur* auteur;
}Message;

typedef struct maillon_message{
    Message message;
    struct maillon_message* next;
} M_Message;

//Fonctions affichage message
void afficher_message(Message m){
    printf("Message Num: %d\nTitre: %s\nAuteur: %s\n%s\n",m.id_message,m.titre,m.auteur->nom,m.textes);
}


void afficher_Liste_Message(M_Message* mess_head){

    M_Message* cour = (M_Message*)malloc(sizeof(M_Message));

    cour=mess_head;
    while(cour!=NULL){
        afficher_message(cour->message);
        printf("\n");
        cour=cour->next;
    }
    free(cour);

}

//Ajout d'un message dans la liste
M_Message* add_message(M_Message * mess_head, Message m){
    //Initialisation maillon auteur
    M_Message* new_m=(M_Message*)malloc(sizeof(M_Message));

    new_m->message=m;
    new_m->next=mess_head;

    return new_m;
}

//Fonctions affichage auteur
void afficher_auteur(Auteur a){
    printf("Auteur Num: %d\nNom: %s\n",a.id_auteur,a.nom);
}

void afficher_Liste_Auteur(M_Auteur* aut_head){

    M_Auteur* cour = (M_Auteur*)malloc(sizeof(M_Auteur));

    cour=aut_head;
    while(cour!=NULL){
        afficher_auteur(cour->auteur);
        printf("\n");
        cour=cour->next;
    }
    free(cour);

}


//Ajout d'un auteur dans la liste
M_Auteur* add_auteur(M_Auteur * aut_head, Auteur a){
    //Initialisation maillon auteur
    M_Auteur* new_a=(M_Auteur*)malloc(sizeof(Auteur));
    new_a->auteur=a;
    new_a->next=aut_head;
    return new_a;
}

//Trouver un auteur à partir de son identifiant dans la liste chainee
Auteur* find_auteur(M_Auteur* tete, int id){
    M_Auteur* parcours=(M_Auteur*)malloc(sizeof(M_Auteur));
    parcours=tete;
    while (parcours!=NULL){

        if(parcours->auteur.id_auteur==id){

            return &(parcours->auteur);
        }
        parcours=parcours->next;

    }

    free(parcours);
    return(NULL);
}


//Ecrire un message dans un fichier
int ecrire (FILE * fp,Message m)
{

    if (fp == NULL)
    {
        fputs("Le fichier n'a pas pu être ouvert\n",stderr);
        return EXIT_FAILURE;
    }

    //Ecriture des données d'un message dans le fichier

    if (fprintf(fp,"%d\n%s\n%s\n%c\n%d\n%d\n\n",m.id_message,m.titre, m.textes, m.type,m.id_original,m.auteur->id_auteur) == EOF)
    {
        fputs("Erreur lors de l'écriture dans le fichier\n",stderr);
        return EXIT_FAILURE;
    }


    return 0;
}


//Ecrire une liste de message dans un fichier
void ecrire_liste_message(FILE * fp,M_Message * mess_head){
    M_Message * courant = (M_Message*)malloc(sizeof(M_Message));
    courant=mess_head;
    while(courant!=NULL){
        ecrire(fp,courant->message);
        courant=courant->next;
    }
    free(courant);

}

//Lire un fichier de messages et les stocker dans une liste chainée
M_Message* lire_liste_message(FILE* fp,M_Auteur* Liste_auteurs){

    M_Message * liste_m = (M_Message*)malloc(sizeof(M_Message));
    int id_a;
    Message m;

    int i;

    fseek (fp, 0, SEEK_END);
    int size = ftell(fp);
    if (0 == size) {
        printf("file is empty\n");
    }*/
    else {
        fseek (fp, 0, SEEK_SET);
        while (fscanf(fp,"%d\n",&i)==1){

            m.textes=(char*)malloc(sizeof(char));
            m.titre=(char*)malloc(sizeof(char));

            m.id_message=i;

            fgets(m.titre,256,fp);
            fgets(m.textes,256,fp);
            fscanf(fp,"\n%c\n%d\n%d\n\n",&m.type,&m.id_original,&id_a);

            m.auteur=find_auteur(Liste_auteurs,id_a);
            liste_m=add_message(liste_m,m);

            m.textes=(char*)malloc(sizeof(char));
            m.titre=(char*)malloc(sizeof(char));
        }

        afficher_Liste_Message(liste_m);
    }
    return(liste_m);
}


*/
int main (){
    //Nom du fichier
    char * nom_file ="Messages.txt";
    //Déclaration pointeur et ouverture en écriture
    FILE *fp = fopen(nom_file, "w");

    if (fp == NULL)
    {
        fputs("Le fichier n'a pas pu être ouvert\n",stderr);
        return EXIT_FAILURE;
    }

    Auteur a;
    a.id_auteur=1;
    a.nom="Ali";

    Auteur b;
    b.id_auteur=2;
    b.nom="Momo";

    Message m;
    m.id_message=5;
    m.auteur=&a;
    m.id_original=0;
    m.textes="TEXTE MESSAGE 1";
    m.titre="TITRE MESSAGE 1";
    m.type='o';

    Message m1;
    m1.id_message=10;
    m1.auteur=&b;
    m1.id_original=m.id_message;
    m1.textes="TEXTE MESSAGE 2";
    m1.titre="TITRE MESSAGE 2";
    m1.type='r';

    printf("\n*****************Creation et lecture auteurs*********************\n");

    M_Auteur* Liste_Auteur=(M_Auteur*)malloc(sizeof(M_Auteur));
    Liste_Auteur=NULL;
    Liste_Auteur=add_auteur(Liste_Auteur,a);
    Liste_Auteur=add_auteur(Liste_Auteur,b);
    afficher_Liste_Auteur(Liste_Auteur);

    printf("\n*****************Creation et lecture messages*********************\n");

    M_Message* Liste_Message=(M_Message*)malloc(sizeof(M_Message));
    Liste_Message=NULL;
    Liste_Message=add_message(Liste_Message,m);
    Liste_Message=add_message(Liste_Message,m1);
    afficher_Liste_Message(Liste_Message);

    printf("\n*****************Ecture des messages dans le fichier *********************\n");
    ecrire_liste_message(fp,Liste_Message);

    //Je ferme le fichier pour passer en mode écriture
    if (fclose(fp) == EOF)
    {
        fprintf(stderr, "Erreur lors de la fermeture du flux\n");
        return EXIT_FAILURE;
    }

    printf("\n*****************Lecture des messages a partir du fichier *********************\n");
    //Je le réouvre en mode lecture
    fp = fopen(nom_file, "r");

    if (fp == NULL)
    {
        fputs("Le fichier n'a pas pu être ouvert\n",stderr);
        return EXIT_FAILURE;
    }

    M_Message* liste_lecture=(M_Message*)malloc(sizeof(M_Message));

    liste_lecture=lire_liste_message(fp,Liste_Auteur);

    afficher_Liste_Message(liste_lecture);

    if (fclose(fp) == EOF)
    {
        fprintf(stderr, "Erreur lors de la fermeture du flux\n");
        return EXIT_FAILURE;
    }

    free(Liste_Auteur);
    free(Liste_Message);
    return 0 ;*/
}

