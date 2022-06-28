/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef TEXTURES_H_
    #define TEXTURES_H_

typedef struct all_my_tex_s {
    sfImage *image;
    sfTexture *texture;
    const sfUint8 *pixels;
    char *path;
    struct all_my_tex_s *next;
} all_my_tex_t;

#endif //TEXTURES_H_
