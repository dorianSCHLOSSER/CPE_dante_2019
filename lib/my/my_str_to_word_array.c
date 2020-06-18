/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** to split words
*/

#include "../../my.h"

typedef struct word_array
{
    int i;
    int u;
    int a;
    int mode;
} wa;

int my_line_ok(char *str, wa arr, char c, int nb)
{
    if (str[arr.i] == c && arr.mode == 0 && nb == 0 &&
        str[arr.i + 1] != c && str[arr.i + 1] != '\0')
        return (1);
    if (nb == 1 && str[arr.i] == c &&
        (str[arr.i + 1] == c || str[arr.i + 1] == '\0'))
        return (1);
    return (0);
}

int nbr_mots(char *str, char c)
{
    int i = 0;
    int u = 1;
    int mode = 0;

    for (i; str[i] == c; i++);
    while (str[i] != '\0') {
        if (str[i] == '\"')
            mode = (mode == 0);
        if (str[i] == c && mode == 0 && str[i + 1] != c && str[i + 1] != '\0')
            u++;
        i++;
    }
    return (u);
}

char **use_malloc(char *str, char c)
{
    char **word_array;
    wa arr = {0, 0, 0, 0};

    for (arr.i; str[arr.i] == c; arr.i++);
    word_array = malloc(sizeof(char *) * (nbr_mots(str, c) + 1));
    for (arr.i; str[arr.i - (arr.i != 0)] != '\0'; arr.i++) {
        if (str[arr.i] == '\"') {
            arr.i++;
            arr.mode = (arr.mode == 0);
        }
        if ((str[arr.i] == c && arr.mode == 0 && str[arr.i + 1] != c)
            || (str[arr.i] == '\0' && str[arr.i - 1] != c)) {
            word_array[arr.u] = malloc(sizeof(char) * (arr.a + 1));
            arr.u++;
            arr.a = -1;
        }
        arr.a += 1 - (str[arr.i] == c && str[arr.i + 1] == c);
    }
    return (word_array);
}

char **my_str_to_word_array(char *str, char c)
{
    char **word_array = use_malloc(str, c);
    wa arr = {0, 0, 0, 0};

    for (arr.i; str[arr.i] == c; arr.i++);
    while (str[arr.i - (arr.i != 0)] != '\0') {
        arr.mode = (str[arr.i] == '\"') ? (arr.mode == 0) : arr.mode;
        arr.i += (str[arr.i] == '\"');
        if (my_line_ok(str, arr, c, 0) == 1) {
            word_array[arr.u][arr.a] = '\0';
            arr.u++;
            arr.i++;
            arr.a = 0;
        }
        if (str[arr.i] != '\"') {
            word_array[arr.u][arr.a] = str[arr.i];
            arr.a += 1 - (my_line_ok(str, arr, c, 1));
            arr.i++;
        }
    }
    word_array[arr.u + 1] = NULL;
    return (word_array);
}