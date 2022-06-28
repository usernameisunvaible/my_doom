/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef SLIDE_BAR_P_H_
    #define SLIDE_BAR_P_H_

slide_bar_t *init_slide_bar(elements_t *elements,
slide_bar_params_t bar_params);
void show_slide_bar(slide_bar_t *bar, elements_t *elements);
void show_s(slide_bar_t *button);
void hide_s(slide_bar_t *button);
void click_s(slide_bar_t *button);
void unclick_s(slide_bar_t *button);
slide_bar_params_t define_slide_bar_params(char *path, int tot,
sfVector2i button_size, sfIntRect bar_pos);

#endif //SLIDE_BAR_P_H_
