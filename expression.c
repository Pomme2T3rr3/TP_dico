#include "expression.h"

#define TAILLE_MOT_MAX 255

static int est_separateur(int c) {
    return strchr(" _-.:'()?!,\t\n", c) != NULL;
}

static int lire_mot_expression(FILE *fichier, char *mot, size_t taille_mot) {
    int c;
    size_t i = 0;

    while ((c = fgetc(fichier)) != EOF) {
        if (!est_separateur(c)) {
            mot[i++] = Maj_vers_Min(c);
            break;
        }
    }

    if (c == EOF) {
        return 0;
    }

    while ((c = fgetc(fichier)) != EOF && !est_separateur(c)) {
        if (i + 1 < taille_mot) {
            mot[i++] = Maj_vers_Min(c);
        }
    }

    mot[i] = '\0';
    return 1;
}

int tri_expression(const char *filename, int n, int *taille_resultat) {
    FILE *fichier;
    char mot[TAILLE_MOT_MAX + 1];
    int nb_mots = 0;

    if (filename == NULL || taille_resultat == NULL || n <= 0) {
        return -1;
    }

    fichier = fopen(filename, "r");
    if (fichier == NULL) {
        return -1;
    }

    while (lire_mot_expression(fichier, mot, sizeof(mot))) {
        nb_mots++;
    }

    fclose(fichier);

    if (nb_mots < n) {
        *taille_resultat = 0;
    } else {
        *taille_resultat = nb_mots - n + 1;
    }

    return 0;
}
