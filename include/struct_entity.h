/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** struct_entity.h
*/

#ifndef __STRUCT_ENTITY_H__
#define __STRUCT_ENTITY_H__

typedef struct global_t global_t;
typedef struct entity_s entity_t;
typedef void (*entity_action_t) (entity_t *, global_t *);

#include "struct.h"

struct entity_s {
    entity_action_t on_interact;
    sfVector2i position;
    sfTexture *texture;
    sfSprite *sprite;
    int action_type;
    int move_dir;
    char *talk_file;
    char *poke_file;
};

#endif