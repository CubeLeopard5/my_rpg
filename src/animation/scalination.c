/*
** EPITECH PROJECT, 2019
** scalinator.c
** File description:
** scalination
*/

#include "sflib_f.h"
#include <library.h>
#include "char_create.h"
#include <particles.h>

int anime_scale_grow(sfSprite *sprite, sfRenderWindow *win, int toscale,
int speed)
{
    sfVector2f base_scale = sfSprite_getScale(sprite);
    sfClock *clocking = sfClock_create();

    if (base_scale.x > toscale || base_scale.y > toscale)
        return (84);
    for (base_scale ; base_scale.x > toscale || base_scale.y < toscale;
    base_scale.x -= 0.05, base_scale.y += 0.05) {
        while (sfClock_getElapsedTime(clocking).microseconds / 1000.00
        <= speed) {
            sfRenderWindow_drawSprite(win, sprite, NULL);
            sfRenderWindow_display(win);
        }
        sfSprite_setScale(sprite, base_scale);
        sfClock_restart(clocking);
    }
    sfClock_destroy(clocking);
    return (0);
}

int anime_scale_resize(sfSprite *sprite, sfRenderWindow *win, int toscale,
int speed)
{
    sfVector2f base_scale = sfSprite_getScale(sprite);
    sfClock *clocking = sfClock_create();

    if (base_scale.x < toscale || base_scale.y < toscale)
        return (84);
    for (base_scale ; base_scale.x > toscale || base_scale.y > toscale ||
    base_scale.x > 0.06 || base_scale.y > 0.06; base_scale.x -= 0.05,
    base_scale.y -= 0.05) {
        while (sfClock_getElapsedTime(clocking).microseconds / 1000.00 <=
        speed) {
            sfRenderWindow_drawSprite(win, sprite, NULL);
            sfRenderWindow_display(win);
        }
        sfSprite_setScale(sprite, base_scale);
        sfClock_restart(clocking);
    }
    sfClock_destroy(clocking);
    return (0);
}