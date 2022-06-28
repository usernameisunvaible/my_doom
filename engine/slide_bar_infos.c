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

slide_bar_params_t define_slide_bar_params(char *path, int tot,
sfVector2i button_size, sfIntRect bar_pos)
{
    slide_bar_params_t bar_params;

    bar_params.path = path;
    bar_params.tot = tot;
    bar_params.button_size = button_size;
    bar_params.bar_p = bar_pos;
    return bar_params;
}

void show_s(slide_bar_t *button)
{
    button->infos = button->infos | SHOW_F;
}

void hide_s(slide_bar_t *button)
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

void click_s(slide_bar_t *button)
{
    button->infos = button->infos | CLICK_F;
}

void unclick_s(slide_bar_t *button)
{
    char tmp = 0;
    for (int i = 0; i < 7; ++i) {
        tmp = tmp | CLICK_F;
        tmp = tmp << 1;
    }
    tmp = tmp << 1;
    button->infos = button->infos & SHOW_F;
}
