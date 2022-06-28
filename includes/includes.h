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

#define NB_RAY 1080

#define FOV 80

#define RAY_LEN 350

#define P_SPEED_FB 5
#define P_SPEED_LR 3

#define C_SPEED 4