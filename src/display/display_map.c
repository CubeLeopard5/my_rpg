/*
** EPITECH PROJECT, 2020
** display map
** File description:
** display the map
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "stdio.h"
#include "function.h"

void display_map(global_t *global)
{
    sfVector2f pos;

    for (int i = 0; i != global->place->size.y; i++) {
        for (int j = 0; j != global->place->size.x; j++) {
            pos.y = (float)i * 64;
            pos.x = (float)j * 64;
            sfSprite_setPosition(global->place->tiles[i][j].sprite, pos);
            sfRenderWindow_drawSprite(global->window.window,
            global->place->tiles[i][j].sprite, NULL);
        }
    }
}