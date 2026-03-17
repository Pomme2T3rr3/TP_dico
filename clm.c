#include "nb_occurence.h"

int main() {
    Dico dico[100];
    int taille = 0;
    ajouter_mot(dico, &taille, "mot");
    afficher_dico(dico, taille);

    return 1;
}
