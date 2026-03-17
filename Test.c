#include "nb_occurence.h"

int test_ajouter_mot(char *mot) {
    Dico *dico = NULL;
    int taille = 0, capacite = 0;
    dico = ajouter_mot(dico, &taille, &capacite, mot);

    if (dico == NULL || taille == 0) {
        return 0;
    }
    return 1;
}



int test(void) {
    if (!test_ajouter_mot("mot")) return 0;

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
