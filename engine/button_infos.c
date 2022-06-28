/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "includes/include_engine.h"

button_params_t define_button_params(char *path, sfIntRect pos, int nb_rep,
int ref_time)
{
    button_params_t params;

    params.path = path;
    params.pos = pos;
    params.nb_rep = nb_rep;
    params.ref_time = ref_time;
    return params;
}

void show_b(button_t *button)
{
    button->infos = button->infos | SHOW_F;
}

void hide_b(button_t *button)
{
    char tmp = 0;
    for (int i = 0; i < 6; ++i) {
        tmp = tmp | CLICK_F;
        tmp = tmp << 1;
    }
    tmp = tmp << 1;
    tmp = tmp | CLICK_F;
    button->infos = button->infos & tmp;
}

void click_b(button_t *button)
{
    button->infos = button->infos | CLICK_F;
}

void unclick_b(button_t *button)
{
    char tmp = 0;
    for (int i = 0; i < 7; ++i) {
        tmp = tmp | CLICK_F;
        tmp = tmp << 1;
    }
    tmp = tmp << 1;
    button->infos = button->infos & SHOW_F;
}
