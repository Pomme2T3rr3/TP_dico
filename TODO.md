# TODO

## Liste des options demandées
- [x] 'clm texte' affiche ligne par ligne chaque mot du texte suivi de son nombre d'occurence.
- [x] 'clm texte -a' tri les mots affichés dans l'ordre lexicographique.
- [x] 'clm texte -n' tri les mots affichés en fonction de leur nombre d'occurence.
- [x] 'clm TEXTE -s MOT' affiche chaque mot x suivi de MOT dans TEXTE, suivi du nombre d'occurence de x situé après MOT.
- [x] 'clm TEXTE -p MOT' affiche chaque mot x qui précède MOT dans TEXTE, suivi du nombre d'occurence de x précédant MOT.
- [ ] 'clm TEXTE -e N' affiche une ligne pour chaque expression de N mots dans TEXTE, suivi d'espace, suivi du nombre d'occurence de cette expression dans TEXTE. On pourra y rajouter les options -a et -n.


## Découpage en modules
- "cpt_occurence.c" s'occupe de l'affichage de chaque mot ligne par ligne, suivi de son nombre d'occurence.
- "tri_lexico.c" s'occupe de l'option -a
- "tri_nb_occurence.c" s'occupe de l'option -n
- "mot_suivant.c" s'occupe de l'option -s
- "mot_precedent.c" s'occupe de l'option -p
- "expression.c" s'occupe de l'option -e
- "Test.c" gère les tests des fonctions écrites dans les modules précédemment cités, pourra être appelé avec la fonction '--test'.
