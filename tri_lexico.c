#include "tri_lexico.h"

void tri_lexico(Dico *dico, int taille) {
    for (int i = 0; i < taille - 1; i++) {
        for (int j = 0; j < taille - i - 1; j++) {
            if (strcmp(dico[j].mot, dico[j + 1].mot) > 0) {
                Dico temp = dico[j];
                dico[j] = dico[j + 1];
                dico[j + 1] = temp;
            }
        }
    }
}
