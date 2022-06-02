all:  main

ast_construction.o: ast_construction.c type_ast.h
	gcc -g -Wall -c ast_construction.c

ast_parcours.o: ast_parcours.c type_ast.h ast_construction.h table_symbole.h
	gcc -g -Wall -c ast_parcours.c

essai_ast.o: essai_ast.c  ast_construction.h  ast_parcours.h  type_ast.h
	gcc -g -Wall -c essai_ast.c

main: analyse_syntaxique.o analyse_lexicale.o lecture_caracteres.o main.o ast_parcours.o ast_construction.o table_symbole.o
	gcc -g -Wall -o main analyse_syntaxique.o analyse_lexicale.o  lecture_caracteres.o main.o ast_parcours.o ast_construction.o table_symbole.o

analyse_syntaxique.o: analyse_syntaxique.c analyse_syntaxique.h analyse_lexicale.h lecture_caracteres.h type_ast.h ast_construction.h table_symbole.h
	gcc -g -Wall -c analyse_syntaxique.c

analyse_lexicale.o: analyse_lexicale.c analyse_lexicale.h lecture_caracteres.h
	gcc -g -Wall -c analyse_lexicale.c

lecture_caracteres.o: lecture_caracteres.h lecture_caracteres.c
	gcc -g -Wall -c lecture_caracteres.c

main.o : analyse_syntaxique.h analyse_lexicale.h type_ast.h ast_parcours.h
	gcc -g -Wall -c main.c

table_symbole.o : table_symbole.c table_symbole.h
	gcc -g -Wall -c table_symbole.c

clean:
	rm -f *.o main

