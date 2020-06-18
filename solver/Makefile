##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## to make some files
##

SRC =	main.c								\
		../lib/my/my_putarray.c				\
		../lib/my/my_freearray.c			\
		../dlist/init.c						\
		../dlist/insert.c					\
		../dlist/my_freelist.c				\
		../dlist/rmlist.c					\
		../lib/my/my_str_to_word_array.c	\
		../dlist/my_listlen.c				\
		verification.c						\

NAME = solver

all: $(SRC)
	gcc -o $(NAME) $(SRC)

val: $(SRC)
	gcc -o $(NAME) $(SRC) -g

clean:
	rm -f *~
	rm -f *.o
	rm -f vgcore*

fclean: clean
	rm -f $(NAME)

re: fclean all
