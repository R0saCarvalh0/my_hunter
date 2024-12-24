/*
** EPITECH PROJECT, 2024
** my_hunter.h
** File description:
** my_hunter
*/

#ifndef MY_HUNTER_H
    #define MY_HUNTER_H

    #include "struct.h"

    #define FIRST_DINO_SPRITE 96
    #define FIRST_DINO_DIED 336
    #define DINO_SIZE 24

int my_hunter(int argc, char **argv);

void display_window(backG_t *bg, sprite_t *dino, texte_t *text,
    mousesprite_t *mouse_s);
int display_level(texte_t *txt);
void display_menu(backG_t *bg, play_t *play, texte_t *text);
void display_game(sprite_t *dino, texte_t *text, backG_t *bg,
    mousesprite_t *mouse_s);
void display_end(backG_t *bg, gameover_t *GO);

int creat_clock(sprite_t *dino, texte_t *txt);
play_t *creat_play(void);
gameover_t *creat_go(void);
mousesprite_t *creat_mouse(void);
sound_t *creat_sound(void);

int manage_event(backG_t *bg, sprite_t *dino, texte_t *txt);
int manage_event_menu(backG_t *GO, play_t *play);
int manage_event_end(backG_t *end);

void destroy(sfMusic *music, texte_t *txt, backG_t *bg, sprite_t *dino);
void destroy_end(gameover_t *GO);
void destroy_menu(play_t *play);

int set_level(texte_t *txt);

mousesprite_t *position_mouse(backG_t *bg, mousesprite_t *mouse_s);

sprite_t *animation_dino(backG_t *bg, sprite_t *dino);

#endif /* MY_HUNTER_H */
