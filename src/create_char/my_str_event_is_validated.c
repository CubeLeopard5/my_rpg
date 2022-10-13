/*
** EPITECH PROJECT, 2020
** writting valid
** File description:
** rpg
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "function.h"
#include "stdio.h"
#include "sflib_f.h"
#include "char_create.h"
#include <library.h>

void events(sfEvent event, sfRenderWindow *window, char_create_t *char_create)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed &&
    is_inside_here(char_create->button_start, window) == 1)
        char_create->a = 1;
    if (event.type == sfEvtMouseButtonPressed &&
    is_inside_here(char_create->button_return, window) == 1)
        char_create->a = -1;
    text_tweaks(window, event, char_create);
}

int my_str_event_is_validated(sfEvent event)
{
    if (event.text.unicode >= '0' && event.text.unicode <= '9')
        return (1);
    if (event.text.unicode >= 'a' && event.text.unicode <= 'z')
        return (1);
    if (event.text.unicode >= 'A' && event.text.unicode <= 'Z')
        return (1);
    return (0);
}