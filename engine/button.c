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

button_t *init_button(elements_t *elements, button_params_t params)
{
    button_t *button = malloc(sizeof(button_t));
    button->idle = sprite_factory(elements, define_sprite_param(params.path,
0, 0, define_rect(0, 0, params.pos.width, params.pos.height)));
    sfSprite_setPosition(button->idle->sprite, define_vectorf(params.pos.left,
params.pos.top));
    button->mouse = sprite_factory(elements, define_sprite_param(params.path,
params.ref_time, params.nb_rep, define_rect(0, params.pos.height,
params.pos.width, params.pos.height)));
    sfSprite_setPosition(button->mouse->sprite, define_vectorf(params.pos.left,
params.pos.top));
    button->click = sprite_factory(elements, define_sprite_param(params.path,
params.ref_time, params.nb_rep, define_rect(0, params.pos.height * 2,
params.pos.width, params.pos.height)));
    sfSprite_setPosition(button->click->sprite, define_vectorf(params.pos.left,
params.pos.top));
    button->pos = params.pos;
    button->infos = 0;
    return button;
}

int mouse_on_but(button_t *button, sfVector2i m_pos)
{
    if (m_pos.x >= button->pos.left && m_pos.x <= button->pos.left +
button->pos.width) {
        if (m_pos.y >= button->pos.top && m_pos.y <= button->pos.top +
button->pos.height)
            return 1;
    }
    return 0;
}

void anim_button(button_t *button, elements_t *elements, sfVector2i m_pos)
{
    if (mouse_on_but(button, m_pos)) {
        if (elements->left) {
            refresh_sprite(button->click, elements, 0);
            click_b(button);
        }
        else
            refresh_sprite(button->mouse, elements, 0);
    }
    else
        refresh_sprite(button->idle, elements, 0);
}

void show_button(button_t *button, elements_t *elements)
{
    if (button->infos & SHOW_F) {
        anim_button(button, elements, elements->m_pos);
    }
}

void free_button(button_t *button)
{
    free(button->idle);
    free(button->mouse);
    free(button->click);
}
