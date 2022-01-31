
#include <stdio.h>
#include <stdlib.h>
#include "lecture_caracteres.h"
#include "analyse_syntaxique_grammaire.h"

// 0 si faux, 1 si correcte syntaxe
int rec_eaep(float* val){
    switch(lexeme_courant().nature){
        case FLOAT:
        case ENTIER:
            *val = lexeme_courant().valeur;
            avancer();
            break;
        case PARO:
            avancer();
            float valg;
            rec_eaep(&valg);
            
            Nature_Lexeme op;
            if(rec_op(&op) != 1) {
                // on gere l'erreur
                return 0;
            }
            
            float vald;
            rec_eaep(&vald);
            
            *val = evaluer(valg, op, vald);

            if(lexeme_courant().nature == PARF){
                avancer();
            }else{
                return 0;
            }
            
            break;
        default:
            return 0;
    };
    return 1;
};
// 0 si faux, 1 si correcte
int rec_op(Nature_Lexeme* op){
    switch(lexeme_courant().nature){
        case PLUS:
        case MOINS:
        case MUL:
        case DIV:
            *op = lexeme_courant().nature;
            avancer();
            return 1;
        default:
            return 0;
    }
};

float evaluer(float vald, Nature_Lexeme op, float valg){
    switch(op){
        case PLUS:
            return vald + valg;
        case MOINS:
            return vald - valg;
        case DIV:
            return vald / valg;
        case MUL:
            return vald * valg;
        default:
            // pass
            return 0.0;
    }
}

