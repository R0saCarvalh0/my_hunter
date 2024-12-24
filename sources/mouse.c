/*
** EPITECH PROJECT, 2024
** mouse.c
** File description:
** my_hunter.c
*/

#include "../include/my.h"
#include "../include/my_hunter.h"

mousesprite_t *creat_mouse(void)
{
    mousesprite_t *mouse_s = malloc(sizeof(mousesprite_t));

    mouse_s->texture_ms = sfTexture_createFromFile("./assets/meteorite.png",
                                                    NULL);
    mouse_s->sprite_ms = sfSprite_create();
    sfSprite_setScale(mouse_s->sprite_ms, (sfVector2f){3, 3});
    sfSprite_setTexture(mouse_s->sprite_ms, mouse_s->texture_ms, sfTrue);
    return mouse_s;
}

mousesprite_t *position_mouse(backG_t *bg, mousesprite_t *mouse_s)
{
    mouse_s->pos_mouse = sfMouse_getPositionRenderWindow(bg->window);
    mouse_s->pos_ms = sfRenderWindow_mapPixelToCoords(bg->window,
                                                    mouse_s->pos_mouse, NULL);
    mouse_s->pos_ms.x -= 110;
    mouse_s->pos_ms.y -= 110;
    sfSprite_setPosition(mouse_s->sprite_ms, mouse_s->pos_ms);
    return mouse_s;
}
