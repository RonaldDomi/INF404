#include <stdlib.h>
#include <stdio.h> 

#include "type_ast.h"

Ast creer_operation(TypeOperateur opr , Ast opde_gauche , Ast opde_droit) 
{
      Ast expr ;
      expr = (Ast) malloc (sizeof(NoeudAst));
      expr->nature = OPERATION;
      expr->operateur = opr;
      if (opde_gauche == NULL){
         printf("ERREUR_EXPRESSION gauche null\n") ;
         exit(1) ;

      }else if(opde_droit == NULL) {
      
         printf("ERREUR_EXPRESSION droit null\n") ;
	   exit(1) ;
      } else {
         expr->gauche = opde_gauche;
         expr->droite = opde_droit;
      } ;
      return expr ;
}

Ast creer_valeur(float val) { 
      Ast expr ;
      expr = (Ast) malloc (sizeof(NoeudAst));
      expr->nature = VALEUR;
      expr->valeur = val;
      return expr ;
}
