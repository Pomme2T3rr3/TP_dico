#ifndef MOT_PRECEDENT_H
#define MOT_PRECEDENT_H

#include "nb_occurence.h"

int lire_mot(FILE *fichier, char *mot, size_t taille_mot);
Dico* tri_mot_precedent(const char *filename, const char *mot, int *taille_resultat);

#endif
