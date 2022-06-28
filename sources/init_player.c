#include "../includes/includes.h"

player_ *init_player(void)
{
    player_ *player = malloc(sizeof(player_));
    player->angle = 0;
    player->pos = define_vectori(100, 100);
    player->rays = malloc(sizeof(sfVertexArray *) * NB_RAY);
    player->p_rays = malloc(sizeof(sfVertex) * NB_RAY);
    for (int i = 0; i < NB_RAY; ++i) {

        player->rays[i] = sfVertexArray_create();
        sfVertexArray_setPrimitiveType(player->rays[i], sfLines);
        // sfVertexArray_append(player->rays[i], define_vertex(define_vectorf(player->pos.x, player->pos.y), sfBlue));
        // player->p_rays[i] = define_vertex(define_vectorf((float) player->pos.x + 200 * dcos((player->angle - FOV / 2) + (i * (FOV / NB_RAY))),
        //                    (float) player->pos.y + 200 * dsin((player->angle - FOV / 2) + (i * (FOV / NB_RAY))) ), sfRed);
        // sfVertexArray_append(player->rays[i], player->p_rays[i]);
            
    }
    return player;
}
