/*
** EPITECH PROJECT, 2020
** display ui
** File description:
** rpg
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "stdio.h"
#include "function.h"

char *my_nbr_to_str(int i);

void which_ui_button(global_t *global, int i)
{
    if (global->object[i].id == 1) {
        poke_level_up(&global->player.pokemon);
        remove_object_inv(global, "level up");
    }
}

void manage_inv_input(global_t *global, int x, int y, sfKeyCode input)
{
    sfVector2f rec = sfView_getCenter(global->main_camera);

    y = y + rec.y - 535;
    x = x + rec.x - 955;
    for (int i = 0; i < 25; i++) {
        if (x <= global->button_ui[i].pos.x +
            global->button_ui[i].size.x && x >= global->button_ui[i].pos.x
            && y <= global->button_ui[i].pos.y +
            global->button_ui[i].size.y && y >=
            global->button_ui[i].pos.y)
                which_ui_button(global, i);
    }
}

void event_inventory(global_t *global)
{
    sfVector2i pos;

    while (sfRenderWindow_pollEvent(global->window.window,
    &global->window.event)) {
        if (global->window.event.type == sfEvtClosed)
            sfRenderWindow_close(global->window.window);
        if (global->window.event.type == sfEvtKeyPressed) {
            if (global->window.event.key.code == sfKeyX)
                manage_display_inv(global);
            if (global->window.event.key.code == sfKeyI)
                add_object_inv(global, "level up", 1, "assets/images/tc.png");
            if (global->window.event.key.code == sfKeyP)
                poke_level_up(&global->player.pokemon);
        }
        if (global->window.event.type == sfEvtMouseButtonPressed) {
            pos = sfMouse_getPositionRenderWindow(global->window.window);
            manage_inv_input(global, pos.x, pos.y,
            global->window.event.key.code);
        }
    }
}

void set_pos_inv_menu(global_t *global)
{
    sfVector2f cur_center = sfView_getCenter(global->main_camera);

    global->sprite_sheet.pos_inv[0].x = cur_center.x - 750;
    global->sprite_sheet.pos_inv[0].y = cur_center.y - 450;
    sfSprite_setPosition(global->sprite_sheet.sprite_inv[0],
    global->sprite_sheet.pos_inv[0]);
    global->sprite_sheet.pos_inv[1].x = cur_center.x - 500;
    global->sprite_sheet.pos_inv[1].y = cur_center.y - 430;
    sfSprite_setPosition(global->sprite_sheet.sprite_inv[1],
    global->sprite_sheet.pos_inv[1]);
    global->sprite_sheet.pos_inv[2].x = cur_center.x - 1500;
    global->sprite_sheet.pos_inv[2].y = cur_center.y - 550;
    sfSprite_setPosition(global->sprite_sheet.sprite_inv[2],
    global->sprite_sheet.pos_inv[2]);
    set_pokemon_player(global);
}

void display_ui(global_t *global)
{
    set_pos_inv_menu(global);
    move_rect(global, 0, global->player.pokemon.sprite);
    for (int i = 0; i < 2; i++)
        sfRenderWindow_drawSprite(global->window.window,
        global->sprite_sheet.sprite_inv[i], NULL);
    for (int i = 0; i < 25; i++)
        sfRenderWindow_drawSprite(global->window.window,
        global->object[i].spr, NULL);
    for (int i = 0; i < 7; i++)
        sfRenderWindow_drawText(global->window.window,
        global->text_stat[i].text, NULL);
    sfRenderWindow_drawSprite(global->window.window,
    global->player.pokemon.sprite, NULL);
    sfRenderWindow_display(global->window.window);
    event_inventory(global);
}