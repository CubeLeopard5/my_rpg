/*
** EPITECH PROJECT, 2020
** pokemon player rendering
** File description:
** rpg
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "stdio.h"
#include "function.h"

void set_pokemon_player(global_t *global)
{
    sfVector2f scale;
    sfVector2f pos;
    sfVector2f cur_center = sfView_getCenter(global->main_camera);

    for (int i = 0; i < 25; i++) {
        pos = get_pos_in_inventory(global, i);
        sfSprite_setPosition(global->object[i].spr, pos);
        global->button_ui[i].pos.x = pos.x;
        global->button_ui[i].pos.y = pos.y;
        sfRectangleShape_setPosition(global->button_ui[i].button, pos);
    }
    scale.x = 2;
    scale.y = 2;
    global->player.pokemon.pos.x = cur_center.x - 500;
    global->player.pokemon.pos.y = cur_center.y - 350;
    sfSprite_setPosition(global->player.pokemon.sprite,
    global->player.pokemon.pos);
    sfSprite_setScale(global->player.pokemon.sprite, scale);
    set_new_stat(global);
}