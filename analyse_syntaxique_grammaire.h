/* -------------------
-- paquetage syntaxique
-- analyse syntaxique d'une expression
--------------------------------*/

#include "analyse_lexicale.h"

int rec_eaep(float* val);

int rec_op(Nature_Lexeme* op);

float evaluer(float vald, Nature_Lexeme op, float valg);