/*
** EPITECH PROJECT, 2020
** init sprite sheet
** File description:
** rpg
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "init.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"
#include <stdlib.h>

void init_sprite_sheet_2(global_t *global, char *image[])
{
    for (int i = 0; image[i] != NULL; i++)
        global->sprite_sheet.texture[i] =
        sfTexture_createFromFile(image[i], NULL);
    for (int i = 0; i < global->sprite_sheet.sp_sheet_count; i++) {
        global->sprite_sheet.sprite[i] = sfSprite_create();
        sfSprite_setTexture(global->sprite_sheet.sprite[i],
        global->sprite_sheet.texture[i], sfTrue);
    }
    global->sprite_sheet.pos = malloc(sizeof(sfVector2f) *
    global->sprite_sheet.sp_sheet_count);
    for (int i = 0; i < global->sprite_sheet.sp_sheet_count; i++) {
        global->sprite_sheet.pos[i].x = 0;
        global->sprite_sheet.pos[i].y = 100 * i;
        sfSprite_setPosition(global->sprite_sheet.sprite[i],
        global->sprite_sheet.pos[i]);
    }
}

void init_sprite_sheet(global_t *global)
{
    char *image[] = {"assets/sprite_sheet/eddy_malou.png",
    "assets/sprite_sheet/Enrich_roucool.png", "assets/sprite_sheet/harold.png",
    "assets/sprite_sheet/melenchon.png", "assets/sprite_sheet/metal.png",
    "assets/sprite_sheet/portugesh.png", "assets/sprite_sheet/putin.png",
    "assets/sprite_sheet/Snoop_dog.png", "assets/sprite_sheet/the_rock.png",
    NULL};

    global->sprite_sheet.sp_sheet_count = 9;
    global->sprite_sheet.tx_sheet_count = 9;
    global->sprite_sheet.sprite = malloc(sizeof(sfSprite *) *
    global->sprite_sheet.sp_sheet_count);
    global->sprite_sheet.texture = malloc(sizeof(sfTexture *) *
    global->sprite_sheet.tx_sheet_count);
    init_sprite_sheet_2(global, image);
    global->sprite_sheet.display_inv = 0;
    global->sprite_sheet.display_pause = 0;
}