/*
** EPITECH PROJECT, 2024
** level.c
** File description:
** my_hunter.c
*/

#include "../include/my.h"
#include "../include/my_hunter.h"


int set_level(texte_t *txt)
{
    if (txt->score == 0)
        txt->level -= 1;
    if (txt->score > 10 && txt->score >= 5)
        txt->level += 1;
    if (txt->score > 15)
        txt->level += 1;
    if (txt->score > 20)
        txt->level += 1;
    if (txt->score > 100)
        txt->level += 1;
    display_level(txt);
    return 0;
}

int display_level(texte_t *txt)
{
    my_putstr("your score: ");
    my_put_nbr(txt->score);
    my_putstr("   level: ");
    my_put_nbr(txt->level);
    my_putchar('\n');
    return 0;
}
