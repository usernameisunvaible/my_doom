/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef SPRITE_H_
    #define SPRITE_H_

typedef struct sprite_sheet_s {
    sfSprite *sprite;
    const sfUint8 *pixels;
    sfVector2i pos_tex;
    int size_x;
    int size_y;
    int nb_rep;
    int count;
    int timer;
    int timer_tot;
    int ref_time;
} sprite_sheet_t;

typedef struct sprite_param_s {
    char *path;
    int ref_time;
    int nb_rep;
    sfIntRect sprite_rect;
} sprite_param_t;

#endif//SPRITE_H_
