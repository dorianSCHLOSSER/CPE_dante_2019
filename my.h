/*
** EPITECH PROJECT, 2020
** my
** File description:
** to include files
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

typedef struct vec vec;
struct vec
{
    vec *prev;
    int x;
    int y;
    vec *next;
};

void my_putarray(char **);
void my_freearray(char **);
vec *init(void);
vec *insert_end(vec *, int, int);
vec *rm_end(vec *);
void *freelist(vec *);
char **my_str_to_word_array(char *, char);
int my_listlen(vec *);
vec *rm_nb(vec *, int);
int verification(int, char **);