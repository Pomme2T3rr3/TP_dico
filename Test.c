#include "nb_occurence.h"
#include "tri_lexico.h"
#include "tri_nb_occurence.h"
#include "mot_suivant.h"
#include "mot_precedent.h"


int test_ajouter_mot(char *mot) {
    Dico *dico = NULL;
    int taille = 0, capacite = 10;
    dico = ajouter_mot(dico, &taille, &capacite, mot);

    if (dico == NULL || taille == 0) {
        return 0;
    }
    free_dico(dico, taille);
    return 1;
}

int test_tri_lexico(void) {
    Dico *dico = NULL;
    int taille = 0, capacite = 10;
    dico = ajouter_mot(dico, &taille, &capacite, "banane");
    dico = ajouter_mot(dico, &taille, &capacite, "abricot");
    dico = ajouter_mot(dico, &taille, &capacite, "cerise");

    tri_lexico(dico, taille);

    if (strcmp(dico[0].mot, "abricot") != 0 ||
        strcmp(dico[1].mot, "banane") != 0 ||
        strcmp(dico[2].mot, "cerise") != 0) {
        free_dico(dico, taille);
        return 0;
    }
    free_dico(dico, taille);
    return 1;
}


int test_insertion_sort_dico(void) {
    Dico* dico = NULL;
    int taille = 0, capacite = 10;
    dico = ajouter_mot(dico, &taille, &capacite, "banane");
    dico = ajouter_mot(dico, &taille, &capacite, "abricot");
    dico = ajouter_mot(dico, &taille, &capacite, "abricot");
    dico = ajouter_mot(dico, &taille, &capacite, "abricot");
    dico = ajouter_mot(dico, &taille, &capacite, "cerise");
    dico = ajouter_mot(dico, &taille, &capacite, "cerise");
    dico = ajouter_mot(dico, &taille, &capacite, "cerise");
    dico = ajouter_mot(dico, &taille, &capacite, "cerise");



    insertion_sort_dico(dico, taille);

    if (strcmp(dico[0].mot, "cerise") != 0 ||
        strcmp(dico[1].mot, "abricot") != 0 ||
        strcmp(dico[2].mot, "banane") != 0) {
        free_dico(dico, taille);
        return 0;
    }
    free_dico(dico, taille);
    return 1;
}

int test_mot_suivant(void) {
    const char *fichier = "test_mot_suivant.txt";
    FILE *f = fopen(fichier, "w");
    int taille = 0;
    Dico *dico = NULL;

    if (f == NULL) {
        return 0;
    }

    fputs("Jean Valjean parle. Jean dort. Jean Valjean marche.", f);
    fclose(f);

    dico = tri_mot_suivant(fichier, "jean", &taille);
    remove(fichier);

    if (dico == NULL || taille != 2) {
        free_dico(dico, taille);
        return 0;
    }

    if ((strcmp(dico[0].mot, "valjean") == 0 && dico[0].frequence == 2 &&
         strcmp(dico[1].mot, "dort") == 0 && dico[1].frequence == 1) ||
        (strcmp(dico[1].mot, "valjean") == 0 && dico[1].frequence == 2 &&
         strcmp(dico[0].mot, "dort") == 0 && dico[0].frequence == 1)) {
        free_dico(dico, taille);
        return 1;
    }

    free_dico(dico, taille);
    return 0;
}


int test_mot_precedent(void) {
    const char *fichier = "test_mot_precedent.txt";
    FILE *f = fopen(fichier, "w");
    int taille = 0;
    Dico *dico = NULL;

    if (f == NULL) {
        return 0;
    }

    fputs("Jean Valjean parle. Jean dort. Jean Valjean marche.", f);
    fclose(f);

    dico = tri_mot_precedent(fichier, "jean", &taille);
    remove(fichier);

    if (dico == NULL || taille != 2) {
        free_dico(dico, taille);
        return 0;
    }

    if ((strcmp(dico[0].mot, "parle") == 0 && dico[0].frequence == 1 &&
         strcmp(dico[1].mot, "dort") == 0 && dico[1].frequence == 1) ||
        (strcmp(dico[1].mot, "parle") == 0 && dico[1].frequence == 1 &&
         strcmp(dico[0].mot, "dort") == 0 && dico[0].frequence == 1)) {
        free_dico(dico, taille);
        return 1;
    }

    free_dico(dico, taille);
    return 0;
}

int test(void) {
    if (!test_ajouter_mot("mot")) return 0;
    if (!test_tri_lexico()) return 0;
    if (!test_insertion_sort_dico()) return 0;
    if (!test_mot_suivant()) return 0;
    if (!test_mot_precedent()) return 0;

    return 1;
}

int main(void) {
    if (test()) {
        printf("Tous les tests ont passé!\n");
        return 0;
    } else {
        printf("Certains tests ont échoué!\n");
        return 1;
    }
}
