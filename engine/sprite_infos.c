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

void free_sprite(sprite_sheet_t *sprite_sheet)
{
    sfSprite_destroy(sprite_sheet->sprite);
    free(sprite_sheet);
}
