#include "../includes/includes.h"



static movement_ *init_move(void)
{
    movement_ *move = malloc(sizeof(movement_));
    move->bottom = sfFalse;
    move->top = sfFalse;
    move->left = sfFalse;
    move->right = sfFalse;
    move->c_left = sfFalse;
    move->c_right = sfFalse;
}

player_ *init_player(void)
{
    player_ *player = malloc(sizeof(player_));
    player->angle = 0;
    player->pos = define_vectori(100, 100);
    player->rays = malloc(sizeof(sfVertexArray *) * NB_RAY);
    player->hit = malloc(sizeof(sfBool) * NB_RAY);
    for (int i = 0; i < NB_RAY; ++i) {
        player->hit[i] = sfFalse;
        player->rays[i] = sfVertexArray_create();
        sfVertexArray_setPrimitiveType(player->rays[i], sfLines);  
    }
    player->move = init_move();
    player->vec_dir = define_vectorf(0, 0);
    player->vec_dir_side = define_vectorf(0, 0);
    return player;
}

void move_player(player_ *player)
{
    if (player->move->top) {player->pos.x += player->vec_dir.x; player->pos.y += player->vec_dir.y;}
    if (player->move->bottom) {player->pos.x -= player->vec_dir.x; player->pos.y -= player->vec_dir.y;}
    if (player->move->left) {player->pos.x -= player->vec_dir_side.x; player->pos.y -= player->vec_dir_side.y;}
    if (player->move->right) {player->pos.x += player->vec_dir_side.x; player->pos.y += player->vec_dir_side.y;}



    // (player->move->bottom) ? (player->pos.y += P_SPEED) : (0);
    // (player->move->left) ? (player->pos.x -= P_SPEED) : (0);
    // (player->move->right) ? (player->pos.x += P_SPEED) : (0);
    (player->move->c_left) ? (player->angle -= C_SPEED) : (0);
    (player->move->c_right) ? (player->angle += C_SPEED) : (0);

}