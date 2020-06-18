/*
** EPITECH PROJECT, 2020
** my_freelist
** File description:
** to free a linked list
*/

#include "../my.h"

void *freelist(vec *mylist)
{
    if (mylist == NULL)
        return (NULL);
    if (mylist->prev == NULL && mylist->next != NULL)
        mylist = mylist->next;
    while (mylist->prev != NULL)
        mylist = rm_end(mylist);
    free(mylist);
    return (NULL);
}
