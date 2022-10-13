/*
** EPITECH PROJECT, 2019
** rain_snow.c
** File description:
** let it rain & let it snow
*/

#include "sflib_f.h"
#include <library.h>
#include "char_create.h"
#include <particles.h>

void let_it_go_circle_tweaks(int wichone, global_t *global, sfVector2f *p_a,
sfCircleShape *circle)
{
    if (wichone == -1) {
        sfCircleShape_setRadius(circle, 3.00);
        sfCircleShape_setFillColor(circle, sfWhite);
    }
    else {
        sfCircleShape_setPosition(circle, p_a[wichone]);
        sfRenderWindow_drawCircleShape(global->window.window, circle, NULL);
    }
}

void let_it_go_snow(global_t *global, int speed,
int *velocity, sfVector2f *p_a)
{
    sfCircleShape *circle = sfCircleShape_create();

    let_it_go_circle_tweaks(-1, global, p_a, circle);
    for (int i = 0; i < 200 ; i++) {
        if (velocity[i] < 3)
            velocity[i] = (rand() % 10)+speed;
        p_a[i].y += velocity[i];
        if ((rand() % 10) == 5)
            p_a[i].x += 2;
        if ((rand() % 10) == 5)
            p_a[i].x -= 2;
        if (p_a[i].x > global->place->size.x*64 || p_a[i].x < 0 || p_a[i].y >
        global->place->size.y*64) {
            velocity[i] = rand() % 5;
            p_a[i] = (sfVector2f) {.x = rand() %
            global->place->size.x*64, .y = 0};
        }
        let_it_go_circle_tweaks(i, global, p_a, circle);
    }
    sfCircleShape_destroy(circle);
}

void make_it_rain_or_snow(global_t *global, int issnow, int speed,
int is_init_or_reset)
{
    static int *velocity;
    static sfVector2f *p_a;

    if (is_init_or_reset == 1) {
        velocity = malloc(sizeof(int *) * 201);
        p_a = malloc(sizeof(sfVector2f*) * 201);
        for (int i = 0; i < 201 ; i++) {
            velocity[i] = (rand() % 10)+speed;
            p_a[i] = (sfVector2f) {.x = rand() % 1920, .y = rand() % 750};
        }
        return;
    }
    if (is_init_or_reset == 2) {
        let_it_go_free(p_a, velocity);
        return;
    }
    if (issnow == 1)
        let_it_go_snow(global, speed, velocity, p_a);
    else
        let_it_go_rain(global, speed, velocity, p_a);
}

void let_it_go_rain(global_t *global, int speed,
int *velocity, sfVector2f *position_array)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f size = {3, 7};

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, sfBlue);
    for (int i = 0; i < 200 ; i++) {
        if (velocity[i] < 3)
            velocity[i] = (rand() % 3)+speed;
        position_array[i].y += velocity[i];
        if (position_array[i].x > global->place->size.x*64 ||
        position_array[i].x < 0 ||
        position_array[i].y > global->place->size.y*64) {
            velocity[i] = rand() % 3;
            position_array[i] = (sfVector2f) {.x = rand() %
            global->place->size.x*64, .y = 0};
        }
        sfRectangleShape_setPosition(rect, position_array[i]);
        sfRenderWindow_drawRectangleShape(global->window.window, rect, NULL);
    }
    sfRectangleShape_destroy(rect);
}

void meteo_display(global_t *global)
{
    sfClock *clocking = sfClock_create();

    while (sfClock_getElapsedTime(clocking).microseconds / 1000.00 <= 10) {
        if (global->meteo_rand > 3)
            break;
        if (global->meteo_rand <= 2)
            make_it_rain_or_snow(global, 0, 15, 0);
        else
            make_it_rain_or_snow(global, 1, 5, 0);
        sfRenderWindow_display(global->window.window);
    }
    sfClock_restart(clocking);
    sfClock_destroy(clocking);
}