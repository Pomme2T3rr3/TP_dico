#ifndef NB_OCCURENCE_H
#define NB_OCCURENCE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct dico_mot{
    char *mot;
    int frequence;
} Dico;

char Maj_vers_Min(char c);
Dico* ajouter_mot(Dico *dico, int *taille, int *capacite, char *mot);
Dico* fichier_vers_dico(char *filename, int* taille);
void afficher_dico(Dico *dico, int taille, int nb_affiche);
void free_dico(Dico *dico, int taille);


#endif
