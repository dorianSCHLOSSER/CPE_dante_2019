/*
** EPITECH PROJECT, 2020
** init
** File description:
** to initialize a double linkedkist
*/

#include "../my.h"

vec *init(void)
{
    vec *mylist = malloc(sizeof(*mylist));

    mylist->next = NULL;
    mylist->x = 0;
    mylist->y = 0;
    mylist->prev = NULL;
    return (mylist);
}