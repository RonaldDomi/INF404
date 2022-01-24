#include <stdio.h>
#include <stdlib.h>
#include "lecture_caracteres.h"
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
                        return E_ENTIER;
                        break;
                    
                    default:
                        return E_ERREUR;
                        break;
                }
                break;
            case E_ENTIER:
                switch (lex)
                {
                    case PLUS :
                    case MOINS :
                    case MUL :
                    case DIV : //operateur
                        return E_SYMBOLE;
                        break;
                    
                    default:
                        return E_ERREUR;
                        break;
                }
                break;
            
            case E_SYMBOLE:
                switch (lex)
                {
                    case ENTIER:
                        return E_ENTIER;
                        break;
                    
                    default:
                        return E_ERREUR;
                        break;
                }
                break;
            case E_ERREUR :
                return E_ERREUR;
                break;
            default:
                break;
            }
        }
        return etat;
} 