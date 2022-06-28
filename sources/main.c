#include "../includes/includes.h"


void draw_map(map_ *map, framebuffer_t *fbr)
{
    for (int i = 0; i < map->size.x ; ++i) {
        for (int j = 0; j < map->size.y; ++j) {
            if (map->map[map->size.x * j + i] == 49)
                draw_rect(fbr, define_rect(i * 64 , j * 64, i * 64 + 64, j * 64 + 64), sfWhite);
        }
    }
}

int main (int ac, char **av)
{
    elements_t *elements = load_assets();
    map_ *map = read_the_map("map.txt");
    framebuffer_t *fbr = init_framebuffer(define_vectori(1920, 1080));
    player_ *player = init_player();
    int i = 0;
    
    while (sfRenderWindow_isOpen(elements->window)) {

        while (sfRenderWindow_pollEvent(elements->window, &elements->event)) {
            if (elements->event.type == sfEvtClosed)
                sfRenderWindow_close(elements->window);
        }
        draw_rect(fbr, define_rect(0, 0, 1920, 1080), sfBlack);
        draw_map(map, fbr);
        
        draw_circle_from_point(player->pos, 13, fbr, sfGreen);
        
        refresh_framebuffer(fbr, elements);
        for (int i = 0; i < NB_RAY; ++i) {
            sfVertexArray_append(player->rays[i], define_vertex(define_vectorf(player->pos.x, player->pos.y), sfBlue));
            sfVertexArray_append(player->rays[i], define_vertex(
            define_vectorf((float) player->pos.x + RAY_LEN * dcos((player->angle - FOV / 2) + (i * (FOV / (float)NB_RAY))),
                           (float) player->pos.y + RAY_LEN * dsin((player->angle - FOV / 2) + (i * (FOV / (float)NB_RAY))) ), sfRed));

            sfRenderWindow_drawVertexArray(elements->window, player->rays[i], NULL);
            sfVertexArray_clear(player->rays[i]);
        }
        player->angle += 1;
        refresh_elements(elements);
        sfRenderWindow_clear(elements->window, sfBlack);
    }

    return 0;
}