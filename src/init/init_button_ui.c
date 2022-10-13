/*
** EPITECH PROJECT, 2020
** init button of the UI
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

void init_button_ui(global_t *global)
{
    global->button_ui = malloc(sizeof(button_ui_t) * 25);
    for (int i = 0; i < 25; i++) {
        global->button_ui[i].button = sfRectangleShape_create();
        global->button_ui[i].pos.x = 75 + i * 200;
        global->button_ui[i].pos.y = 40;
        sfRectangleShape_setPosition(global->button_ui[i].button,
        global->button_ui[i].pos);
        global->button_ui[i].size.x = 75;
        global->button_ui[i].size.y = 75;
        sfRectangleShape_setSize(global->button_ui[i].button,
        global->button_ui[i].size);
        sfTexture *texture = sfTexture_createFromFile
        ("assets/images/Red_Square.png", NULL);
        sfRectangleShape_setTexture(global->button_ui[i].button, texture, 0);
    }
}