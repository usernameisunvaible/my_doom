/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef INIT_P_H_
    #define INIT_P_H_

elements_t *init_elements(char **textures_path, char **font_path_list);
/*This function create a struct which contain all the elements who need to
be in the program
args by args:

char **textures_paths: this is an array who contain all the texture paths
*/

void close_elements(elements_t *elements);
/*This function close and free all the element who have been create in
init_elements()
args by args:

elements_t *elements:the struct you have to create in the start of your
program with init_elements()
*/

void refresh_elements(elements_t *elements);
/*This function refresh the elements who need to be refresh. You have to put
it in the main loop
args by args:

elements_t *elements:the struct you have to create in the start of your
program with init_elements()
*/

#endif //INIT_P_H_
