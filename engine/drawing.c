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
#include <math.h>
#include "includes/include_engine.h"

void put_pixel(framebuffer_t *fbuffer, int x, int y, sfColor color)
{
    int i = 4 * WIDTH * y + x * 4;

    if (x < WIDTH && x > 0 && y < HEIGHT && y > 0) {
        fbuffer->framebuffer[i] = color.r;
        fbuffer->framebuffer[i + 1] = color.g;
        fbuffer->framebuffer[i + 2] = color.b;
        fbuffer->framebuffer[i + 3] = color.a;
    }
}

void draw_line(framebuffer_t *fbuffer, sfVector2f p1, sfVector2f p2,
sfColor color)
{
    sfVector2f p;
    double temp = (double)(square(p1.x - p2.x) + square(p1.y - p2.y));
    temp = sqrt(temp);
    for (float i = 0; i < 1; i += (float) 1 / temp) {
        p.x = p1.x + (p2.x - p1.x) * i;
        p.y = p1.y + (p2.y - p1.y) * i;
        put_pixel( fbuffer, p.x, p.y, color);
    }
}

void circle_draw_points(int *p_buf, framebuffer_t *fbuffer,
sfVector2i point, sfColor color)
{
    if (((p_buf[0] - point.x)*(p_buf[0] - point.x) ) +
((p_buf[1] - point.y)*(p_buf[1] - point.y)) < (p_buf[2] / 2) * (p_buf[2] / 2))
        put_pixel(fbuffer, p_buf[0], p_buf[1], color);
}

void draw_circle_from_point(sfVector2i point, int diameter,
framebuffer_t *fbuffer, sfColor color)
{
    int *p_buf = malloc(sizeof(int) * 3);
    p_buf[2] = diameter;
    for (int i = point.x - (diameter / 2); i < point.x +
(diameter / 2); ++i) {
        for (int j = point.y - (diameter / 2); j < point.y +
(diameter / 2); ++j) {
            p_buf[0] = i;
            p_buf[1] = j;
            circle_draw_points(p_buf, fbuffer, point, color);
        }
    }
    free(p_buf);
}

void draw_rect(framebuffer_t *fbuffer, sfIntRect rect, sfColor color)
{
    for (int i = rect.left; i < rect.width; ++i) {
        for (int j = rect.top; j < rect.height; ++j) {
            put_pixel(fbuffer, i, j, color);
        }
    }
}
