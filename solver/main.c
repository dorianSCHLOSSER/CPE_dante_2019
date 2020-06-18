/*
** EPITECH PROJECT, 2020
** main
** File description:
** to solve a labyrinthe
*/

#include "../my.h"

int is_ok(vec *p, char **laby, int mode)
{
    int x = p->x;
    int y = p->y;

    if (mode == UP) y -= 1;
    if (mode == RIGHT) x += 1;
    if (mode == DOWN) y += 1;
    if (mode == LEFT) x -= 1;

    if (x == -1 && y == 0) return (1);
    if (x < 0) return (0);
    if (y < 0) return (0);
    if (laby[y] == NULL) return (0);
    if (laby[y][x] == 'X' || laby[y][x] == '\0')
        return (0);
    return (1);
}

void move(int move, vec *pos)
{
    if (move == UP) pos->y -= 1;
    if (move == RIGHT) pos->x += 1;
    if (move == DOWN) pos->y += 1;
    if (move == LEFT) pos->x -= 1;
}

vec *opti_path(vec *pos)
{
    int x = pos->x;
    int y = pos->y;
    int ok = 0;
    vec *ptr = pos;

    while (pos->prev != NULL) pos = pos->prev;
    for (int i = 0; pos != ptr; i++) {
        if (pos->x == x && pos->y == y)
            ok = 1;
        pos = pos->next;
        if (ok == 1) rm_nb(pos, i);
        i -= (ok == 1);
    }
    return (ptr->next);
}

int solve_map(char **laby)
{
    int m = RIGHT;
    vec *p = init();
    int i = 0;
    for (i = 0; laby[p->y + 1] != NULL || laby[p->y][p->x + 1] != '\0'; i++) {
        insert_end(p, p->x, p->y);
        while (p->next != NULL) p = p->next;
        for (m; is_ok(p, laby, m) == 0; m = (m == 4) ? 1 : m + 1);
        move(m, p);
        m = (m == 1) ? 4 : m - 1;
        if (p->x == -1) return (0);
    }
    while (p->prev != NULL) p = p->prev;
    while (p->next != NULL) p = opti_path(p);
    while (p->prev != NULL) p = p->prev;
    laby[p->y][p->x] = 'o';
    while (p->next != NULL) {
        p = p->next;
        laby[p->y][p->x] = 'o';
    }
    return (1);
}

int main(int ac, char **av)
{
    int fd = 0;
    char **laby;
    char *str;
    int i = 0;
    char c;

    if (verification(ac, av) == 84) {
        printf("no solution found");
        return (84);
    }
    fd = open(av[1], O_RDONLY);
    for (i = 0; read(fd, &c, 1) != 0; i++);
    close(fd);
    fd = open(av[1], O_RDONLY);
    str = malloc(i + 1);
    read(fd, str, i);
    str[i] = '\0';
    close(fd);
    laby = my_str_to_word_array(str, '\n');
    if (solve_map(laby) == 0) printf("no solution found");
    else my_putarray(laby);
    return (0);
}