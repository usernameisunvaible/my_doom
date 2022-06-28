/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef SPRITE_P_H_
    #define SPRITE_P_H_

sprite_sheet_t *sprite_factory(elements_t *elements, sprite_param_t sprite_p);
/*create a sprite from the path of the texture. You have to free
the sprite_sheet_t * after use
args by args:

elements_t *elements:the struct you have to create in the start of your program
with init_elements()
sprite_param_t: the strucur wich will contain the params for the sprite sheet
*/

sprite_param_t define_sprite_param(char *path, int ref_time, int nb_rep,
sfIntRect sprite_rect);
/*only use in the sprite factory in order to give the differents params
args by args:

char *path: the path of the texture you take
int ref_time: the number of refresh by second you want for the sprite sheet
int nbr_rep: the nbr of images you have one the texture
sfIntRect sprite_rect: the rect you take on the texture for the sprite
*/

void refresh_sprite(sprite_sheet_t *sprite_sheet, elements_t *elements,
int ext_count);
/*refresh the sprite sheet create with the sprite factory, you have to put
it in your main clock if you want to see your sprite
args by args:

sprite_sheet_t *sprite_sheet: This is the structur who contain your sprite and
all his elements
elements_t *elements: the struct you have to create in the start of your
program with init_elements()
*/

void free_sprite(sprite_sheet_t *sprite_sheet);

#endif // SPRITE_P_H_
