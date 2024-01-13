#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>

struct Adresse {
    char rue[30];
    int codepostal;
    char ville[10];
};

typedef struct {
    char matiere[30];
    double note;
    int coef;
} Note;

typedef struct {
    char nom[30];
    char prenom[30];
    Note tabNotes[5];
    struct Adresse adresse;
    double moyenne;
} Etudiant;

void lireNotes(Etudiant *etudiant);
double calculerMoyenne(const Etudiant *etudiant);

#endif // STUDENT_H
