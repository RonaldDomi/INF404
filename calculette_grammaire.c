

/* Exemple d'utilisation de l'analyse lexicale : 
    Affichage d'une sequence de lexemes            */

#include <stdio.h>
#include <stdlib.h>

#include "analyse_syntaxique_grammaire.h"


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
   
    // float resultat;
    // analyse recursive de grammaire
    float res;
    int res_error = rec_eaep(&res);
    
    if(res_error == 0){
        // ERROR
        printf("Pas bon syntaxe, lexemme \n");
        afficher(lexeme_courant());
        printf("\n");
        return 0;
    }else{
        printf("Bon syntaxe\n");
        afficher(lexeme_courant());
    }
    
    printf("res: %f\n", res);

    arreter() ; // termine l'analyse lexicale
    return 0 ;
}
