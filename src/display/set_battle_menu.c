/*
** EPITECH PROJECT, 2020
** set battle menu
** File description:
** rpg
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "stdio.h"
#include "function.h"

void set_battle_menu_poke(pokehuman_t *a, pokehuman_t *b,
global_t *global, sfVector2f cur_center)
{
    global->image[0].pos.x = cur_center.x - 965;
    global->image[0].pos.y = cur_center.y - 550;
    sfSprite_setPosition(global->image[0].battle_spr, global->image[0].pos);
    global->image[1].pos.x = cur_center.x + 100;
    global->image[1].pos.y = cur_center.y - 100;
    sfSprite_setPosition(global->image[1].battle_spr, global->image[1].pos);
    global->image[2].pos.x = cur_center.x - 465;
    global->image[2].pos.y = cur_center.y - 350;
    sfSprite_setPosition(global->image[2].battle_spr, global->image[2].pos);
    a->pos.x = cur_center.x + 175;
    a->pos.y = cur_center.y - 260;
    sfSprite_setPosition(a->sprite, a->pos);
    b->pos.x = cur_center.x + 125;
    b->pos.y = cur_center.y - 460;
    sfSprite_setPosition(b->sprite, b->pos);
}

void set_battle_menu_3(global_t *global, sfVector2f cur_center)
{
    for (int i = 2; i < 4; i++) {
        global->button_battle[i].pos.x = cur_center.x + 50;
        global->button_battle[i].pos.y = cur_center.y + 180 + (i - 2) * 170;
        sfRectangleShape_setPosition(global->button_battle[i].button,
        global->button_battle[i].pos);
        global->button_battle[i].txt_pos.x = cur_center.x + 70;
        global->button_battle[i].txt_pos.y =
        cur_center.y + 210 + (i - 2) * 170;
        sfText_setPosition(global->button_battle[i].text,
        global->button_battle[i].txt_pos);
    }
}

void set_battle_menu_2(global_t *global, sfVector2f cur_center)
{
    for (int i = 0; i < 2; i++) {
        global->button_battle[i].pos.x = cur_center.x - 550;
        global->button_battle[i].pos.y = cur_center.y + 180 + i * 170;
        sfRectangleShape_setPosition(global->button_battle[i].button,
        global->button_battle[i].pos);
        global->button_battle[i].txt_pos.x = cur_center.x - 530;
        global->button_battle[i].txt_pos.y = cur_center.y + 210 + i * 170;
        sfText_setPosition(global->button_battle[i].text,
        global->button_battle[i].txt_pos);
    }
}

void set_battle_menu(pokehuman_t *a, pokehuman_t *b, global_t *global)
{
    sfVector2f cur_center = sfView_getCenter(global->main_camera);
    sfVector2f scale;
    sfVector2f scale2;

    set_battle_menu_2(global, cur_center);
    set_battle_menu_3(global, cur_center);
    set_battle_menu_poke(a, b, global, cur_center);
    a->scale.x = -3.3;
    a->scale.y = 3.3;
    sfSprite_setScale(a->sprite, a->scale);
    b->scale.x = -1.5;
    b->scale.y = 1.5;
    sfSprite_setScale(b->sprite, b->scale);
    scale.x = (a->life * 100 / a->base_life) / 10 + 1;
    scale.y = 5;
    scale2.x = (b->life * 100 / b->base_life) / 10 + 1;
    scale2.y = 5;
    sfSprite_setScale(global->image[1].battle_spr, scale);
    sfSprite_setScale(global->image[2].battle_spr, scale2);
}