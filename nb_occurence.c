#include "nb_occurence.h"


int chercher_mot(Dico *dico, int taille, char *mot) {
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
    int index = chercher_mot(dico, *taille, mot);

    if(index != -1) {
        // Mot existe déjà, on incrémente
        dico[index].frequence++;
    } else {
        // Nouveau mot
        if(*taille >= *capacite) {
            // Agrandir le tableau
            *capacite *= 2;
            size_t new_size = (*capacite) * sizeof(Dico);
            dico = (Dico*)realloc(dico, new_size);
        }

        dico[*taille].mot = (char*)malloc(strlen(mot) + 1);
        strcpy(dico[*taille].mot, mot);
        dico[*taille].frequence = 1;
        (*taille)++;
    }

    return dico;
}


Dico* fichier_vers_dico(char *filename, int nb_mots, int min, int flags) {

    FILE *fichier = fopen(filename, "r");
    if(!fichier) return NULL;

    int capacite = 100;
    int taille = 0;
    Dico *dico = (Dico*)malloc(capacite * sizeof(Dico));

    char mot[256];
    int i = 0, c;
    char *white = " _-.:'()?!,\t\n";

    while((c = fgetc(fichier)) != EOF) {
        if(strchr(white, c)) {
            if(i > 0) {
                mot[i] = '\0';

                // Vérifier la longueur
                int longueur = strlen(mot);
                if(longueur >= min) {
                    dico = ajouter_mot(dico, &taille, &capacite, mot);
                }
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
        int longueur = strlen(mot);
        if(longueur >= min) {
            dico = ajouter_mot(dico, &taille, &capacite, mot);
        }
    }

    fclose(fichier);

    return dico;
}


void afficher_dico(Dico *dico, int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%s : %d\n", dico[i].mot, dico[i].frequence);
    }
}
