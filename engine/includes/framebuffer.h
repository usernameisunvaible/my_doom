/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef FRAMEBUFFER_H_
    #define FRAMEBUFFER_H_

typedef struct framebuffer_s {
    sfUint8 *framebuffer;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2i fbuf_size;
}framebuffer_t;

#endif //FRAMEBUFFER_H_
