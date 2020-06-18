/*
** EPITECH PROJECT, 2020
** rmlist
** File description:
** to remove chars
*/

#include "../my.h"

vec *rm_nb(vec *mylist, int nb)
{
    int i = 0;

    while (mylist->prev != NULL)
        mylist = mylist->prev;
    while (i < nb - 1 && mylist->next != NULL) {
        mylist = mylist->next;
        i++;
    }
    mylist->next = mylist->next->next;
    free(mylist->next->prev);
    mylist->next->prev = mylist;
    return (mylist);
}

vec *rm_end(vec *mylist)
{
    while (mylist->next != NULL)
        mylist = mylist->next;
    mylist = mylist->prev;
    free(mylist->next);
    mylist->next = NULL;
    return (mylist);
}