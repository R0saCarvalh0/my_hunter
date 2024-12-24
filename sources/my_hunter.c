/*
** EPITECH PROJECT, 2024
** B-MUL-100-BDX-1-1-myhunter-rosa.carvahlo
** File description:
** my_hunter.c
*/

#include "../include/my.h"
#include "../include/my_hunter.h"

static int died_dino(backG_t *bg, sprite_t *dino, texte_t *txt)
{
    sfFloatRect sprite;
    sfVector2i pos_mouse = {bg->event.mouseButton.x, bg->event.mouseButton.y};
    sfVector2f abs_pos;
    sound_t *sound = creat_sound();

    abs_pos = sfRenderWindow_mapPixelToCoords(bg->window, pos_mouse, NULL);
    sprite = sfSprite_getGlobalBounds(dino->sprite_S);
    if (sfFloatRect_contains(&sprite, abs_pos.x, abs_pos.y)){
        sfSound_play(sound->Sound);
        dino->pos.x = -100;
        dino->pos.y = rand() % 800;
        txt->score += 1;
        sfSprite_setPosition(dino->sprite_S, dino->pos);
    }
    return 0;
}

int manage_event(backG_t *bg, sprite_t *dino, texte_t *txt)
{
    while (sfRenderWindow_pollEvent(bg->window, &(bg->event))){
        if (bg->event.type == sfEvtClosed)
            sfRenderWindow_close(bg->window);
        if (bg->event.type == sfEvtKeyPressed &&
            bg->event.key.code == sfKeyEscape)
            sfRenderWindow_close(bg->window);
        if (bg->event.type == sfEvtMouseButtonPressed)
            died_dino(bg, dino, txt);
    }
    return 0;
}

int creat_clock(sprite_t *dino, texte_t *txt)
{
    sfClock *clock;
    sfTime time;
    float seconds = 0.0;

    dino->vitesse = 20.0;
    clock = sfClock_create();
    if (txt->score > 5)
        dino->vitesse = 40.0;
    if (txt->score > 10)
        dino->vitesse = 60.0;
    if (txt->score > 15)
        dino->vitesse = 80.0;
    if (txt->score > 20)
        dino->vitesse = 100.0;
    while (seconds <= 1.0 / dino->vitesse) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
    }
    sfClock_destroy(clock);
    return 0;
}

sprite_t *animation_dino(backG_t *bg, sprite_t *dino)
{
    if (dino->pos.x >= 1920){
        dino->pos.x = -100;
        dino->pos.y = rand() % 800;
        dino->vie -= 1;
        if (dino->vie == 0){
            bg->valeur_return = 2;
        }
    }
    if (dino->pos_0 > DINO_SIZE * 7)
        dino->pos_0 = FIRST_DINO_SPRITE;
    return dino;
}

void display_window(backG_t *bg, sprite_t *dino, texte_t *text,
    mousesprite_t *mouse_s)
{
    play_t *play = creat_play();
    gameover_t *GO = creat_go();

    dino->pos_0 = FIRST_DINO_SPRITE;
    while (sfRenderWindow_isOpen(bg->window) == 1){
        if (bg->valeur_return == 0)
            display_menu(bg, play, text);
        if (bg->valeur_return == 1)
            display_game(dino, text, bg, mouse_s);
        if (bg->valeur_return == 2){
            display_end(bg, GO);
        }
    }
    destroy_end(GO);
    destroy_menu(play);
}

static sprite_t *create_dino(void)
{
    sprite_t *dino = malloc(sizeof(sprite_t));

    dino->vie = 3;
    dino->texture_S = sfTexture_createFromFile("./assets/DinoSprites_red.png",
                                                NULL);
    dino->sprite_S = sfSprite_create();
    sfSprite_setScale(dino->sprite_S, (sfVector2f){5, 5});
    sfSprite_setTexture(dino->sprite_S, dino->texture_S, sfTrue);
    dino->pos = (sfVector2f){-100, 750};
    return dino;
}

static sfMusic *init_music(void)
{
    sfMusic *music;

    music = sfMusic_createFromFile("./assets/Jurassic_Park.ogg");
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, 1000.0);
    sfMusic_play(music);
    return music;
}

static texte_t *init_text(void)
{
    texte_t *txt = malloc(sizeof(texte_t));

    txt->score = 0;
    txt->level = 1;
    txt->str = "Dino-Hunt";
    txt->text = sfText_create();
    txt->font = sfFont_createFromFile("./assets/Conthrax-SemiBold.otf");
    sfText_setFont(txt->text, txt->font);
    sfText_setCharacterSize(txt->text, 35);
    sfText_setFillColor(txt->text, (sfColor_fromRGB(236, 171, 58)));
    sfText_setPosition(txt->text, (sfVector2f) {810, 100});
    sfText_setString(txt->text, txt->str);
    return txt;
}

static int open_window(backG_t *bg)
{
    sfVideoMode mode = {1920, 1080, 64};
    sprite_t *dino;
    sfMusic *music = init_music();
    texte_t *text = init_text();
    mousesprite_t *mouse_s = creat_mouse();

    bg->valeur_return = 0;
    bg->window = sfRenderWindow_create(mode, "My_Hunter",
                                        sfClose, NULL);
    if (!bg->window)
        return 84;
    sfRenderWindow_setFramerateLimit(bg->window, 60);
    bg->texture = sfTexture_createFromFile("./assets/background.jpg", NULL);
    bg->sprite = sfSprite_create();
    sfSprite_setTexture(bg->sprite, bg->texture, sfTrue);
    dino = create_dino();
    display_window(bg, dino, text, mouse_s);
    destroy(music, text, bg, dino);
    set_level(text);
    return 0;
}

int my_hunter(int argc, char **argv)
{
    backG_t *back = malloc(sizeof(backG_t));

    if (!back)
        return 84;
    if (argc == 1)
        open_window(back);
    else {
        if (argv[1][0] == '-' && argv[1][1] == 'h')
            my_cat("./assets/description_program.txt");
    }
    return 0;
}
