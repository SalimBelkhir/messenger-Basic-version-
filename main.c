#include <stdio.h>

struct Adresse {
    char rue [30] ;
    int codepostal ;
    char ville[10] ;
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
    struct Adresse ;
    double moyenne;
} Etudiant;

void lireNotes(Etudiant *etudiant) {
    printf("Saisie des notes pour l'etudiant %s %s :\n", etudiant->nom, etudiant->prenom);

    for (int i = 0; i < 5; ++i) {
        printf("Matiere de la note %d: ", i + 1);
        scanf("%s", etudiant->tabNotes[i].matiere);

        printf("Note pour la matiere %s: ", etudiant->tabNotes[i].matiere);
        scanf("%lf", &etudiant->tabNotes[i].note);

        printf("Coefficient pour la matiere %s: ", etudiant->tabNotes[i].matiere);
        scanf("%d", &etudiant->tabNotes[i].coef);
    }
}

double calculerMoyenne(const Etudiant *etudiant) {
    double sommeNotes = 0.0;
    int sommeCoefs = 0;

    for (int i = 0; i < 5 ; ++i) {
        sommeNotes += etudiant->tabNotes[i].note * etudiant->tabNotes[i].coef;
        sommeCoefs += etudiant->tabNotes[i].coef;
    }

    return (sommeCoefs != 0) ? (sommeNotes / sommeCoefs) : 0.0;
}

int main() {
    Etudiant etudiant;

    printf("Entrez le nom de l'etudiant : ");
    scanf("%s", etudiant.nom);

    printf("Entrez le prenom de l'etudiant : ");
    scanf("%s", etudiant.prenom);
    lireNotes(&etudiant);
    etudiant.moyenne = calculerMoyenne(&etudiant);

    printf("\nInformations de l'etudiant :\n");
    printf("Nom : %s\n", etudiant.nom);
    printf("Prenom : %s\n", etudiant.prenom);
    printf("Notes :\n");
    for (int i = 0; i < 5; ++i) {
        printf("  %s : %.2f (coef %d)\n", etudiant.tabNotes[i].matiere, etudiant.tabNotes[i].note, etudiant.tabNotes[i].coef);
    }
    printf("Moyenne : %.2f\n", etudiant.moyenne);

    return 0;
}

