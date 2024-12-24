/*
** EPITECH PROJECT, 2024
** STRUCT.h
** File description:
** my_hunter
*/

#ifndef STRUCT_H
    #define STRUCT_H

    #include "include.h"

typedef struct sound_s {
    sfSoundBuffer *Sound_buff;
    sfSound *Sound;
} sound_t;

typedef struct mousesprite_s {
    sfTexture *texture_ms;
    sfSprite *sprite_ms;
    sfVector2f pos_ms;
    sfVector2i pos_mouse;
} mousesprite_t;


typedef struct gameover_s {
    sfTexture *texture_go;
    sfSprite *sprite_go;
    sfVector2f pos_go;
} gameover_t;

typedef struct play_s {
    sfTexture *texture_p;
    sfSprite *sprite_p;
    sfVector2f pos_p;
} play_t;

typedef struct backG_s {
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *texture;
    sfSprite *sprite;
    int valeur_return;
} backG_t;

typedef struct sprite_s {
    sfTexture *texture_S;
    sfSprite *sprite_S;
    sfVector2f pos;
    int pos_0;
    double vitesse;
    int vie;
} sprite_t;

typedef struct texte_s {
    sfText *text;
    sfFont *font;
    int score;
    char *str;
    int level;
}texte_t;

#endif /* STRUCT_H */
