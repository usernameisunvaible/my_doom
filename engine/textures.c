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

sfTexture *get_texture(char *path, all_my_tex_t *list)
{
    all_my_tex_t *temp;

    temp = list;
    while (temp != NULL) {
        if (str_comp(path, temp->path))
            return temp->texture;
        temp = temp->next;
    }
}

void add_tex(char *path, all_my_tex_t **list)
{
    sfVector2u buf;

    all_my_tex_t *part = malloc(sizeof(all_my_tex_t));
    part->path = path;
    part->image = sfImage_createFromFile(path);
    part->texture = sfTexture_createFromImage(part->image, NULL);
    buf = sfTexture_getSize(part->texture);
    part->pixels = malloc(sizeof(sfUint8) * buf.x * buf.y * 4);
    part->pixels = sfImage_getPixelsPtr(part->image);
    part->next = *list;
    *list = part;
}

all_my_tex_t *init_tex(char **textures_paths)
{
    all_my_tex_t *list = malloc(sizeof(all_my_tex_t));

    list = NULL;
    for (int i = 0; textures_paths[i][0]; ++i) {
        add_tex(textures_paths[i], &list);
    }
    return list;
}

void free_tex(all_my_tex_t *list)
{
    all_my_tex_t *temp;

    temp = list;
    while (list != NULL) {
        list = list->next;
        free(temp);
        temp = list;
    }
}
