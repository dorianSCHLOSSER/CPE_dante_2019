/*
** EPITECH PROJECT, 2020
** my_freearray
** File description:
** to free arrays
*/

#include "../../my.h"

void my_freearray(char **arr)
{
    char **tab = arr;

    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}
