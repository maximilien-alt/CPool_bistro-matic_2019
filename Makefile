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
<<<<<<< HEAD
	gcc -o $(NAME) -g3 infin_mult.c infin_add.c infin_sub.c -L. -lmy -I include
=======
	gcc -o $(NAME) -g3 infin_div.c infin_add.c infin_sub.c infin_mod.c -L. -lmy -I include
>>>>>>> 9c1c1c34c192bcc9f739d9168168081807c48071
clean	:
	rm -f *.o $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
