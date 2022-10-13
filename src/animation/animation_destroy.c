/*
** EPITECH PROJECT, 2019
** animation_destroy.c
** File description:
** destroy animation
*/

#include "sflib_f.h"
#include <library.h>
#include "char_create.h"
#include <particles.h>

void attack_move_left_to_right_destroy(sfSprite *sprite, sfRenderWindow *win,
sfClock *clocking, sfVector2f refer)
{
    sfClock_destroy(clocking);
    sfSprite_setPosition(sprite, refer);
    sfRenderWindow_drawSprite(win, sprite, NULL);
}

void attack_move_right_to_left_destroy(sfSprite *sprite, sfRenderWindow *win,
sfClock *clocking, sfVector2f refer)
{
    sfClock_destroy(clocking);
    sfSprite_setPosition(sprite, refer);
    sfRenderWindow_drawSprite(win, sprite, NULL);
}

void attack_move_down_to_up_destroy(sfSprite *sprite, sfRenderWindow *win,
sfClock *clocking, sfVector2f refer)
{
    sfClock_destroy(clocking);
    sfSprite_setPosition(sprite, refer);
    sfRenderWindow_drawSprite(win, sprite, NULL);
}

void attack_move_up_to_down_destroy(sfSprite *sprite, sfRenderWindow *win,
sfClock *clocking, sfVector2f refer)
{
    sfClock_destroy(clocking);
    sfSprite_setPosition(sprite, refer);
    sfRenderWindow_drawSprite(win, sprite, NULL);
}