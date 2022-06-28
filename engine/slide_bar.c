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

slide_bar_t *init_slide_bar(elements_t *elements, slide_bar_params_t barp)
{
    slide_bar_t *bar = malloc(sizeof(slide_bar_t));

    bar->bar = sprite_factory(elements, define_sprite_param(barp.path,
0, 0, define_rect(0, 0, barp.bar_p.width, barp.bar_p.height)));
    sfSprite_setPosition(bar->bar->sprite,
define_vectorf(barp.bar_p.left, barp.bar_p.top));
    bar->button = sprite_factory(elements,
define_sprite_param(barp.path, 0, 0, define_rect(barp.bar_p.width,
0, barp.button_size.x, barp.button_size.y)));
    bar->but_pos = define_rect((barp.bar_p.left + (barp.bar_p.width / 2)) -
(barp.button_size.x / 2), (barp.bar_p.top + (barp.bar_p.height / 2)) -
(barp.button_size.y / 2), barp.button_size.x, barp.button_size.y);
    sfSprite_setPosition(bar->button->sprite,
define_vectorf(bar->but_pos.left, bar->but_pos.top));
    bar->pos = (int)barp.tot/2;
    bar->taille_tot = barp.tot;
    bar->start_bar = (barp.bar_p.left + barp.bar_p.width / 2) -
barp.tot / 2;
    hide_s(bar);
    return bar;
}

int mouse_on_but_bar(slide_bar_t *button, sfVector2i m_pos)
{
    if (m_pos.x >= button->but_pos.left && m_pos.x <= button->but_pos.left +
button->but_pos.width) {
        if (m_pos.y >= button->but_pos.top && m_pos.y <= button->but_pos.top +
button->but_pos.height)
            return 1;
    }
    return 0;
}

void anim_bar_two(slide_bar_t *bar)
{
    if (bar->pos < 0) {
        bar->pos = 0;
        bar->but_pos.left = (bar->start_bar ) - bar->but_pos.width / 2;
        sfSprite_setPosition(bar->button->sprite,
define_vectorf(bar->but_pos.left, bar->but_pos.top));
    }
}

void anim_bar(slide_bar_t *bar, elements_t *elements,
sfVector2i m_pos, sfBool click)
{
    refresh_sprite(bar->bar, elements, 0);
    refresh_sprite(bar->button, elements, 0);
    if (mouse_on_but_bar(bar, m_pos) && click) {
        if (bar->pos >= 0 && bar->pos <= bar->taille_tot) {
            bar->pos = m_pos.x - bar->start_bar;
            bar->but_pos.left = m_pos.x - bar->but_pos.width / 2;
            sfSprite_setPosition(bar->button->sprite,
define_vectorf(bar->but_pos.left, bar->but_pos.top));
        }
    }
    if (bar->pos > bar->taille_tot) {
        bar->pos = bar->taille_tot ;
        bar->but_pos.left = (bar->start_bar + bar->taille_tot) -
bar->but_pos.width / 2;
        sfSprite_setPosition(bar->button->sprite,
define_vectorf(bar->but_pos.left, bar->but_pos.top));
    }
    anim_bar_two(bar);
}

void show_slide_bar(slide_bar_t *bar, elements_t *elements)
{
    if (bar->infos & SHOW_F)
        anim_bar(bar, elements, elements->m_pos, elements->left);
}
