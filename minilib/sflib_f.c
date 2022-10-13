/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main of main
*/

#include "sflib_f.h"

int is_inside_here(sfSprite *sprite, sfRenderWindow *win)
{
    sfVector2f spriteshe = sfSprite_getPosition(sprite);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    sfVector2f mouse_pos;
    sfFloatRect sizey = sfSprite_getGlobalBounds(sprite);
    int px = spriteshe.x;
    int py = spriteshe.y;
    int sx = sizey.width;
    int sy = sizey.height;
    int mx = 0;
    int my = 0;

    mouse_pos.x = mouse.x;
    mouse_pos.y = mouse.y;
    mx = mouse_pos.x;
    my = mouse_pos.y;
    if (px+sx >= mx && py+sy >= my && px <= mx && py <= my)
        return (1);
    else
        return (0);
}

void button_draw_classic(sfSprite *sprite, sfRenderWindow *win, 
sfColor colour, sfRectangleShape *hover_b)
{
    sfVector2f spriteshe = sfSprite_getPosition(sprite);
    sfFloatRect sizey = sfSprite_getGlobalBounds(sprite);
    sfVector2f hover_pos;
    sfVector2f hover_size;

    hover_size.x = sizey.width+20;
    hover_size.y = sizey.height+20;
    hover_pos.x = spriteshe.x-10;
    hover_pos.y = spriteshe.y-10;
    if (is_inside_here(sprite, win) == 1) {
        sfRectangleShape_setSize(hover_b, hover_size);
        sfRectangleShape_setPosition(hover_b, hover_pos);
        sfRectangleShape_setFillColor(hover_b, colour);
        sfRenderWindow_drawRectangleShape(win, hover_b, NULL);
    }
    sfRenderWindow_drawSprite(win, sprite, NULL);
}

float scalinator(sfSprite *sprite, int type, sfRenderWindow *win)
{
    sfVector2f spriteshe = sfSprite_getPosition(sprite);
    sfFloatRect size = sfSprite_getGlobalBounds(sprite);
    sfVector2u win_size = sfRenderWindow_getSize(win);
    float sizey = 1.00;

    if (type == 1) {
        for (; (spriteshe.x+size.width >
        win_size.x && spriteshe.y+size.height >
        win_size.y) || sizey < 0.1; sizey -= 0.01) {
            sfSprite_setScale(sprite, (sfVector2f) {.x = sizey, .y = sizey});
            size = sfSprite_getGlobalBounds(sprite);
        }
    }
    scalinator_2(sprite, type, win);
    return (sizey);
}

void scalinator_2(sfSprite *sprite, int type, sfRenderWindow *win)
{
    float sizey = 1.00;
    sfVector2f spriteshe = sfSprite_getPosition(sprite);
    sfFloatRect size = sfSprite_getGlobalBounds(sprite);
    sfVector2u win_size = sfRenderWindow_getSize(win);

    if (type == 0) {
        for (; (spriteshe.x+size.width > win_size.x ||
        spriteshe.y+size.height > win_size.y) ||
        sizey < 0.1; sizey -= 0.01) {
            sfSprite_setScale(sprite, (sfVector2f) {.x = sizey, .y = sizey});
            size = sfSprite_getGlobalBounds(sprite);
        }
    }
    scalinator_3(sprite, type, win);
}

void scalinator_3(sfSprite *sprite, int type, sfRenderWindow *win)
{
    float sizey = 1.00;
    float sizey2 = 1.00;
    sfVector2f spriteshe = sfSprite_getPosition(sprite);
    sfFloatRect size = sfSprite_getGlobalBounds(sprite);
    sfVector2u win_size = sfRenderWindow_getSize(win);

    if (type == 2) {
        for (; (spriteshe.x+size.width > win_size.x &&
        spriteshe.y+size.height > win_size.y) ||
        sizey < 0.1; sizey -= 0.01) {
            sfSprite_setScale(sprite, (sfVector2f) {.x = sizey, .y = 1.0});
            size = sfSprite_getGlobalBounds(sprite);
        }
        for (; (spriteshe.y+size.height > win_size.y) ||
        sizey2 < 0.1; sizey2 -= 0.01) {
            sfSprite_setScale(sprite, (sfVector2f) {.x = sizey, .y = sizey2});
            size = sfSprite_getGlobalBounds(sprite);
        }
    }
}