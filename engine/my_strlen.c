/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** count and returns the number of characteres found in a string
*/

int my_strlen(char const *str)
{
    int len = 0;
    while (str[len] != '\0'){
        len++;
    }
    return len;
}
