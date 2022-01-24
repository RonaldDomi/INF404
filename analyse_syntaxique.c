#include <stdio.h>
#include <stdlib.h>
#include "lecture_caracteres.h"
#include "analyse_lexicale.h"
#include "analyse_syntaxique.h"

int is_final(Etat_Automate_Syntax etat){return etat == E_ENTIER;}


int analyser(Etat_Automate_Syntax etat, Nature_Lexeme lex){

    while (etat != E_ERREUR)
    {
        switch (etat)
        {
            case E_INIT:
                switch (lex)
                {
                    case ENTIER:
                        etat = E_ENTIER;
                        break;
                    
                    default:
                        etat = E_ERREUR;
                        break;
                }
                break;
            case E_ENTIER:
                switch (lex)
                {
                    case PLUS || MOINS || MUL || DIV: //operateur
                        etat = E_SYMBOLE;
                        break;
                    
                    default:
                        etat = E_ERREUR;
                        break;
                }
                break;
            
            case E_SYMBOLE:
                switch (lex)
                {
                    case ENTIER:
                        etat = E_ENTIER;
                        break;
                    
                    default:
                        etat = E_ERREUR;
                        break;
                }
                break;
            case E_ERREUR :
                break;
            default:
                break;
            }
        }
        return etat;
} 