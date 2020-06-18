/*
** EPITECH PROJECT, 2020
** verification
** File description:
** i'm actually the FBI
*/

#include "../my.h"

char *get_file(char **av)
{
    int i = 0;
    char c;
    char *str;
    int nb = 0;
    int fd = open(av[1], O_RDONLY);

    if (fd == -1) exit(84);
    for (i = 0; 1; i++) {
        nb = read(fd, &c, 1);
        if (c == '\0') exit(84);
        if (nb == 0) break;
        if (nb == -1) exit(84);
    }
    close(fd);
    fd = open(av[1], O_RDONLY);
    str = malloc(i + 1);
    read(fd, str, i);
    str[i] = '\0';
    close(fd);
    return (str);
}

int verification(int ac, char **av)
{
    int fd = 0;
    char **laby;
    char *str;
    int i = 0;
    int len = 0;

    if (ac != 2) return (84);
    str = get_file(av);
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] != '*' && str[i] != 'X' && str[i] != '\n') return (84);
    laby = my_str_to_word_array(str, '\n');
    free(str);
    len = strlen(laby[0]);
    for (i = 0; laby[i] != NULL; i++)
        if (strlen(laby[i]) != len) return (84);
    i--;
    if (laby[0][0] == 'X' || laby[i][strlen(laby[i])] == 'X')
        return (84);
    my_freearray(laby);
    return (0);
}