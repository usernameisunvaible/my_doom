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

framebuffer_t *init_framebuffer(sfVector2i fbuf_size)
{
    framebuffer_t *fbuffer = malloc(sizeof(framebuffer_t));

    fbuffer->framebuffer = malloc(sizeof(sfUint8) *
(fbuf_size.x * fbuf_size.y * 4));
    fbuffer->sprite = sfSprite_create();
    fbuffer->texture = sfTexture_create(fbuf_size.x, fbuf_size.y);
    sfSprite_setTexture(fbuffer->sprite, fbuffer->texture, sfTrue);
    fbuffer->fbuf_size = fbuf_size;
    return fbuffer;
}

void refresh_framebuffer(framebuffer_t *fbuffer, elements_t *elements)
{
    sfTexture_updateFromPixels(fbuffer->texture, fbuffer->framebuffer,
fbuffer->fbuf_size.x, fbuffer->fbuf_size.y, 0, 0);
    sfSprite_setTexture(fbuffer->sprite, fbuffer->texture, sfFalse);
    sfRenderWindow_drawSprite(elements->window, fbuffer->sprite, NULL);
}
