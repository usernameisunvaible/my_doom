#include "../includes/includes.h"

map_ *read_the_map(char *name)
{
    map_ *map = malloc(sizeof(map_));
    struct _stat buf;
    char *buffer;
    FILE *file;
    int i = 0;
    int nb = 0;
    int j = 0;
    int a = 0, b = 0, c = 0;

    if (_stat(name, &buf) == -1)
        exit(1);
    buffer =  malloc(sizeof(char) * buf.st_size + 1);
    if ((file = fopen(name, "r")) == NULL)
        exit(1);
    for (; (buffer[i] = fgetc(file)) != EOF; ++i);
    fclose(file);
    buffer[i] = 0;
    
    for(i = 0; buffer[i]; ++i)
        if (buffer[i] != '\n') {
            ++nb;
            ++a;
        } else {
            if (c && a != b) exit(1);
            b = a;
            c = 1;
            a = 0;
        }
    map->map = malloc(sizeof(char) * nb + 1);
    for(i = 0; buffer[i]; ++i) {
        if (buffer[i] != '\n') {
            map->map[j] = buffer[i];
            ++j;
        }
    }
    map->map[j] = 0;
    map->size_tot = j;
    map->size = define_vectori(b, j / b);
    return map;
}

sfBool colli(map_ *map, sfVector2f p)
{
    
    if (map->map[map->size.x * (int)(p.y / 64) + (int)(p.x / 64)] == 49)
        return sfTrue;
    return sfFalse;
}