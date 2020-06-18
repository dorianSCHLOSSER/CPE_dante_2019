/*
** EPITECH PROJECT, 2020
** my_putarray
** File description:
** to put some arrays
*/

#include "../../my.h"

void my_putarray(char **arr)
{
    int i = 0;
    for (; arr[i + 1] != NULL; i++)
        printf("%s\n", arr[i]);
    printf("%s", arr[i]);
}
