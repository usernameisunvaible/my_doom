/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "includes/include_engine.h"

int str_comp(char *stra, char *strb)
{
    if (my_strlen(stra) != my_strlen(strb))
        return 0;
    for (int i = 0; stra[i]; ++i)
    {
        if (stra[i] != strb[i])
            return 0;
    }
    return 1;
}
