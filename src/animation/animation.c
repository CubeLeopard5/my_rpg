/*
** EPITECH PROJECT, 2019
** animation.c
** File description:
** animator
*/

#include "sflib_f.h"
#include <library.h>
#include "char_create.h"
#include <particles.h>

void attack_move_left_to_right(sfSprite *sprite, sfRenderWindow *win, int dist)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2f refer = sfSprite_getPosition(sprite);
    sfClock *clocking = sfClock_create();

    for (pos.x-dist ; pos.x < refer.x + dist + 1 ; pos.x += 1) {
        while (sfClock_getElapsedTime(clocking).microseconds / 1000.00  <= 1);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(win, sprite, NULL);
        sfRenderWindow_display(win);
        sfClock_restart(clocking);
    }
    for (pos.x ; pos.x > refer.x-(dist+1) ; pos.x -= 1) {
        while (sfClock_getElapsedTime(clocking).microseconds / 1000.00  <= 1);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(win, sprite, NULL);
        sfRenderWindow_display(win);
        sfClock_restart(clocking);
    }
    attack_move_left_to_right_destroy(sprite, win, clocking, refer);
}

void attack_move_down_to_up(sfSprite *sprite, sfRenderWindow *win, int dist)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2f refer = sfSprite_getPosition(sprite);
    sfClock *clocking = sfClock_create();

    for (pos.y-dist ; pos.y < refer.y + dist + 1 ; pos.y += 1) {
        while (sfClock_getElapsedTime(clocking).microseconds / 1000.00  <= 1);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(win, sprite, NULL);
        sfRenderWindow_display(win);
        sfClock_restart(clocking);
    }
    for (pos.y ; pos.y > refer.y - (dist + 1) ; pos.y -= 1) {
        while (sfClock_getElapsedTime(clocking).microseconds / 1000.00  <= 1);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(win, sprite, NULL);
        sfRenderWindow_display(win);
        sfClock_restart(clocking);
    }
    attack_move_down_to_up_destroy(sprite, win, clocking, refer);
}

void attack_move_right_to_left(sfSprite *sprite, sfRenderWindow *win, int dist)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2f refer = sfSprite_getPosition(sprite);
    sfClock *clocking = sfClock_create();

    for (pos.x+dist ; pos.x > refer.x - (dist + 1) ; pos.x -= 1) {
        while (sfClock_getElapsedTime(clocking).microseconds / 1000.00  <= 1);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(win, sprite, NULL);
        sfRenderWindow_display(win);
        sfClock_restart(clocking);
    }
    for (pos.x ; pos.x < refer.x+dist+1 ; pos.x += 1) {
        while (sfClock_getElapsedTime(clocking).microseconds / 1000.00  <= 1);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(win, sprite, NULL);
        sfRenderWindow_display(win);
        sfClock_restart(clocking);
    }
    attack_move_right_to_left_destroy(sprite, win, clocking, refer);
}

void attack_move_up_to_down(sfSprite *sprite, sfRenderWindow *win, int dist)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2f refer = sfSprite_getPosition(sprite);
    sfClock *clocking = sfClock_create();

    for (pos.y+dist ; pos.y > refer.y-(dist+1) ; pos.y -= 1) {
        while (sfClock_getElapsedTime(clocking).microseconds / 1000.00  <= 1);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(win, sprite, NULL);
        sfRenderWindow_display(win);
        sfClock_restart(clocking);
    }
    for (pos.y ; pos.y < refer.y+dist+1 ; pos.y += 1) {
        while (sfClock_getElapsedTime(clocking).microseconds / 1000.00  <= 1);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(win, sprite, NULL);
        sfRenderWindow_display(win);
        sfClock_restart(clocking);
    }
    attack_move_up_to_down_destroy(sprite, win, clocking, refer);
}

void advanced_particle_daw_base(sfVector2f *position_array,
sfRenderWindow *win, int *velocity, sfRectangleShape *particle)
{
    for (int i = 0; i < 200 ; i++) {
        if (i >= 0 && i < 50) {
            advanced_particle_left_up(position_array, win, velocity, particle);
            sfRenderWindow_drawRectangleShape(win, particle, NULL);
        }
        if (i >= 50 && i < 100) {
            advanced_particle_righ_up(position_array, win, velocity, particle);
            sfRenderWindow_drawRectangleShape(win, particle, NULL);
        }
        if (i >= 100 && i < 150) {
            advanced_particle_left_dn(position_array, win, velocity, particle);
            sfRenderWindow_drawRectangleShape(win, particle, NULL);
        }
        if (i >= 150 && i < 200) {
            advanced_particle_righ_dn(position_array, win, velocity, particle);
            sfRenderWindow_drawRectangleShape(win, particle, NULL);
        }
    }
    sfRenderWindow_display(win);
}