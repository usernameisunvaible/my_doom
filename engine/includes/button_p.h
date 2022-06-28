/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef BUTTON_P_H_
    #define BUTTON_P_H_

button_t *init_button(elements_t *elements, button_params_t params);
button_params_t define_button_params(char *path, sfIntRect pos,
int nb_rep, int ref_time);
void show_button(button_t *button, elements_t *elements);
void free_button(button_t *button);
void show_b(button_t *button);
void hide_b(button_t *button);
void unclick_b(button_t *button);
void click_b(button_t *button);

#endif //BUTTON_P_H_
