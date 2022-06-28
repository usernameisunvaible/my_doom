void *mmalloc(size_t size);
map_ *read_the_map(char *name);
elements_t *load_assets(void);
float to_rad(float deg);
float dcos(float deg);
float dsin(float deg);
player_ *init_player(void);
sfBool colli(map_ *map, sfVector2f p);
void move_player(player_ *player);
double dist_points(sfVector2f pa, sfVector2f pb);

