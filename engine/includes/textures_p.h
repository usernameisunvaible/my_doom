/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef TEXTURE_P_H_
    #define TEXTURE_P_H_

all_my_tex_t *init_tex(char **textures_paths);
/*create the linked list where all the textures will be loads, you don't
really have to care about it. This function is call in init_elements()
args by args:

char **textures_paths: this is an array who contain all the texture paths
*/

void free_tex(all_my_tex_t *list);
/*free the texture list. This function is call in close_elements()
args by args:

all_my_tex_t *list: this is the linked list which contain all the textures
*/

sfTexture *get_texture(char *path, all_my_tex_t *list);

#endif // TEXTURE_P_H_
