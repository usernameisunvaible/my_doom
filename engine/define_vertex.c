/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "includes/include_engine.h"

sfVertex define_vertex(sfVector2f pos, sfColor color)
{
    sfVertex vert;

    vert.position = pos;
    vert.color =  color;
    return vert;
}
