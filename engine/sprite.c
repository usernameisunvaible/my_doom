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

sprite_param_t define_sprite_param(char *path, int ref_time, int nb_rep,
sfIntRect sprite_rect)
{
    sprite_param_t sprite_p;
    int a;

    (ref_time < 1) ? (ref_time = 1) : (ref_time = ref_time);
    a = (int)1000/ref_time;
    (a < 1) ? (a = 1) : (a = a);
    (nb_rep < 1) ? (nb_rep = 1) : (nb_rep = nb_rep);
    sprite_p.path = path;
    sprite_p.ref_time = a;
    sprite_p.nb_rep = nb_rep;
    sprite_p.sprite_rect = sprite_rect;
    return sprite_p;
}

void sprite_factory_two(sprite_sheet_t *sprite_sheet, all_my_tex_t *temp,
sprite_param_t sprite_p)
{
    sprite_sheet->pixels = temp->pixels;
    sprite_sheet->size_x = sprite_p.sprite_rect.width;
    sprite_sheet->size_y = sprite_p.sprite_rect.height;
    sprite_sheet->nb_rep = sprite_p.nb_rep;
    sprite_sheet->timer = 0;
    sprite_sheet->timer_tot = 0;
    sprite_sheet->count = 0;
    sprite_sheet->pos_tex = define_vectori(sprite_p.sprite_rect.left,
sprite_p.sprite_rect.top);
}

sprite_sheet_t *sprite_factory(elements_t *elements, sprite_param_t sprite_p)
{
    all_my_tex_t *temp;
    sprite_sheet_t *sprite_sheet = malloc(sizeof(sprite_sheet_t));
    temp = elements->tex_list;

    while (temp != NULL) {
        if (str_comp(sprite_p.path, temp->path)) {
            sprite_sheet->sprite = sfSprite_create();
            sfSprite_setTexture(sprite_sheet->sprite, temp->texture, sfTrue);
            sfSprite_setTextureRect(sprite_sheet->sprite,
sprite_p.sprite_rect);
            sprite_factory_two(sprite_sheet, temp, sprite_p);
            sprite_sheet->ref_time = sprite_p.ref_time;
            return sprite_sheet;
        }
        temp = temp->next;
    }
    write(1, "Un chemin d'acces d'une texture n'est pas juste lors du \
chargement d'un sprite: ", 80);
    write(1, sprite_p.path, my_strlen(sprite_p.path));
    write(1, "\n", 1);
}

void refresh_sprite_count(sprite_sheet_t *sprite_sheet)
{
    ++sprite_sheet->count;
    if (sprite_sheet->count == sprite_sheet->nb_rep)
        sprite_sheet->count = 0;
}

void refresh_sprite(sprite_sheet_t *sprite_sheet, elements_t *elements,
int ext_count)
{
    if (sprite_sheet->nb_rep > 1) {
        sprite_sheet->timer_tot += elements->chrono->ms -
sprite_sheet->timer;
        while (sprite_sheet->timer_tot >= sprite_sheet->ref_time) {
            sfSprite_setTextureRect(sprite_sheet->sprite, define_rect(
sprite_sheet->size_x * sprite_sheet->count, sprite_sheet->pos_tex.y,
sprite_sheet->size_x, sprite_sheet->size_y));
            (ext_count == 0) ? (refresh_sprite_count(sprite_sheet)) : (0);
            sprite_sheet->timer_tot -= sprite_sheet->ref_time;
        }
        sprite_sheet->timer = elements->chrono->ms;
    }
    sfRenderWindow_drawSprite(elements->window, sprite_sheet->sprite, NULL);
}
