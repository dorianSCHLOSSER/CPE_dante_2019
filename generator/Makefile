##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## to generate
##

SRC =	main.c						\
		../lib/my/my_putarray.c		\
		../lib/my/my_freearray.c	\

NAME =	generator

all: $(SRC)
	gcc -o $(NAME) $(SRC)

val: $(SRC)
	gcc -o $(NAME) $(SRC) -g

clean:
	rm -f *.o
	rm -f vgcore*
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all