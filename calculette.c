
/* Exemple d'utilisation de l'analyse lexicale : 
    Affichage d'une sequence de lexemes            */

#include <stdio.h>
#include <stdlib.h>

#include "analyse_syntaxique.h"
#include "analyse_lexicale.h"


int main (int argc, char *argv[]) {
   switch (argc) {
        case 1:
		// demarre l'analyse lexicale sur stdin
   		demarrer ("") ; 
                break ;
        case 2:
		// demarre l'analyse lexicale sur le fichier transmis en argument
   		demarrer (argv[1]) ; 
                break ;
        default:
                printf("nombre d'arguments incorrects !\n");
                exit(1) ;
   } ;
   Etat_Automate_Syntax etat = E_INIT;
   while (! fin_de_sequence()) { 
        afficher (lexeme_courant()) ;
        printf("\n") ;
        etat = analyser(etat, lexeme_courant().nature); 
        avancer();
        printf("%d", etat);
   } ;
   is_final(etat) ? printf("\nlexpression est correct\n") : printf("\nlexpression nest pas correct\n");
   arreter() ; // termine l'analyse lexicale
   return 0 ;
}
