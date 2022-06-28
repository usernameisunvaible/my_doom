/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef TIME_H_
    #define TIME_H_

typedef struct chrono_s {
    long ms;
    int s;
    sfClock *clock;
}chrono_t;

chrono_t *init_chrono(void);
/*create a chrono who count time in second and milisecond.
This function is call in init_elements() */

void elapse_time(chrono_t *chrono);
/*refresh the chrono on each game refresh (you have to put it in the main
game loop). This function is call in refresh_elements()
args by args:

chrono_t *chrono: the struct which contain the timers in second and milisecond
*/

void free_chrono(chrono_t *chrono);
/*free the chrono who have been create with init_chrono.
This function is call in close_elements()
args by args:

chrono_t *chrono: the struct which contain the timers in second and milisecond
*/

#endif //TIME_H_
