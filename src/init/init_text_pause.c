/*
** EPITECH PROJECT, 2020
** text pause
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

void init_text_pause(global_t *global)
{
    char *text[] = {"Resume", "Return Menu", "Exit", NULL};

    global->text_pause = malloc(sizeof(text_pause_t) * 3);
    for (int i = 0; i < 3; i++) {
        global->text_pause[i].text = sfText_create();
        sfText_setString(global->text_pause[i].text, text[i]);
        global->text_pause[i].font =
        sfFont_createFromFile("resources/fonts/8bit.ttf");
        sfText_setFont(global->text_pause[i].text, global->text_pause[i].font);
        sfText_setColor(global->text_pause[i].text, sfWhite);
        sfText_setCharacterSize(global->text_pause[i].text, 40);
    }
}