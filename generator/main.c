/*
** EPITECH PROJECT, 2020
** main
** File description:
** to generate a labyrinthe
*/

#include "../my.h"

int verification(int ac, char **av)
{
    if (ac != 3 && ac != 4) return (84);
    if (atoi(av[1]) <= 0) return (84);
    if (atoi(av[2]) <= 0) return (84);
    return (0);
}

char **generate_map(int x, int y)
{
    char **laby = malloc(sizeof(char *) * (y + 1));
    int random = 0;

    for (int i = 0; i < y; i++) {
        laby[i] = malloc(x + 1);
        for (int u = 0; u < x; u++)
            laby[i][u] = (rand() %2 == 1) ? 'X' : '*';
        laby[i][x] = '\0';
    }
    laby[y] = NULL;
    return (laby);
}

void generate_way(char **laby, int x, int y)
{
    int px = 0;
    int py = 0;
    int m = 0;
    int mm = 0;

    for (int i = 0; px != x - 1 || py != y - 1; i++) {
        laby[py][px] = '*';
        mm = m;
        m = rand() % 4 + 1;
        while ((mm == UP || mm == LEFT) && m == mm) m = rand() %4 + 1;
        for (int i = 0; i < rand() % 6 && m == UP && py > 0; i++)
            laby[py--][px] = '*';
        for (int i = 0; i < rand() % 6 && m == DOWN && py < y - 1; i++)
            laby[py++][px] = '*';
        for (int i = 0; i < rand() % 6 && m == LEFT && px > 0; i++)
            laby[py][px--] = '*';
        for (int i = 0; i < rand() % 6 && m == RIGHT && px < x - 1; i++)
            laby[py][px++] = '*';
    }
    laby[py][px] = '*';
}

int main(int ac, char **av)
{
    char **laby;
    int fd = 0;

    srand(time(NULL));
    if (verification(ac, av) == 84) return (84);
    laby = generate_map(atoi(av[1]), atoi(av[2]));
    generate_way(laby, atoi(av[1]), atoi(av[2]));
    remove("maze.txt");
    if (fopen("maze.txt", "w+") == NULL) return (84);
    fd = open("maze.txt", O_RDWR);
    for (int i = 0; i < atoi(av[2]); i++) {
        write(fd, laby[i], strlen(laby[i]));
        if (laby[i + 1] != NULL) write(fd, "\n", 1);
    }
    close(fd);
    my_putarray(laby);
    my_freearray(laby);
}