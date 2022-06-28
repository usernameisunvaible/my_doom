/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef TEXT_H_
    #define TEXT_H_

typedef struct all_my_font_s {
    sfFont *font;
    char *path;
    struct all_my_font_s *next;
}all_my_font_t;

typedef struct text_params_s {
    char *font_path;
    char *string;
    sfVector2f pos;
    unsigned int size;
}text_params_t;

#endif //TEXT_H_
