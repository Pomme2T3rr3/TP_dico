#include "nb_occurence.h"
#include "tri_lexico.h"


int main(int argc, char *argv[]) {
    int taille = 0;
    Dico *dico = NULL;

    if (argc != 2) {
        printf("Usage: %s <fichier>\n", argv[0]);
        return 1;
    }

    dico = fichier_vers_dico(argv[1], &taille);

    if (dico == NULL) {
        printf("Erreur: impossible d'ouvrir le fichier\n");
        return 1;
    }

    if (strcmp(argv[1], "-a") == 0) {
        tri_lexico(dico, taille);
    }

    afficher_dico(dico, taille);
    free_dico(dico);

    return 0;
}
