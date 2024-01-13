#include <stdio.h>
#include <stdlib.h>
#include"forum_version_dynamique_header_file.h"
#include<string.h>
void saisie_message(message* m,int* val_mess);
void ajouter_debut_mess(liste_m* l ,message m);
void afficher_liste_mess(liste_m* l);
void trouver_reponses( message m,liste_m* l);
void  chercher_messages_par_rubrique( liste_m* l,rubrique* r);
void saisie_auteur(auteur* b);
void ajouter_debut_aut(liste_a* l ,auteur b);
void ajouter_debut_forum(liste_f* l,forum f);
void afficher_liste_aut(liste_a* l);
void afficher_liste_rub(liste_r* l);
profil saisie_profil();
forum saisie_forum();
void afficher_liste_forum(liste_f l);

void afficher_liste_profil(liste_p l);

void afficher_liste_profil(liste_p l);
void ajouter_debut_prof(liste_p* l , profil p1);


rubrique saisie_rub();
void ecrit_list_message(FILE *f ,liste_m *l);
void lire_liste_message(FILE* f ,liste_m* lm);
void append_message(liste_m* lm,message msg);
int main()
 {
  /*message m1,m2,m3;
  int val_mess=1;
  saisie_message(&m1,&val_mess);
  saisie_message(&m2,&val_mess);
  saisie_message(&m3,&val_mess);
  liste_m l;
  l.tete=NULL;
  ajouter_debut_mess(&l,m1);
  ajouter_debut_mess(&l,m2);
  ajouter_debut_mess(&l,m3);
  afficher_liste_mess(&l);
  trouver_reponses(m1,&l);
  rubrique r;
  r=saisie_rub();
  liste_r l2;
  afficher_liste_rub(&l2);
chercher_messages_par_rubrique( &l,&r);


auteur a1;//a2;
     liste_a l1;
     l1.tete=NULL;
     saisie_auteur(&a1);
    // saisie_auteur(&a2);
     ajouter_debut_aut(&l1,a1);
   // ajouter_debut_aut(&l1,a2);
     afficher_liste_aut(&l1);
 profil p1;
 p1=saisie_profil();
 liste_p l3;
  l3.tete=NULL;
 ajouter_debut_prof(&l3,p1);
 afficher_liste_profil(l3);
 forum f1,f2;
  f1=saisie_forum();
  f2=saisie_forum();
  liste_f l4;
  l4.tete=NULL;
  ajouter_debut_forum(&l4,f1);
  ajouter_debut_forum(&l4,f2);
  afficher_liste_forum(l4);*/

  //manipulation de fichier


  char* f_nom = "message.txt";
  //definir le nom de fichier
  FILE* f = fopen(f_nom,"w");
  // creer un fichier de cette nom
  int n ;
  printf("saisir le nombre des messages dans la liste \n");
  scanf("%d",&n);
  //definir un list de message et la intitialise
  liste_m lm ;
  lm.tete=NULL ;
  int val_mess = 1 ;
  for(int i =0 ; i<n ; i++)
  {
      //saisir n messages et la inserer al fin de la list
      message msg ;
      //int val_mess ;
      //printf("ecrire l'identifiant unique d'un message :\n");
      //scanf("%d",&val_mess);
      saisie_message(&msg,&val_mess);
      Message* node = malloc(sizeof(Message));
      append_message(&lm,msg);
  }
  //ecrire les messages dans la fichier
  ecrit_list_message(f,&lm);
  //affichage de la list
  afficher_liste_mess(&lm);
  //examiner si la fermeture de la ficher est succees pour l'ouvrir en mode lecture
  if(fclose(f)!=0){
    fputs("la fermeture de fichier n'est pas succees",stderr);
    return EXIT_FAILURE ;
  }
  //supprimer les elements de la list des messages et la initialser
  Message* parc;
  parc=lm.tete;
  while(parc!=NULL){
    free(parc);
    parc=parc->suiv_mess;
  }
  lm.tete=NULL ;
  //on affiche la list des messages pour verifie si elle est vide ou non
  afficher_liste_mess(&lm);
  f=fopen(f_nom,"r");
  //lire les donnees de fichier et les populer sur la list des messages
  lire_liste_message(f,&lm);
  afficher_liste_mess(&lm);
  //fermeture de la fichier
  if(fclose(f)!=0){
    fputs("la fermeture de fichier n'est pas succees",stderr);
    return EXIT_FAILURE ;
  }

  return 0;
}
void append_message(liste_m* lm,message msg){
    Message* nodem = malloc(sizeof(Message));
    Message* parc ;
    nodem->m = msg ;
    nodem->suiv_mess = NULL ;
    if(lm->tete==NULL) lm->tete =nodem ;
    else{
            parc=lm->tete;
            while(parc->suiv_mess!=NULL){
                parc=parc->suiv_mess;
            }
        parc->suiv_mess = nodem ;
    }
}
void saisie_auteur(auteur* b)

   {printf("saisir le pseudo");

     scanf("%s",b->pseudo);

     printf("saisir la date du premier_mess");

      scanf("%d%d%d",&b->premier_mess.tm_mday,&b->premier_mess.tm_mon,&b->premier_mess.tm_year);
     printf("saisir la date du dernier_mess");

       scanf("%d%d%d",&b->dernier_mess.tm_mday,&b->dernier_mess.tm_mon,&b->dernier_mess.tm_year);
        printf("donner nombre message");
       scanf("%d",&b->nb_mess);
  }
 profil saisie_profil()
  {
       profil p ;

       printf("saisir le numero d'inscription du profil: ");
       scanf("%d",&p.num_ins);
       printf("saisir le nom: ");
       scanf("%s",p.nom);
       printf("saisir le prenom: ");
       scanf("%s",p.prenom);
       printf("saisir l'adresse: ");
       scanf("%s%s%d",p.ad.rue,p.ad.ville,&p.ad.code_postal);
       printf("saisir le date de naissance: ");
       scanf("%d%d%d",&p.date_de_naissance.tm_mday,&p.date_de_naissance.tm_mon,&p.date_de_naissance.tm_year);
       printf("saisir l'adresse mail: ");
       scanf("%s",p.adresse_email);
       printf("saisir le numero de telephone: ");
       scanf("%d",&p.num_tel);
       return p;
   }



