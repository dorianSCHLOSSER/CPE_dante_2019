/*
** EPITECH PROJECT, 2020
** insert
** File description:
** to insert a char
*/

#include "../my.h"

vec *insert_end(vec *mylist, int x, int y)
{
    vec *new = malloc(sizeof(*new));

    while (mylist->next != NULL)
        mylist = mylist->next;
    new->x = x;
    new->y = y;
    new->next = mylist->next;
    new->prev = mylist;
    new->prev->next = new;
    return (new);
}
