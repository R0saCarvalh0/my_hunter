/*
** EPITECH PROJECT, 2024
** end.c
** File description:
** display window menu
*/

#include "../include/my.h"
#include "../include/my_hunter.h"

int manage_event_end(backG_t *end)
{
    while (sfRenderWindow_pollEvent(end->window, &(end->event))){
        if (end->event.type == sfEvtClosed)
            sfRenderWindow_close(end->window);
        if (end->event.type == sfEvtKeyPressed &&
            end->event.key.code == sfKeyEscape)
            sfRenderWindow_close(end->window);
    }
    return 0;
}

gameover_t *creat_go(void)
{
    gameover_t *GO = malloc(sizeof(gameover_t));

    GO->texture_go = sfTexture_createFromFile("./assets/game_over.png", NULL);
    GO->sprite_go = sfSprite_create();
    sfSprite_setScale(GO->sprite_go, (sfVector2f){0.5, 0.5});
    sfSprite_setTexture(GO->sprite_go, GO->texture_go, sfTrue);
    GO->pos_go = (sfVector2f){960, 540};
    return GO;
}
