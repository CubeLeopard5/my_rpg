/*
** EPITECH PROJECT, 2020
** background battle
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

void init_text_stat(global_t *global);

void init_background_battle(global_t *global)
{
    char *image[] = {"assets/images/battle_background.png",
    "assets/images/greenlife.png", "assets/images/greenlife.png", NULL};

    global->image = malloc(sizeof(image_t) * 3);
    for (int i = 0; image[i] != NULL; i++) {
        global->image[i].battle_spr = sfSprite_create();
        global->image[i].battle_tex =
        sfTexture_createFromFile(image[i], NULL);
        sfSprite_setTexture(global->image[i].battle_spr,
        global->image[i].battle_tex, sfTrue);
        global->image[i].pos.x = 0;
        global->image[i].pos.y = 0;
        sfSprite_setPosition(global->image[i].battle_spr,
        global->image[i].pos);
    }
    init_text_stat(global);
}