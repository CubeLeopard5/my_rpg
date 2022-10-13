/*
** EPITECH PROJECT, 2019
** advanced_particle.c
** File description:
** advanced particle system
*/

#include "sflib_f.h"
#include <library.h>
#include "char_create.h"
#include <particles.h>

void advanced_particle_spray(sfVector2f position, sfColor color,
sfRenderWindow *win, int size)
{
    sfRectangleShape *particle = sfRectangleShape_create();
    sfVector2f particle_size = {3, 3};
    sfVector2f *position_array = malloc(sizeof(sfVector2f*) * 201);
    int *velocity = malloc(sizeof(int *) * 201);
    sfClock *clocking = sfClock_create();

    advanced_particle_init(position_array, position, velocity, size);
    sfRectangleShape_setFillColor(particle, color);
    sfRectangleShape_setSize(particle, particle_size);
    for (int i = 1 ; i != size ; i++) {
        while (sfClock_getElapsedTime(clocking).
        microseconds / 1000.00 <= 2);
        advanced_particle_daw_base(position_array, win, velocity, particle);
        sfClock_restart(clocking);
    }
    sfClock_destroy(clocking);
    free(position_array);
    free(velocity);
    sfRectangleShape_destroy(particle);
}

void advanced_particle_left_up(sfVector2f *position_array,
sfRenderWindow *win, int *velocity, sfRectangleShape *particle)
{
    static int i = 0;

    if (i >= 50)
        i = 0;
    if (position_array[i].x <= position_array[200].x + velocity[200] &&
    position_array[i].y <= position_array[200].y + velocity[200] &&
    position_array[i].x >= position_array[200].x - velocity[200] &&
    position_array[i].y >= position_array[200].y - velocity[200]) {
        if (rand() % 2 == 1)
            position_array[i].x -= velocity[i];
        else
            position_array[i].y += velocity[i];
    }
    else {
        position_array[i] = position_array[200];
        velocity[i] = (rand() % 4)+(rand() % 4);
    }
    sfRectangleShape_setPosition(particle, position_array[i]);
    i++;
}

void advanced_particle_righ_up(sfVector2f *position_array,
sfRenderWindow *win, int *velocity, sfRectangleShape *particle)
{
    static int i = 0;

    if (i >= 100)
        i = 50;
    if (position_array[i].x <= position_array[200].x+velocity[200] &&
    position_array[i].y <= position_array[200].y+velocity[200] &&
    position_array[i].x >= position_array[200].x-velocity[200] &&
    position_array[i].y >= position_array[200].y-velocity[200]) {
        if (rand() % 2 == 1)
            position_array[i].x += velocity[i];
        else
            position_array[i].y += velocity[i];
    }
    else {
        position_array[i] = position_array[200];
        velocity[i] = (rand() % 4)+(rand() % 4);
    }
    sfRectangleShape_setPosition(particle, position_array[i]);
    i++;
}

void advanced_particle_left_dn(sfVector2f *position_array,
sfRenderWindow *win, int *velocity, sfRectangleShape *particle)
{
    static int i = 0;

    if (i >= 150)
        i = 100;
    if (position_array[i].x <= position_array[200].x + velocity[200] &&
    position_array[i].y <= position_array[200].y + velocity[200] &&
    position_array[i].x >= position_array[200].x - velocity[200] &&
    position_array[i].y >= position_array[200].y - velocity[200]) {
        if (rand() % 2 == 1)
            position_array[i].x -= velocity[i];
        else
            position_array[i].y -= velocity[i];
    }
    else {
        position_array[i] = position_array[200];
        velocity[i] = (rand() % 4)+(rand() % 4);
    }
    sfRectangleShape_setPosition(particle, position_array[i]);
    i++;
}

void advanced_particle_righ_dn(sfVector2f *position_array,
sfRenderWindow *win, int *velocity, sfRectangleShape *particle)
{
    static int i = 0;

    if (i >= 200)
        i = 150;
    if (position_array[i].x <= position_array[200].x + velocity[200] &&
    position_array[i].y <= position_array[200].y + velocity[200] &&
    position_array[i].x >= position_array[200].x - velocity[200] &&
    position_array[i].y >= position_array[200].y - velocity[200]) {
        if (rand() % 2 == 1)
            position_array[i].x += velocity[i];
        else
            position_array[i].y -= velocity[i];
    }
    else {
        position_array[i] = position_array[200];
        velocity[i] = (rand() % 4)+(rand() % 4);
    }
    sfRectangleShape_setPosition(particle, position_array[i]);
    i++;
}