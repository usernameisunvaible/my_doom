/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef BUTTON_H_
    #define BUTTON_H_

typedef struct button_params_s {
    char *path;
    sfIntRect pos;
    int nb_rep;
    int ref_time;
}button_params_t;

typedef struct button_s {
    sfIntRect pos;
    sprite_sheet_t *idle;
    sprite_sheet_t *mouse;
    sprite_sheet_t *click;
    char infos;
}button_t;

#endif //BUTTON_H_
