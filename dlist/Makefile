##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## i almost finnish my double linked list
##

SRC =	init.c				\
		insert.c			\
		my_freelist.c		\
		my_listcat.c		\
		my_listlen.c		\
		printlist.c			\
		rmlist.c			\
		my_to_linked_list.c	\

OBJ =	$(SRC:.c=.o)

NAME =	libdlist.a

all: $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	@rm -f *~

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all