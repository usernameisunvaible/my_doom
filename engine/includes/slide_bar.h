/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef SLIDE_BAR_H_
    #define SLIDE_BAR_H_

typedef struct slide_bar_params_s {
    char *path;
    int tot;
    sfVector2i button_size;
    sfIntRect bar_p;
}slide_bar_params_t;

typedef struct slide_bar_s {
    sprite_sheet_t *bar;
    sprite_sheet_t *button;
    sfIntRect but_pos;
    int taille_tot;
    int pos;
    int start_bar;
    char infos;
}slide_bar_t;

#endif //SLIDE_BAR_H_
