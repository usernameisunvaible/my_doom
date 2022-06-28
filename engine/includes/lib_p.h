/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef LIB_H_
    #define LIB_H_

int my_strlen(char const *str);
/*my_strlen epitech friendly*/

sfIntRect define_rect(int a, int b, int c, int d);
/*This function create a sfIntRect with her 4 arguments
args by args:

int a: the x start of the rect
int b: the y start of the rect
int c: the x size of the rect
int d: the y size of the rect
*/

sfVector2i define_vectori(int x, int y);
sfVector2f define_vectorf(float x, float y);
sfVector3f define_vectortf(float x, float y, float z);
int str_comp(char *stra, char *strb);
sfVertex define_vertex(sfVector2f pos, sfColor color);
int square(int a);

#endif //LIB_H_
