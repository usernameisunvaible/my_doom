/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef FRAMEBUFFER_P_H_
    #define FRAMEBUFFER_P_H_

framebuffer_t *init_framebuffer(sfVector2i fbuf_size);
void refresh_framebuffer(framebuffer_t *framebuffer, elements_t *elements);
void draw_line(framebuffer_t *fbuffer, sfVector2f p1, sfVector2f p2,
sfColor color);
void put_pixel(framebuffer_t *fbuffer, int x, int y, sfColor color);
void draw_circle_from_point(sfVector2i point, int radius,
framebuffer_t *fbuffer, sfColor color);
void draw_rect(framebuffer_t *fbuffer, sfIntRect rect, sfColor color);

#endif // FRAMEBUFFER_P_H_
