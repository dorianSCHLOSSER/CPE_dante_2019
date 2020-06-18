/*
** EPITECH PROJECT, 2020
** my_listlen
** File description:
** this lib is too EZ
*/

#include "../my.h"

int my_listlen(vec *mylist)
{
    int i = 0;

    while (mylist->prev != NULL)
        mylist = mylist->prev;
    while (mylist->next != NULL) {
        i++;
        mylist = mylist->next;
    }
    return (i + 1);
}
