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

sfIntRect define_rect(int a, int b, int c, int d)
{
    sfIntRect rect;
    rect.left = a;
    rect.top = b;
    rect.width = c;
    rect.height = d;
    return rect;
}
