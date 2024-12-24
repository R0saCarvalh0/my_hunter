/*
** EPITECH PROJECT, 2024
** destroy.c
** File description:
** my_hunter.c
*/

#include "../include/my.h"
#include "../include/my_hunter.h"

void destroy(sfMusic *music, texte_t *txt, backG_t *bg, sprite_t *dino)
{
    sfSprite_destroy(dino->sprite_S);
    sfTexture_destroy(dino->texture_S);
    sfSprite_destroy(bg->sprite);
    sfTexture_destroy(bg->texture);
    sfMusic_destroy(music);
    sfText_destroy(txt->text);
    sfRenderWindow_destroy(bg->window);
}

void destroy_menu(play_t *play)
{
    sfSprite_destroy(play->sprite_p);
    sfTexture_destroy(play->texture_p);
}

void destroy_end(gameover_t *GO)
{
    sfSprite_destroy(GO->sprite_go);
    sfTexture_destroy(GO->texture_go);
}
