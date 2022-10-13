/*
** EPITECH PROJECT, 2019
** particle.c
** File description:
** particle system
*/

#include "sflib_f.h"
#include <library.h>
#include "char_create.h"
#include <particles.h>

void particle_spray(sfVector2f position, sfColor color,
sfRenderWindow *win, int size)
{
    sfRectangleShape *particle = sfRectangleShape_create();
    sfVector2f particle_size = {4, 4};
    sfClock *clocking = sfClock_create();

    sfRectangleShape_setFillColor(particle, color);
    sfRectangleShape_setSize(particle, particle_size);
    for (int z = 0 ; z != 2 ; z++) {
        for (int i = 1 ; i != size+1 ; i++) {
            while (sfClock_getElapsedTime(clocking).
            microseconds / 10000.00 <= 1);
            draw_particle_system_fixed_angle(position, particle, win, i);
            draw_particle_system_random_angle(position, particle, win, i);
            sfRenderWindow_display(win);
            sfClock_restart(clocking);
        }
    }
    sfClock_destroy(clocking);
    sfRectangleShape_destroy(particle);
}

void draw_particle_system_random_angle(sfVector2f position, sfRectangleShape
*particle, sfRenderWindow *win, int i)
{
    sfVector2f refe = sfRectangleShape_getPosition(particle);

    if (rand() % 10 <= 4)
        sfRectangleShape_setPosition(particle, (sfVector2f) {.x =
        refe.x + 6 + i, .y = refe.y});
    else
        sfRectangleShape_setPosition(particle, (sfVector2f) {.x =
        refe.x, .y = refe.y + 6 + i});
    sfRenderWindow_drawRectangleShape(win, particle, NULL);
    if (rand() % 10 <= 4)
        sfRectangleShape_setPosition(particle, (sfVector2f) {.x =
        refe.x-(6+i), .y = refe.y});
    else
        sfRectangleShape_setPosition(particle, (sfVector2f) {.x =
        refe.x, .y = refe.y-(6+i)});
    sfRenderWindow_drawRectangleShape(win, particle, NULL);
}

void draw_particle_system_fixed_angle(sfVector2f position, sfRectangleShape
*particle, sfRenderWindow *win, int i)
{
    sfRectangleShape_setPosition(particle, (sfVector2f) {.x =
    position.x+(i+5), .y = position.y+(i+5)});
    sfRenderWindow_drawRectangleShape(win, particle, NULL);
    draw_particle_system_random_angle(position, particle, win, i);
    sfRectangleShape_setPosition(particle, (sfVector2f) {.x =
    position.x+(i+5), .y = position.y});
    sfRenderWindow_drawRectangleShape(win, particle, NULL);
    draw_particle_system_random_angle(position, particle, win, i);
    sfRectangleShape_setPosition(particle, (sfVector2f) {.x =
    position.x, .y = position.y+(i+5)});
    sfRenderWindow_drawRectangleShape(win, particle, NULL);
    draw_particle_system_random_angle(position, particle, win, i);
    sfRectangleShape_setPosition(particle, (sfVector2f) {.x =
    position.x-(i+5), .y = position.y+(i+5)});
    sfRenderWindow_drawRectangleShape(win, particle, NULL);
    draw_particle_system_random_angle(position, particle, win, i);
    sfRectangleShape_setPosition(particle, (sfVector2f) {.x =
    position.x+(i+5), .y = position.y-(i+5)});
    sfRenderWindow_drawRectangleShape(win, particle, NULL);
    draw_particle_system_random_angle(position, particle, win, i);
}

void draw_particle_system_fixed_angle_next(sfVector2f position,
sfRectangleShape *particle, sfRenderWindow *win, int i)
{
    sfRectangleShape_setPosition(particle, (sfVector2f) {.x =
    position.x-(i+5), .y = position.y-(i+5)});
    sfRenderWindow_drawRectangleShape(win, particle, NULL);
    draw_particle_system_random_angle(position, particle, win, i);
    sfRectangleShape_setPosition(particle, (sfVector2f) {.x =
    position.x-(i+5), .y = position.y});
    sfRenderWindow_drawRectangleShape(win, particle, NULL);
    draw_particle_system_random_angle(position, particle, win, i);
    sfRectangleShape_setPosition(particle, (sfVector2f) {.x =
    position.x, .y = position.y-(i+5)});
    sfRenderWindow_drawRectangleShape(win, particle, NULL);
    draw_particle_system_random_angle(position, particle, win, i);
}

void advanced_particle_init(sfVector2f *position_array,
sfVector2f position, int *velocity, int size)
{
    for (int i = 0; i < 200 ; i++) {
        position_array[i] = ((sfVector2f) {.x = position.x, .y = position.y});
        velocity[i] = (rand() % 4)+(rand() % 4);
    }
    position_array[200] = ((sfVector2f) {.x = position.x, .y = position.y});
    velocity[200] = size;
    velocity[201] = '\0';
}