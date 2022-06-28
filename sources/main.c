#include "../includes/includes.h"

#define WIDTH 1920
#define HEIGHT 1080



int main (int ac, char **av)
{
    // sfVideoMode mode = {WIDTH, HEIGHT, 32};

    // sfRenderWindow *window = sfRenderWindow_create(mode, "my_world", sfClose | sfFullscreen | sfResize, NULL);

    // while (sfRenderWindow_isOpen(window)) {
    //     sfRenderWindow_clear(window, sfBlack);
    //     sfRenderWindow_display(window);
    // }
    read_the_map("map.txt");
    return 0;
}