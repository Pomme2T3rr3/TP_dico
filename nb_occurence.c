#include "nb_occurence.h"


int chercher_mot(Dico *dico, int taille, char *mot) {
    if(dico == NULL || taille == 0) {
        return -1;
    }
    for(int i = 0; i < taille; i++) {
        if(strcmp(dico[i].mot, mot) == 0) {
            return i;  // Retourne l'index
        }
    }
    return -1;  // Mot non trouvé
}


char Maj_vers_Min(char c) {
    if(c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');  // Différence de 32 en ASCII
    }
    return c;
}


// Ajouter ou incrémenter le nombre d'occurence d'un mot
Dico* ajouter_mot(Dico *dico, int *taille, int *capacite, char *mot) {
    if (capacite == NULL || taille == NULL || mot == NULL) {
        return dico;
    }

    if (dico == NULL) {
        if (*capacite <= 0) {
            *capacite = 10;
        }
        dico = malloc((size_t)(*capacite) * sizeof(Dico));
        if (dico == NULL) {
            return NULL;
        }
    }

    int index = chercher_mot(dico, *taille, mot);

    if(index != -1) {
        // Mot existe déjà, on incrémente
        dico[index].frequence++;
    } else {
        // Nouveau mot
        if(*taille >= *capacite) {
            // Agrandir le tableau
            if(*capacite == 0) {
                *capacite = 10;
            } else {
                *capacite *= 2;
            }
            size_t new_size = (*capacite) * sizeof(Dico);
            Dico *tmp = realloc(dico, new_size);
            if (tmp == NULL) {
                return NULL;
            }
            dico = tmp;
        }

        dico[*taille].mot = (char*)malloc(strlen(mot) + 1);
        if (dico[*taille].mot == NULL) {
            return NULL;
        }
        strcpy(dico[*taille].mot, mot);
        dico[*taille].frequence = 1;
        (*taille)++;
    }

    return dico;
}


Dico* fichier_vers_dico(char *filename, int *taille) {
    if (taille == NULL) {
        return NULL;
    }

    *taille = 0;

    FILE *fichier = fopen(filename, "r");
    if(!fichier) return NULL;

    int capacite = 100;
    Dico *dico = (Dico*)malloc(capacite * sizeof(Dico));

    char mot[256];
    int i = 0, c;
    char *white = " _-.:'()?!,\t\n";

    while((c = fgetc(fichier)) != EOF) {
        if(strchr(white, c)) {
            if(i > 0) {
                mot[i] = '\0';
                dico = ajouter_mot(dico, taille, &capacite, mot);
                i = 0;
            }
        } else {
            mot[i++] = Maj_vers_Min(c);
            if(i >= 255) i = 255;
        }
    }

    // Dernier mot
    if(i > 0) {
        mot[i] = '\0';
        dico = ajouter_mot(dico, taille, &capacite, mot);
    }

    fclose(fichier);

    return dico;
}


void afficher_dico(Dico *dico, int taille, int nb_affiche) {
    for (int i = 0; i < nb_affiche && i < taille; i++) {
        printf("%s : %d\n", dico[i].mot, dico[i].frequence);
    }
}


void free_dico(Dico *dico, int taille) {
    if (dico == NULL) {
        return;
    }

    for (int i = 0; i < taille; i++) {
        free(dico[i].mot);
    }
    free(dico);
}
