COMPILATION : 
gcc main.c StringArray.c Intersection.c TreeSet.c --std=c99 -o intersection
ou 
gcc main.c StringArray.c Intersection.c ListSet.c --std=c99 -o intersection
ou 
gcc main.c StringArray.c Intersection.c HashSet.c --std=c99 -o intersection
EXECUTION : 
./intersection French.txt English.txt

Affiche : (1) temps insertion des n premieres chaines de French.txt -> n peut etre changé en changeant la constante NB_MOTS_FRENCH dans le main.c (utilisé dans le projet)
	  (2) temps de recherche directement entre les chaines de english.txt contenu dans un tableau et un set contenant les mots insérés dans 1 (inutile/ non utilisé dans le projet finalement)
	  (3) temps de recherche entre 2 sets avec setIntersection() (utilisé dans le projet)