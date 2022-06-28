/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef TEXT_P_H_
    #define TEXT_P_H_

all_my_font_t *init_font(char **font_path);
sfText *text_factory(text_params_t params, elements_t *elements);
text_params_t define_text_params(char *string, char *font_path, sfVector2f pos,
unsigned int size);
void refresh_text(elements_t *elements, sfText *text, char *string);

#endif //TEXT_P_H_
