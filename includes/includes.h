#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <malloc.h>
#include <share.h>
#include <io.h>
#include <mem.h>
#include <math.h>

#define PI 3.1415

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#include "../engine/includes/include_engine.h"
#include "map.h"
#include "player.h"

#include "proto.h"

#define KEY_CODE elements->event.key.code

#define NB_RAY 300

#define FOV 60

#define RAY_LEN 250