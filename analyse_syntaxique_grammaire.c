
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
            // return 1;
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

int rec_eag(Ast *A){
    return rec_seq_terme(A);
}

int rec_seq_terme(Ast *A){
    int err = 1;
    Ast A1 = NULL;
    err *= Rec_terme(&A1);
    err *= Rec_suite_seq_terme(A1, A);
    return err;
}

int Rec_suite_seq_terme(Ast Ag, Ast *A){
    int err = 1;
    Ast Ad = NULL, A1 = NULL;
    TypeOperateur Op;
    switch (lexeme_courant().nature){
        case PLUS:
        case MOINS:
            err *= Rec_op1(&Op);
            err *= Rec_terme(&Ad);
            A1 = creer_operation(Op, Ag, Ad);
            err *= Rec_suite_seq_terme(A1, A);
            break;
        
        default:
            *A = Ag;
            break;
    }
    return err;
}

int Rec_suite_seq_facteur(Ast Ag, Ast *A){
    int err = 1;
    Ast Ad = NULL, A1 = NULL;
    TypeOperateur Op;
    switch (lexeme_courant().nature){
        case MUL:
        case DIV:
            err *= Rec_op2(&Op);
            err *= Rec_terme(&Ad);
            A1 = creer_operation(Op, Ag, Ad);
            err *= Rec_suite_seq_terme(A1, A);
            break;
        
        default:
            *A = Ag;
            break;
    }
    return err;
}

int Rec_terme(Ast *A){
    return Rec_seq_facteur(A);
}

int Rec_seq_facteur(Ast *A){
    Ast Ag = NULL;
    int err = 1;
    err *= Rec_facteur(&Ag);
    err *= Rec_suite_seq_facteur(Ag, A);
    return err;
}

int Rec_facteur(Ast *A){
    //TypeOperateur Op;
    switch (lexeme_courant().nature){
        case ENTIER:
        case FLOAT:
            *A = creer_valeur(lexeme_courant().valeur);
            avancer();
            break;
        case PARO:
            avancer();
            rec_eag(A);
            if (lexeme_courant().nature == PARF)
            {
                avancer();
            }
            else return 0;
            break;
        default:
            return 0;
    }
    return 1;
}

int Rec_op1(TypeOperateur *Op){
    switch (lexeme_courant().nature){
        case PLUS:
            *Op = N_PLUS;
            avancer();
            return 1;
        case MOINS:
            *Op = N_MOINS;
            avancer();    
            return 1;

        default:
            return 0;
    }
}

int Rec_op2(TypeOperateur *Op){
    switch (lexeme_courant().nature){
        case MUL:
            *Op = N_MUL;
            avancer();    
            return 1;
        case DIV:
            avancer();    
            return 1;
        
        default:
            return 0;
    }
}