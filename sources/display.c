/*
** EPITECH PROJECT, 2024
** display.c
** File description:
** my_hunter.c
*/

#include "../include/my.h"
#include "../include/my_hunter.h"

void display_menu(backG_t *bg, play_t *play, texte_t *text)
{
    manage_event_menu(bg, play);
    sfRenderWindow_clear(bg->window, sfBlack);
    sfRenderWindow_drawSprite(bg->window, bg->sprite, NULL);
    sfRenderWindow_drawSprite(bg->window, play->sprite_p, NULL);
    sfSprite_setPosition(play->sprite_p, (sfVector2f){730, 450});
    sfRenderWindow_drawText(bg->window, text->text, NULL);
    sfRenderWindow_display(bg->window);
}

void display_game(sprite_t *dino, texte_t *text, backG_t *bg,
    mousesprite_t *mouse_s)
{
    creat_clock(dino, text);
    manage_event(bg, dino, text);
    sfRenderWindow_clear(bg->window, sfBlack);
    sfRenderWindow_drawSprite(bg->window, bg->sprite, NULL);
    position_mouse(bg, mouse_s);
    sfSprite_setTextureRect(dino->sprite_S,
                            (sfIntRect) {dino->pos_0, 0,
                            DINO_SIZE, DINO_SIZE});
    sfRenderWindow_drawSprite(bg->window, dino->sprite_S, NULL);
    sfRenderWindow_drawSprite(bg->window, mouse_s->sprite_ms, NULL);
    sfRenderWindow_drawText(bg->window, text->text, NULL);
    sfSprite_setPosition(dino->sprite_S, (sfVector2f){dino->pos.x,
                        dino->pos.y});
    dino->pos_0 += DINO_SIZE;
    dino->pos.x += 10;
    animation_dino(bg, dino);
    sfRenderWindow_display(bg->window);
}

void display_end(backG_t *bg, gameover_t *GO)
{
    manage_event_end(bg);
    sfRenderWindow_clear(bg->window, sfBlack);
    sfRenderWindow_drawSprite(bg->window, bg->sprite, NULL);
    sfRenderWindow_drawSprite(bg->window, GO->sprite_go, NULL);
    sfSprite_setPosition(GO->sprite_go, (sfVector2f){350, -100});
    sfRenderWindow_display(bg->window);
}
