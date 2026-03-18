#include "expression.h"

int tri_expression(const char *filename, int n, int *taille_resultat) {
    FILE *fichier = fopen(filename, "r");
    if (!fichier) {
        return -1;
    }

    char mot[256];
    int compteur = 0;
    while (lire_mot(fichier, mot, sizeof(mot)) != EOF) {
        if (compteur < n) {
        }
        compteur++;
    }

    fclose(fichier);
    *taille_resultat = compteur;
    return 0;
}
