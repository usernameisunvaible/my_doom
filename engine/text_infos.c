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

void refresh_text(elements_t *elements, sfText *text, char *string)
{
    if (string[0])
        sfText_setString(text, string);
    sfRenderWindow_drawText(elements->window, text, NULL);
}
