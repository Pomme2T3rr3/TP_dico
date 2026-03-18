#include "mot_precedent.h"

#define TAILLE_MOT_MAX 255

static int est_separateur(int c) {
    return strchr(" _-.:'()?!,\t\n", c) != NULL;
}

static void mot_en_minuscule(const char *src, char *dst, size_t taille_dst) {
    size_t i = 0;

    if (taille_dst == 0) {
        return;
    }

    while (src[i] != '\0' && i + 1 < taille_dst) {
        dst[i] = Maj_vers_Min(src[i]);
        i++;
    }
    dst[i] = '\0';
}

int lire_mot(FILE *fichier, char *mot, size_t taille_mot) {
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

Dico* tri_mot_precedent(const char *filename, const char *mot, int *taille_resultat) {
    FILE *fichier;
    Dico *resultat = NULL;
    int capacite = 10;
    char precedent[TAILLE_MOT_MAX + 1];
    char courant[TAILLE_MOT_MAX + 1];
    char mot_recherche[TAILLE_MOT_MAX + 1];

    if (filename == NULL || mot == NULL || taille_resultat == NULL) {
        return NULL;
    }

    *taille_resultat = 0;
    mot_en_minuscule(mot, mot_recherche, sizeof(mot_recherche));

    fichier = fopen(filename, "r");
    if (fichier == NULL) {
        return NULL;
    }

    if (!lire_mot(fichier, precedent, sizeof(precedent))) {
        fclose(fichier);
        return NULL;
    }

    while (lire_mot(fichier, courant, sizeof(courant))) {
        if (strcmp(courant, mot_recherche) == 0) {
            resultat = ajouter_mot(resultat, taille_resultat, &capacite, precedent);
            if (resultat == NULL) {
                fclose(fichier);
                return NULL;
            }
        }
        strcpy(precedent, courant);
    }

    fclose(fichier);
    return resultat;
}