// Création de messages avec des identifiants uniques
 void saisie_message(message*m,int* val_mess){



   printf("saisir le titre du message: \n");
   //pour eviter les problems de sauter des saisir de titre
   getchar();
   //au place de scanf("%s",m->titre); pour compter les espaces dans le titre
   gets(m->titre);
   printf("saisir le texte: \n");
   //au place de scanf("%s",m->text); pour compter les espaces dans le text
   gets(m->text);
   printf("saisir la date de publication: \n");
   scanf("%i %i %i",&m->date_de_publication.tm_mday,&m->date_de_publication.tm_mon,&m->date_de_publication.tm_year);
    m->id_m=*val_mess;
   (*val_mess)++;
   int reponse;
   printf("tapez 1 si c'est une reponse\n");
   scanf("%d",&reponse);
   printf("donner le theme du rubrique\n");
   //pour eviter de sauter le saisir de rubrique
   getchar();
   //scanf("%s",m->theme_rub);
   gets(m->theme_rub);
   if(reponse==0)
     m->id_original=0;
   else
      {printf("donner numero message originale \n");
      int i;
      scanf("%d",&i);
      m->id_original=i;}
 }

rubrique saisie_rub()
{
    rubrique r ;
    printf("saisir le theme du rubrique:");
    scanf("%s",r.theme);
    printf("saisie le date de creation du rubrique :");
    scanf("%02d/%02d/%d",&r.date_de_creation.tm_mday,&r.date_de_creation.tm_mon,&r.date_de_creation.tm_year);
    printf("saisir l'adresse mail du rubrique :");
    scanf("%s",r.adresse_email);
    printf("saisir la liste des sites :");
    scanf("%s",r.L_sites);

    return r;
}

void ajouter_debut_aut(liste_a* l ,auteur b)
{ Auteur* aut;
  aut=malloc(sizeof(Auteur));
  aut->a=b;
  aut->suiv_aut=l->tete;
  l->tete=aut;}

void ajouter_debut_prof(liste_p* l , profil p1)
{
    Profil* prof ;
    prof=malloc(sizeof(Profil));
    prof->p=p1 ;
    prof->suiv_prof=l->tete;
    l->tete=prof;
}
void ajouter_debut_mess(liste_m* l , message m1)
{
    Message* message ;
    message=malloc(sizeof(Message));
    message->m=m1;
    message->suiv_mess=l->tete;
    l->tete=message;
}

