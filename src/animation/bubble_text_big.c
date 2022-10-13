/*
** EPITECH PROJECT, 2019
** bubble_text_big.c
** File description:
** text says whaaat but biger
*/

#include "sflib_f.h"

int my_strlen(char *str);

void bubble_txt_2_b(sfText *texty, sfRenderWindow *win, const char *base_text,
char *textyno)
{
    bubble_text_3_big(base_text, textyno, -1);
    sfText_setString(texty, textyno);
    sfRenderWindow_drawText(win, texty, NULL);
}

void bubble_txt_clock_big(sfText *texty, sfRenderWindow *win,
sfRectangleShape *hover, char *textyno)
{
    sfText_setString(texty, textyno);
    sfRenderWindow_drawRectangleShape(win, hover, NULL);
    sfRenderWindow_drawText(win, texty, NULL);
    sfRenderWindow_display(win);
}

void bubble_text_big(sfVector2f positions, sfText *texty, sfRenderWindow *win,
int speed)
{
    const char *base_text = sfText_getString(texty);
    char *texto = malloc(sizeof(char) * 9999);
    sfClock *clocking = sfClock_create();
    sfVector2f sizey = {1920, 368};
    sfRectangleShape *hover = sfRectangleShape_create();

    sfRectangleShape_setFillColor(hover, sfWhite);
    sfRectangleShape_setSize(hover, sizey);
    sfText_setPosition(texty, positions);
    sfRectangleShape_setPosition(hover, positions);
    for (int z = 0 ; base_text[z] != '\0' ; z++) {
        while (sfClock_getElapsedTime(clocking).microseconds /
        1000.00  <= speed)
            bubble_txt_clock_big(texty, win, hover, texto);
        bubble_txt_2_b(texty, win, base_text, texto);
        sfClock_restart(clocking);
    }
    sfRectangleShape_destroy(hover);
    sfClock_destroy(clocking);
    free(texto);
}

void bubble_text_draw_big(sfVector2f positions, sfText *texty,
sfRenderWindow *win, int speed)
{
    sfText_setColor(texty, sfBlack);
    sfText_setCharacterSize(texty, 140);
    bubble_text_3_big(NULL, NULL, 1);
    bubble_text_big(positions, texty, win, speed);
}