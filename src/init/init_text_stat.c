/*
** EPITECH PROJECT, 2020
** stat pokemon
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

void init_text_stat(global_t *global)
{
    char *text[] = {"level : ", "type : ", "life : ", "atk : ", "def : ",
    "atk spe : ", "def spe : ", NULL};

    global->text_stat = malloc(sizeof(text_stat_t) * 8);
    for (int i = 0; text[i] != NULL; i++) {
        global->text_stat[i].text = sfText_create();
        sfText_setString(global->text_stat[i].text, text[i]);
        global->text_stat[i].font =
        sfFont_createFromFile("resources/fonts/8bit.ttf");
        sfText_setFont(global->text_stat[i].text, global->text_stat[i].font);
        sfText_setColor(global->text_stat[i].text, sfWhite);
        sfText_setCharacterSize(global->text_stat[i].text, 40);
    }
}