/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** window.c
*/

#include "engine.h"

sfRenderWindow *get_window(sfVector2u *size, sfBool fullscreen, char *title,
    int framerate)
{
    sfVideoMode mode;
    sfRenderWindow *window = NULL;

    mode.width = size->x;
    mode.height = size->y;
    mode.bitsPerPixel = 32;
    if (fullscreen) {
        window = sfRenderWindow_create(mode, title,
        sfClose | sfFullscreen, NULL);
    } else {
        window = sfRenderWindow_create(mode, title,
        sfResize | sfClose, NULL);
    }
    if (framerate > 0 && window != NULL)
        sfRenderWindow_setFramerateLimit(window, framerate);
    *size = sfRenderWindow_getSize(window);
    return (window);
}