#ifndef PROJETLISTE_H_INCLUDED
#define PROJETLISTE_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


   struct tm date;
     typedef struct {

        char rue[50] ;
        char ville[50];
        int code_postal ;
    }adresse;

 typedef  struct {
           char titre[100];
           char text[100];
           struct tm date_de_publication ;
            int id_m;// Identifiant unique du message
            int id_original; // Identifiant du message original
            char theme_rub[20];//theme d'une rubrique
            }message;


struct message_n{
       message m;
       struct message_n* suiv_mess;//Référence au prochain message dans la liste
    };//cellule du message
    typedef struct  message_n Message;
typedef struct {
   Message* tete;


}liste_m;
    typedef struct {
        char theme[20];
        struct tm date_de_creation ;
        char adresse_email[20];
        char L_sites[10];

    }rubrique;

    struct rubrique_n
    { rubrique r;
       struct rubrique_n* suiv_rub;
    };
    typedef struct rubrique_n Rubrique;
    typedef struct {

     Rubrique* tete;

    }liste_r;

    typedef struct {
        char pseudo[20];
        struct tm premier_mess;
        struct tm dernier_mess;
        int nb_mess;
    }auteur;


    struct auteur_n{
        auteur a;
        struct auteur_n*suiv_aut ;
    };

    typedef struct auteur_n Auteur ;

    typedef struct {
        Auteur * tete ;
    }liste_a;

    typedef struct {
        int num_ins ;
        char nom[20];
        char prenom[20];
        adresse ad ;
        struct tm date_de_naissance ;
        char adresse_email[20] ;
        int num_tel ;

    }profil;

    struct profil_n{
        profil p ;
        struct profil_n* suiv_prof ;
    };

    typedef struct profil_n Profil ;

    typedef struct {
        Profil* tete ;
    }liste_p;

    typedef struct
    { char ad_net[30];
      char ad_mail[30];

    }forum;

    struct forum_n {
        forum f ;
        struct forum_n* suiv_f ;
    };
    typedef struct forum_n Forum ;
    typedef struct {
       Forum* tete;


    }liste_f;

// Définir une structure pour le Message







#endif // PROJETLISTE_H_INCLUDED
