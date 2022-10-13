/*
** EPITECH PROJECT, 2020
** init time
** File description:
** init_time
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "function.h"

void init_time(my_time_t *time)
{
    time->clock = sfClock_create();
}