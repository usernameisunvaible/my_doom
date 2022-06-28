/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include "includes/include_engine.h"

elements_t *init_elements(char **textures_path, char **font_path_list)
{
    elements_t *elements = malloc(sizeof(elements_t));
    sfVideoMode mode = {WIDTH, HEIGHT, 32};

    elements->window = sfRenderWindow_create(mode, "RPG",
sfClose | sfFullscreen, NULL);
    elements->tex_list = init_tex(textures_path);
    elements->font_list = init_font(font_path_list);
    elements->chrono = init_chrono();
    elements->m_pos = sfMouse_getPositionRenderWindow(elements->window);
    elements->left = sfMouse_isButtonPressed(sfMouseLeft);
    elements->right = sfMouse_isButtonPressed(sfMouseRight);
    elements->win_size = define_vectorf(WIDTH, HEIGHT);
    return elements;
}

void close_elements(elements_t *elements)
{
    free_tex(elements->tex_list);
    free(elements->chrono);
    sfRenderWindow_destroy(elements->window);
}

void refresh_elements(elements_t *elements)
{
    elapse_time(elements->chrono);
    sfRenderWindow_display(elements->window);
    elements->m_pos = sfMouse_getPositionRenderWindow(elements->window);
    elements->left = sfMouse_isButtonPressed(sfMouseLeft);
    elements-> right = sfMouse_isButtonPressed(sfMouseRight);
}
