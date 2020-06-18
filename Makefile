##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## to make some files
##

all:
	make -C ./solver re
	make -C ./generator re

val:
	make -C ./solver val
	make -C ./generator val

fclean:
	rm -f generator/generator
	rm -f solver/solver

re: fclean all