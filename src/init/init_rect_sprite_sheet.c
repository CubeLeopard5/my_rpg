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

void move_rect(global_t *global, int face, sfSprite *sprite)
{
    if (face == 0) {
        global->sprite_sheet.rect.left = 0;
        sfSprite_setTextureRect(sprite, global->sprite_sheet.rect);
    }
    else if (face == 1) {
        global->sprite_sheet.rect.left = 128;
        sfSprite_setTextureRect(sprite, global->sprite_sheet.rect);
    }
    else {
        global->sprite_sheet.rect.left = 256;
        sfSprite_setTextureRect(sprite, global->sprite_sheet.rect);
    }
}

void init_my_rect(global_t *global)
{
    global->sprite_sheet.rect.top = 0;
    global->sprite_sheet.rect.left = 0;
    global->sprite_sheet.rect.width = 128;
    global->sprite_sheet.rect.height = 128;
    for (int i = 0; i < global->sprite_sheet.sp_sheet_count; i++) {
        sfSprite_setTextureRect(global->sprite_sheet.sprite[i],
        global->sprite_sheet.rect);
    }
}