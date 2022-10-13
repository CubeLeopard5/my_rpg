/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** entity_events.c
*/

#include "entity.h"

entity_t *get_entity_at_pos(global_t *global, sfVector2i position)
{
    sfVector2i epos;

    for (unsigned long i = 0; global->entities[i]; ++i) {
        epos = global->entities[i]->position;
        if (epos.x == position.x && epos.y == position.y)
            return global->entities[i];
    }
    return NULL;
}
// 3 haut, 0 bas, 1 gauche, 2 droite
entity_t *player_facing_entity(global_t *global)
{
    sfVector2i pos;
    sfVector2i dpos;

    pos.x = global->player.pos.x / 64;
    pos.y = global->player.pos.y / 64;
    switch (global->player.animation) {
        case 0: pos.y += 1;
            return get_entity_at_pos(global, pos);
        case 1: pos.x -= 1;
            return get_entity_at_pos(global, pos);
        case 2: pos.x += 1;
            return get_entity_at_pos(global, pos);
        case 3: pos.y -= 1;
            return get_entity_at_pos(global, pos);
        default: return NULL;
    }
}

void handle_entity_interaction(global_t *global)
{
    entity_t *target = player_facing_entity(global);
    entity_action_t on_interact = target ? target->on_interact : NULL;

    if (on_interact)
        (*on_interact)(target, global);
}