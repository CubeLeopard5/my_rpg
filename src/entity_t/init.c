/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init.c
*/

#include "struct_entity.h"
#include <stdlib.h>
#include <stddef.h>

// create an entity
entity_t *create_entity(char *texture_path, entity_action_t on_interact,
sfVector2i position)
{
    entity_t *entity = malloc(sizeof(entity_t));

    if (!entity)
        return NULL;
    entity->texture = sfTexture_createFromFile(texture_path, NULL);
    entity->sprite = sfSprite_create();
    sfSprite_setTexture(entity->sprite, entity->texture, sfFalse);
    entity->position = position;
    entity->on_interact = on_interact;
    return entity;
}

// free entity
void destroy_entity(entity_t *entity)
{
    sfTexture_destroy(entity->texture);
    sfSprite_destroy(entity->sprite);
    free(entity);
}