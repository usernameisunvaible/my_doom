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

sfVector2f colli_rays(int it, sfVector2f angles, player_ *player, map_ *map)
{
    sfVector2f temp;
    for (int i = 0; i < RAY_LEN; ++i) {
        temp.x = player->pos.x + i * angles.x;
        temp.y = player->pos.y + i * angles.y;
        if (colli(map, temp)) {
            player->hit[it] = sfTrue;
            return temp;
        }
    }
    player->hit[it] = sfFalse;
    return define_vectorf((float) player->pos.x + RAY_LEN * angles.x , (float) player->pos.y + RAY_LEN *  angles.y);
}

void draw_rays(player_ *player, elements_t *elements, map_ *map)
{
    sfVector2f tmp;
    sfVector2f angles;

    for (int i = 0; i < NB_RAY; ++i) {
        angles = define_vectorf(dcos((player->angle - FOV / 2) + (i * (FOV / (float)NB_RAY))), dsin((player->angle - FOV / 2) + (i * (FOV / (float)NB_RAY))));
        sfVertexArray_append(player->rays[i], define_vertex(define_vectorf(player->pos.x, player->pos.y), sfRed));

        tmp = colli_rays(i, angles, player, map);

        sfVertexArray_append(player->rays[i], define_vertex(tmp, sfRed));
        
            // sfRenderWindow_drawVertexArray(elements->window, player->rays[i], NULL);
            sfVertexArray_clear(player->rays[i]);
    }
}

void set_player_dir(player_ *player)
{
    player->vec_dir = define_vectorf((float) (player->pos.x + P_SPEED_FB * dcos(player->angle)) - player->pos.x , (float) (player->pos.y + P_SPEED_FB *  dsin(player->angle)) - player->pos.y);
    player->vec_dir_side = define_vectorf((float) (player->pos.x + P_SPEED_LR * dcos(player->angle + 90)) - player->pos.x , (float) (player->pos.y + P_SPEED_LR *  dsin(player->angle + 90)) - player->pos.y);
}   

int FixAng(int a){ if(a>359){ a-=360;} if(a<0){ a+=360;} return a;}


int main (int ac, char **av)
{
    elements_t *elements = load_assets(define_vectori(1920, 1080));
    map_ *map = read_the_map("map.txt");
    framebuffer_t *fbr = init_framebuffer(define_vectori(elements->win_size.x, elements->win_size.y));
    player_ *player = init_player();
    int i = 0;
    float depth;
    float wall_height;
    int color;
    float scale = elements->win_size.x / NB_RAY;

    while (sfRenderWindow_isOpen(elements->window)) {
        set_player_dir(player);
        while (sfRenderWindow_pollEvent(elements->window, &elements->event)) {
            if (elements->event.type == sfEvtClosed)
                sfRenderWindow_close(elements->window);
            if (elements->event.type == sfEvtKeyPressed) {
                (sfKeyZ == KEY_CODE) ? (player->move->top = sfTrue) : (0);
                (sfKeyS == KEY_CODE) ? (player->move->bottom = sfTrue) : (0);
                (sfKeyQ == KEY_CODE) ? (player->move->left = sfTrue) : (0);
                (sfKeyD == KEY_CODE) ? (player->move->right = sfTrue) : (0);
                (sfKeyLeft == KEY_CODE) ? (player->move->c_left = sfTrue) : (0);
                (sfKeyRight == KEY_CODE) ? (player->move->c_right = sfTrue) : (0);
            }
            if (elements->event.type == sfEvtKeyReleased) {
                (sfKeyZ == KEY_CODE) ? (player->move->top = sfFalse) : (0);
                (sfKeyS == KEY_CODE) ? (player->move->bottom = sfFalse) : (0);
                (sfKeyQ == KEY_CODE) ? (player->move->left = sfFalse) : (0);
                (sfKeyD == KEY_CODE) ? (player->move->right = sfFalse) : (0);
                (sfKeyLeft == KEY_CODE) ? (player->move->c_left = sfFalse) : (0);
                (sfKeyRight == KEY_CODE) ? (player->move->c_right = sfFalse) : (0);
            }
        }
        move_player(player);

        draw_rect(fbr, define_rect(0, 0, elements->win_size.x, elements->win_size.y), sfBlack);
        // draw_map(map, fbr);
        
        // draw_circle_from_point(player->pos, 13, fbr, sfGreen);
        for (int i = 0; i < NB_RAY; ++i) {
            if (player->hit[i]) {
                depth = dist_points(define_vectorf(player->pos.x, player->pos.y), sfVertexArray_getVertex(player->rays[i], 1)->position);
                color = ((255.0 / (float)RAY_LEN * depth) - 255) * -1;
                (color <= 0) ? (color = 0) : (0);
                (color >= 255) ? (color = 255) : (0);
                depth *= dcos(player->angle - (player->angle - FOV / 2));
                wall_height = 40000 / (depth + 0.0001);
                (wall_height > elements->win_size.y) ? (wall_height = elements->win_size.y) :(0);
                
                draw_rect(fbr, define_rect(i * scale, (elements->win_size.y / 2) - wall_height / 2, (i * scale) + scale, ((elements->win_size.y / 2) - wall_height / 2) + wall_height ), sfColor_fromRGB(color, color, color));
                // draw_line(fbr,define_vectorf(i + 700, RAY_LEN), define_vectorf(i + 700, ((dist_points(define_vectorf(player->pos.x, player->pos.y), sfVertexArray_getVertex(player->rays[i], 1)->position) - RAY_LEN) * -1) + RAY_LEN ), sfRed);
                // draw_line(fbr,define_vectorf(i + 700, RAY_LEN), define_vectorf(i + 700, dist_points(define_vectorf(player->pos.x, player->pos.y), sfVertexArray_getVertex(player->rays[i], 1)->position)  ), sfRed);
            }
        }
        refresh_framebuffer(fbr, elements);
        draw_rays(player, elements, map);
        // player->angle += 1;

        
        refresh_elements(elements);
        sfRenderWindow_clear(elements->window, sfBlack);
    }

    return 0;
}

