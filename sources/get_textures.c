#include "../includes/includes.h"

elements_t *load_assets(void)
{
    char *textures[] = {"\0"};
    char *fonts[] = {"\0"};
    return init_elements(textures, fonts, define_vectori(1920, 1080));
}