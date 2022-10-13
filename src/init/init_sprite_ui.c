/*
** EPITECH PROJECT, 2020
** init sprite ui
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

void init_scale_inventory(global_t *global, int i)
{
    if (i == 0) {
        global->sprite_sheet.scale_inv[i].x = 0.8;
        global->sprite_sheet.scale_inv[i].y = 0.8;
    }
    if (i == 1) {
        global->sprite_sheet.scale_inv[i].x = 0.9;
        global->sprite_sheet.scale_inv[i].y = 0.9;
    }
    if (i == 2) {
        global->sprite_sheet.scale_inv[i].x = 1.5;
        global->sprite_sheet.scale_inv[i].y = 1.5;
    }
    sfSprite_setScale(global->sprite_sheet.sprite_inv[i],
    global->sprite_sheet.scale_inv[i]);
}

void init_inventory(global_t *global)
{
    char *image[] = {"assets/images/Grey_Square.png",
    "assets/images/quadrillage.png",
    "assets/images/quadrillage_poke.png", NULL};

    for (int i = 0; image[i] != NULL; i++) {
        global->sprite_sheet.texture_inv[i]
        = sfTexture_createFromFile(image[i], NULL);
        global->sprite_sheet.sprite_inv[i] = sfSprite_create();
        sfSprite_setTexture(global->sprite_sheet.sprite_inv[i],
        global->sprite_sheet.texture_inv[i], sfTrue);
        init_scale_inventory(global, i);
    }
}

void init_sprite_ui_2(global_t *global)
{
    for (int i = 0; i < 25; i++) {
        global->object[i].name = NULL;
        global->object[i].id = 0;
        global->object[i].spr = sfSprite_create();
        global->object[i].pos.x = 0;
        global->object[i].pos.y = 0;
    }
}

void init_sprite_ui(global_t *global)
{
    global->object = malloc(sizeof(object_t) * 25);
    global->sprite_sheet.sprite_inv = malloc(sizeof(sfSprite *) * 3);
    global->sprite_sheet.texture_inv = malloc(sizeof(sfTexture *) * 3);
    global->sprite_sheet.pos_inv = malloc(sizeof(sfVector2f) * 3);
    global->sprite_sheet.scale_inv = malloc(sizeof(sfVector2f) * 3);
    init_sprite_ui_2(global);
    init_inventory(global);
}