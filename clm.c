#include "mot_precedent.h"
#include "nb_occurence.h"
#include "tri_lexico.h"
#include "tri_nb_occurence.h"
#include "mot_suivant.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    Dico *dico = NULL;
    Dico *dico_affiche = NULL;
    int taille = 0;
    int taille_affichee = 0;
    int tri1 = 0;
    int tri2 = 0;
    int utilise_suivants = 0;
    int utilise_precedent = 0;
    char *mot_precedent = NULL;
    char *mot_suivant = NULL;

    if (argc < 2) {
        printf("Usage: %s <fichier> [options]\n", argv[0]);
        return 1;
    }

    dico = fichier_vers_dico(argv[1], &taille);

    if (dico == NULL) {
        printf("Erreur: impossible d'ouvrir le fichier\n");
        return 1;
    }

    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-a") == 0) {
            tri1 = 1;
        }

        if (strcmp(argv[i], "-n") == 0) {
            tri2 = 1;
        }

        if (strcmp(argv[i], "-s") == 0 && i + 1 < argc) {
            utilise_suivants = 1;
            mot_suivant = argv[i + 1];
            i++;
        }

        if (strcmp(argv[i], "-p") == 0 && i + 1 < argc) {
            utilise_precedent = 1;
            mot_precedent = argv[i + 1];
            i++;
        }
    }

    dico_affiche = dico;
    taille_affichee = taille;

    if (utilise_suivants) {
        dico_affiche = tri_mot_suivant(argv[1], mot_suivant, &taille_affichee);
        if (dico_affiche == NULL || taille_affichee == 0) {
            printf("Aucun mot trouve apres \"%s\"\n", mot_suivant);
            free_dico(dico, taille);
            return 0;
        }
    }

    if (utilise_precedent) {
        dico_affiche = tri_mot_precedent(argv[1], mot_precedent, &taille_affichee);

        if (!dico_affiche || taille_affichee == 0) {
            printf("Aucun mot trouvé avant \"%s\"\n", mot_precedent);
            free_dico(dico, taille);
            return 0;
        }
    }

    if (tri1) {
        tri_lexico(dico_affiche, taille_affichee);
    }

    if (tri2) {
        insertion_sort_dico(dico_affiche, taille_affichee);
    }

    afficher_dico(dico_affiche, taille_affichee, 10);

    if (utilise_suivants) {
        free_dico(dico_affiche, taille_affichee);
    }
    free_dico(dico, taille);

    return 0;
}
