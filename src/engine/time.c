/*
** EPITECH PROJECT, 2020
** time
** File description:
** time utilities
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "function.h"

int compare_time(sfClock *clock, float *balise, float delay)
{
    sfTime current_time = sfClock_getElapsedTime(clock);
    float time_float = sfTime_asMilliseconds(current_time);

    if (time_float >= *balise + delay) {
        *balise = time_float;
        return (1);
    }
    return (0);
}
