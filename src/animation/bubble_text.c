/*
** EPITECH PROJECT, 2019
** bubble_text.c
** File description:
** text says whaaat
*/

#include "sflib_f.h"
#include "particles.h"

int my_strlen(char *str);

void bubble_text_2(sfText *texty, sfRenderWindow *win, const char *base_text,
char *textyno)
{
    bubble_text_3(base_text, textyno, -1);
    sfText_setString(texty, textyno);
    sfRenderWindow_drawText(win, texty, NULL);
    sfRenderWindow_display(win);
}

void bubble_txt_clock(sfText *texty, sfRenderWindow *win,
sfRectangleShape *hover, char *textyno)
{
    sfText_setString(texty, textyno);
    sfRenderWindow_drawRectangleShape(win, hover, NULL);
    sfRenderWindow_drawText(win, texty, NULL);
    sfRenderWindow_display(win);
}

void bubble_text(sfVector2f positions, sfText *texty, sfRenderWindow *win,
int speed)
{
    const char *base_text = sfText_getString(texty);
    char *texto = malloc(sizeof(char) * 9999);
    sfClock *clocking = sfClock_create();
    sfRectangleShape *hover = sfRectangleShape_create();

    bubble_text_sound(positions, texty, hover);
    for (int z = 0 ; base_text[z] != '\0' ; z++) {
        while (sfClock_getElapsedTime(clocking).microseconds /
        1000.00  <= speed)
            bubble_txt_clock(texty, win, hover, texto);
        bubble_text_2(texty, win, base_text, texto);
        sfClock_restart(clocking);
    }
    sfRectangleShape_destroy(hover);
    sfClock_destroy(clocking);
    free(texto);
}

void bubble_text_sound(sfVector2f positions, sfText *texty,
sfRectangleShape *hover)
{
    sfVector2f sizey = {1000, 140};

    sfRectangleShape_setFillColor(hover, sfWhite);
    sfRectangleShape_setSize(hover, sizey);
    sfText_setPosition(texty, positions);
    sfRectangleShape_setPosition(hover, positions);
}

void bubble_text_draw(sfVector2f positions, sfText *texty, sfRenderWindow *win,
int speed)
{
    sfText_setColor(texty, sfBlack);
    sfText_setCharacterSize(texty, 60);
    bubble_text_3(NULL, NULL, 1);
    bubble_text(positions, texty, win, speed);
}