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

int colli_rect_rect(sfIntRect a, sfIntRect b)
{
    if (a.left + a.width >= b.left && a.left <= b.left + b.width) {
        if (a.top + a.height >= b.top && a.top <= b.top + b.height) {
            return 1;
        }
    }
    return 0;
}