void afficher_liste_mess(liste_m* l)
{   Message* parc;
    if(l->tete==NULL)
      printf("liste vide\n");
   else
     parc=l->tete;
     while(parc!=NULL)
         {printf("le message numero %d est du titre : %s du texte: %s du theme : %s et publie  en (%d/%d/%d)\n"
                 ,parc->m.id_m,parc->m.titre,parc->m.text,parc->m.theme_rub
                 ,parc->m.date_de_publication.tm_mday
                 ,parc->m.date_de_publication.tm_mon
                 ,parc->m.date_de_publication.tm_year);
         //chaque message a son identifieur unique
         // l'identifieur original id_original est 0 pour un message sans reponse
         //sinon il egal a l'identifieur unique de la message repondu
         if(parc->m.id_original != 0){printf("la message repond a la message de numero %d \n",parc->m.id_original);}
          parc=parc->suiv_mess;}

}

void ajouter_debut_rub(liste_r* l ,rubrique r1)
{ Rubrique* rub;
  rub=malloc(sizeof(Rubrique));
  rub->r=r1;
  rub->suiv_rub=l->tete;
  l->tete=rub;}
  forum saisie_forum(){
    forum f ;
    printf("saisir l'adresse mail du forum: \n ");
    scanf("%s",f.ad_mail);
    printf("saisir l'adresse net du forum: \n");
    scanf("%s",f.ad_net);
    return f;
}


void ajouter_debut_forum(liste_f* l ,forum f)
{ Forum * forum;
  forum=malloc(sizeof(Forum));
   forum->f=f;
   forum->suiv_f=l->tete;

  l->tete=forum;}
void afficher_liste_forum(liste_f l)
{ if(l.tete==NULL)
      printf("liste vide");
   else
   { Forum* parc;
     parc=l.tete;
     while(parc!=NULL)
        { printf("l'adresse  internet %s et l'adresse email est %s ",parc->f.ad_net,parc->f.ad_mail );
          parc=parc->suiv_f;}
   }
}
void afficher_liste_rub(liste_r* l)
{ if(l->tete==NULL)
      printf("liste vide");
   else
   { Rubrique* parc;
     parc=l->tete;
     while(parc!=NULL)
         {printf("le theme est %s , la date de creation est: %02d/02%d/%d , l'adresse email est: %s , la liste des sites est: %s",parc->r.theme ,parc->r.date_de_creation.tm_mday ,parc->r.date_de_creation.tm_mon ,parc->r.date_de_creation.tm_year,parc->r.adresse_email ,parc->r.L_sites );
          parc=parc->suiv_rub;}
   }
}



void afficher_liste_profil(liste_p l)
{if(l.tete==NULL)
      printf("liste vide");
   else
   { Profil* parc;
     parc=l.tete;
     while(parc!=NULL)
        { printf("le numero d'inscription est :%d\n le nom est : %s\n le prenom est : %s\n adresse  est :( %s,%s,%d)\n  la date de naisssance  est : (%02d/%02d/%d)\n L''adresse email est : %s\n le numero de telephone est : %d",parc->p.num_ins,parc->p.nom,parc->p.prenom,parc->p.ad.rue,parc->p.ad.ville,parc->p.ad.code_postal,parc->p.date_de_naissance.tm_mday,parc->p.date_de_naissance.tm_mon,parc->p.date_de_naissance.tm_year,parc->p.adresse_email,parc->p.num_tel);

          parc=parc->suiv_prof;}
   }}


