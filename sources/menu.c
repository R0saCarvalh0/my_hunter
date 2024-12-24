/*
** EPITECH PROJECT, 2024
** menu.c
** File description:
** display window menu
*/

#include "../include/my.h"
#include "../include/my_hunter.h"

static int play_game(backG_t *bg, play_t *play)
{
    sfFloatRect sprite;
    sfVector2i pos_mouse = {bg->event.mouseButton.x,
                            bg->event.mouseButton.y};
    sfVector2f abs_pos;

    abs_pos = sfRenderWindow_mapPixelToCoords(bg->window, pos_mouse, NULL);
    sprite = sfSprite_getGlobalBounds(play->sprite_p);
    if (sfFloatRect_contains(&sprite, abs_pos.x, abs_pos.y)){
        bg->valeur_return = 1;
    }
    return 0;
}

int manage_event_menu(backG_t *GO, play_t *play)
{
    while (sfRenderWindow_pollEvent(GO->window, &(GO->event))){
        if (GO->event.type == sfEvtClosed)
            sfRenderWindow_close(GO->window);
        if (GO->event.type == sfEvtKeyPressed &&
            GO->event.key.code == sfKeyEscape)
            sfRenderWindow_close(GO->window);
        if (GO->event.type == sfEvtMouseButtonPressed)
            play_game(GO, play);
    }
    return 0;
}

play_t *creat_play(void)
{
    play_t *play = malloc(sizeof(play_t));

    play->texture_p = sfTexture_createFromFile("./assets/play.png", NULL);
    play->sprite_p = sfSprite_create();
    sfSprite_setScale(play->sprite_p, (sfVector2f){0.10, 0.10});
    sfSprite_setTexture(play->sprite_p, play->texture_p, sfTrue);
    play->pos_p = (sfVector2f){960, 540};
    return play;
}

sound_t *creat_sound(void)
{
    sound_t *sound = malloc(sizeof(sound_t));

    sound->Sound_buff = sfSoundBuffer_createFromFile("./assets/explosion.ogg");
    sound->Sound = sfSound_create();
    sfSound_setBuffer(sound->Sound, sound->Sound_buff);
    sfSound_setVolume(sound->Sound, 20.0);
    return sound;
}
