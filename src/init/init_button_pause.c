/*
** EPITECH PROJECT, 2020
** button pause
** File description:
** rpg
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "function.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"
#include <stdlib.h>

void init_button_pause(global_t *global)
{
    global->button_pause = malloc(sizeof(button_pause_t) * 3);
    for (int i = 0; i < 3; i++) {
        global->button_pause[i].button = sfRectangleShape_create();
        global->button_pause[i].pos.x = 575;
        global->button_pause[i].pos.y = 400 + i * 300;
        sfRectangleShape_setPosition(global->button_pause[i].button,
        global->button_pause[i].pos);
        global->button_pause[i].size.x = 750;
        global->button_pause[i].size.y = 100;
        sfRectangleShape_setSize(global->button_pause[i].button,
        global->button_pause[i].size);
        sfTexture *texture = sfTexture_createFromFile
        ("assets/images/Red_Square.png", NULL);
        sfRectangleShape_setTexture(global->button_pause[i].button,
        texture, 0);
    }
}