void afficher_liste_aut(liste_a* l)
{   if(l->tete==NULL)
      printf("liste vide");
    else
      { Auteur* parc;
      parc=l->tete;
      while(parc!=NULL)
         {printf("le pseudo est : %s , la date du premier message est : %02d/%02d/%d , la date du dernier de message %02d/%02d/%d ,le nombre des messages :%d",parc->a.pseudo ,parc->a.premier_mess.tm_mday,parc->a.premier_mess.tm_mon ,parc->a.premier_mess.tm_year ,parc->a.dernier_mess.tm_mday ,parc->a.dernier_mess.tm_mon ,parc->a.dernier_mess.tm_year,parc->a.nb_mess);

          parc=parc->suiv_aut;}
   }
}
// Fonction pour trouver les messages en réponse à un message spécifique
void trouver_reponses( message m,liste_m* l)
{

      printf("Messages en réponse au message avec l'id %d:\n", m.id_m);
      Message* parc;
      parc=l->tete;
    while (parc!= NULL) {
          if (parc->m.id_original == m.id_m)
            {printf("la reponse du message %d est:titre %s,texte %s,date du publication (%d/%d/%d) ",parc->m.id_original,parc->m.titre,parc->m.text,parc->m.date_de_publication.tm_mday,parc->m.date_de_publication.tm_mon,parc->m.date_de_publication.tm_year);
             parc=parc->suiv_mess;}
}


}
void chercher_messages_par_rubrique( liste_m* l,rubrique* r)
{

    Message* parc =l->tete;

    while (parc != NULL) {

           // testez  si le message appartient à la rubrique donné
           if (strcmp(parc->m.theme_rub,r->theme) == 0) {
             printf("Message trouvé pour la rubrique  ayant theme %s est \n ",r->theme);
             printf(" du titre : %s du texte:%s et publie en (%d/%d/%d)\n",parc->m.titre,parc->m.text,parc->m.date_de_publication.tm_mday,parc->m.date_de_publication.tm_mon,parc->m.date_de_publication.tm_year) ;
              parc = parc->suiv_mess;}
           else
           {


            printf("cette rubrique n'admet aucun message");}

            }
}
void ecrit_list_message(FILE *f ,liste_m *l){
    Message* parc ;
    // examine si on peut ouvrir le fichier ou non
    if(!f)
    {
        fputs("le fichier ne peut pas ouvrir\n",stderr);
        return ;
    }
    //examine si la liste des messages est vide ou non
    if(l->tete==NULL)
    {
        printf("la list des messages est vide\n");
        return ;
    }
    //initialisation la node parc de facon qu'elle prend les valeurs de la premier node
    parc=l->tete ;
    while(parc!=NULL)
    {
        /*ecrire les elements de chaque message de facon que chaque element est ecrit dans chaque ligne pour
        les lire asiement avec la fonction fgets et scanf dans la fonction lire_list_message*/
        if(fprintf(f,"%d\n%s\n%s\n%s\n%d\n%d/%d/%d\n\n",
        parc->m.id_m,parc->m.titre,parc->m.text,parc->m.theme_rub,parc->m.id_original,
        parc->m.date_de_publication.tm_mday,parc->m.date_de_publication.tm_mon,parc->m.date_de_publication.tm_year)==EOF)
        {
            // si on atteint a la fin du fichier on ecrit un message d'erruer dans la fichier stderr qui est le terminal
            fputs("Erreur lors de l'écriture dans le fichier\n",stderr);
            return ;
        }
        // on passe passe a la node suivant
        parc = parc->suiv_mess;
    }

}

void lire_liste_message(FILE* f ,liste_m* lm)
{
    //on initialise la list chainé
    lm->tete = NULL;
    message m1;
    //on examine comme toujours si on peut ouvrir la fichier ou non
    if(!f)
    {
        fputs("le fichier ne peut pas ouvrir\n",stderr);
        return ;
    }
    //on place la curseur dans notre fichier a la fin de fichier
    fseek (f, 0, SEEK_END);
    //la fonction ftell(FILE* f) dans la localisation actuelle de curseur d'aprés la taille de memore de fichier
    int size = ftell(f);
    if (0 == size) {
        // si la taille de fichier est 0 bits notre fichier est donc vide
        printf("fichier est vide\n");
        return ; //on sortit de la fonction
    }
    else{
        //sinon on place la curseur dans la premier avant le premier caracter de fichier
        fseek (f, 0, SEEK_SET);
        // la premier ligne avoir l'denitité de la message
        while(fscanf(f,"%d\n",&m1.id_m)==1){
          //on examine si la lecture de l'dentité est en succées sinon il n'y a pas d'un message
          fgets(m1.titre,255,f);
          fgets(m1.text,255,f);
          fgets(m1.theme_rub,255,f);
          fscanf(f,"\n%d\n%d/%d/%d\n",&m1.id_original,&m1.date_de_publication.tm_mday,&m1.date_de_publication.tm_mon,&m1.date_de_publication.tm_year);
          //lecture de tous les elements de la message
          append_message(lm ,m1);
          //on ajoute dans la liste des messages
        }
    printf("la lecture du fichier est termnie voici les messages lu : \n");

    //on examin s'il ya un error ou non
    }

}
