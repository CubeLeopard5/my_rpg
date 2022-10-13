/*
** EPITECH PROJECT, 2020
** init player
** File description:
** init the player
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "init.h"
#include "battle.h"

sfSprite *set_player_origin(sfSprite *sprite)
{
    sfVector2f center;

    center.x = 64;
    center.y = 64;
    sfSprite_setOrigin(sprite, center);
    return (sprite);
}

void init_player(player_t *player, global_t *global)
{
    player->pos.x = 8 * 64 + 32;
    player->pos.y = 17 * 64;
    player->sprite = init_this_sprite("assets/images/pika_player.png",
    global);
    player->balise_mv = 0;
    player->delay_mv = 1 / 60;
    player->speed = 10;
    player->sprite = set_player_origin(player->sprite);
    player->animation = 0;
    player->atk_choice = -1;
    player->pokemon =
    init_pokehuman(global, "assets/sprite_sheet/melenchon.png", 5);
}
//sfVector2f origin =  sfSprite_getOrigin(player->sprite);