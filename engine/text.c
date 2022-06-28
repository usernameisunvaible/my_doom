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

void add_font(char *path, all_my_font_t **list)
{
    all_my_font_t *part = malloc(sizeof(all_my_font_t));
    part->path = path;
    part->font = sfFont_createFromFile(path);
    part->next = *list;
    *list = part;
}

all_my_font_t *init_font(char **font_path)
{
    all_my_font_t *list = malloc(sizeof(all_my_font_t));

    list = NULL;
    for (int i = 0; font_path[i][0]; ++i) {
        add_font(font_path[i], &list);
    }
    return list;
}

text_params_t define_text_params(char *string, char *font_path, sfVector2f pos,
unsigned int size)
{
    text_params_t params;

    params.font_path = font_path;
    params.pos = pos;
    params.size = size;
    params.string = string;
    return params;
}

sfFont *get_font(elements_t *elements, char *path)
{
    all_my_font_t *temp;

    temp = elements->font_list;
    while (temp != NULL) {
        if (str_comp(path, temp->path))
            return temp->font;
        temp = temp->next;
    }
}

sfText *text_factory(text_params_t params, elements_t *elements)
{
    sfText *text = sfText_create();

    sfText_setPosition(text, params.pos);
    sfText_setString(text, params.string);
    sfText_setFont(text, get_font(elements, params.font_path));
    sfText_setCharacterSize(text, params.size);
    return text;
}
