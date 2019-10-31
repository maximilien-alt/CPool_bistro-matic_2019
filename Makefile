##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	*.c	\

NAME	=	calc

OBJ	=	libmy.a

all	:	$(OBJ)

$(OBJ)	:
	gcc -c -g3 lib/my/$(SRC)
	ar rc $(OBJ) *.o
	gcc -o $(NAME) -g3 main.c eval_expr.c infin_mult.c infin_div.c infin_add.c infin_sub.c infin_mod.c -L. -lmy -I include
clean	:
	rm -f *.o $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
