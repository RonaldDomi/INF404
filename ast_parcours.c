
#include <stdio.h>
#include "type_ast.h"

void aff_operateur(TypeOperateur op){
	switch (op) {
		case N_PLUS:
			printf("+") ;
			break;
		case N_MOINS:
			printf("-") ;
			break;
		case N_MUL:
			printf("*") ;
			break;
	} 
}

void afficher_ast(Ast expr) {
	switch (expr->nature) {
               case OPERATION:
                        printf("(");
                        afficher_ast(expr->gauche);
                        aff_operateur(expr->operateur) ;
                        afficher_ast(expr->droite);
                        printf(")");
			break ;
               case VALEUR:
                  	printf("%d", expr->valeur);
			break ;
	}
}

int evaluation(Ast expr) {
      int vg, vd;
	  switch (expr->nature)
	  {
	  case VALEUR:
		  return expr->valeur;
	  case OPERATION:
	  	vg = evaluation(expr->gauche);
		vd = evaluation(expr->droite);
		switch (expr->operateur)
		{
		case N_PLUS:
			return vg + vd;
		case N_MOINS:
			return vg - vd;
		case N_MUL:
		 return vg * vd;
		default:
			break;
		}  
	  default:
		  break;
	  }
      return -1 ;
}

