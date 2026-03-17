#include "tri_nb_occurence.h"


// Fonction Tri insertion en fonction de la fréquence
void insertion_sort_dico(Dico* dico, int taille) {
    for (int i = 1; i < taille; i++) {
        Dico cle = dico[i];
        int j = i - 1;

        // Décale droite
        while (j >= 0 && dico[j].frequence < cle.frequence) {
            dico[j + 1] = dico[j];
            j--;
        }
        dico[j + 1] = cle;
    }
}
