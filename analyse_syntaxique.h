/* -------------------
-- paquetage syntaxique
-- analyse syntaxique d'une expression
--------------------------------*/

typedef enum {E_INIT, E_ENTIER, E_SYMBOLE, E_ERREUR} Etat_Automate_Syntax;

int analyser(Etat_Automate_Syntax etat, Nature_Lexeme lex);

int is_final(Etat_Automate_Syntax etat);

