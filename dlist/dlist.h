/*
** EPITECH PROJECT, 2020
** my
** File description:
** this file name is muy mdr
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct List List;
struct List
{
    List *prev;
    char c;
    List *next;
};

List *init(char);
List *insert_nb(List *, char, int);
List *insert_end(List *, char);
void printlist(List *);
int my_listlen(List *);
List *rm_end(List *);
List *rm_nb(List *, int);
List *my_str_to_linkedlist(char *);
List *my_tab_to_linkedlist(char **);
void *freelist(List *);
List *my_listcat(List *, List *);