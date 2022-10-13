/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** entity.h
*/

#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "struct_entity.h"
#include "struct.h"
#include <stdarg.h>

entity_t *create_entity(char *texture_path, entity_action_t on_interact,
    sfVector2i position);
void destroy_entity(entity_t *entity);

void init_game_entities(global_t *global);
void add_entity(global_t *global, char *texure_path,
    entity_action_t on_interact, sfVector2i position);
void destroy_game_entities(global_t *global);

entity_t *get_entity_at_pos(global_t *global, sfVector2i position);
entity_t *player_facing_entity(global_t *global);
void handle_entity_interaction(global_t *global);
void entity_act(entity_t *entity, global_t *global);
#endif