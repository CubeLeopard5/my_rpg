/*
** EPITECH PROJECT, 2020
** button in battles
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

void init_txt_button_battle(global_t *global)
{
    char *text[] = {"Attaque 1", "Attaque 2", "Attaque 3", "Attaque 4", NULL};
    sfFont *font = sfFont_createFromFile("resources/fonts/8bit.ttf");

    for (int i = 0; text[i] != NULL; i++) {
        global->button_battle[i].text = sfText_create();
        sfText_setFont(global->button_battle[i].text, font);
        sfText_setString(global->button_battle[i].text, text[i]);
        sfText_setColor(global->button_battle[i].text, sfWhite);
        sfText_setCharacterSize(global->button_battle[i].text, 25);
        global->button_battle[i].txt_pos.x = 500;
        global->button_battle[i].txt_pos.y = 120;
        sfText_setPosition(global->button_battle[i].text,
        global->button_battle[i].txt_pos);
    }
}

void init_button_battle(global_t *global)
{
    global->button_battle = malloc(sizeof(button_pause_t) * 100);
    for (int i = 0; i < 4; i++) {
        global->button_battle[i].button = sfRectangleShape_create();
        global->button_battle[i].size.x = 500;
        global->button_battle[i].size.y = 120;
        sfRectangleShape_setSize(global->button_battle[i].button,
        global->button_battle[i].size);
        sfTexture *texture = sfTexture_createFromFile
        ("assets/images/Red_Square.png", NULL);
        sfRectangleShape_setTexture(global->button_battle[i].button,
        texture, 0);
    }
    init_txt_button_battle(global);
}