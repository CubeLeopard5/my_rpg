/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_entities.c
*/

#include "entity.h"
#include <stdlib.h>

unsigned long count_entities(entity_t **entities)
{
    unsigned long i = 0;

    for (; entities[i]; ++i);
    return i;
}

void init_game_entities(global_t *global)
{
    global->entities = malloc(sizeof(entity_t *));
    global->entities[0] = NULL;
}

void add_entity(global_t *global, char *texure_path,
    entity_action_t on_interact, sfVector2i position)
{
    unsigned long count = count_entities(global->entities);
    entity_t **arr = malloc(sizeof(entity_t *) * (count + 2));

    for (unsigned long i = 0; global->entities[i]; ++i)
        arr[i] = global->entities[i];
    arr[count] = create_entity(texure_path, on_interact, position);
    arr[count + 1] = NULL;
    free(global->entities);
    global->entities = arr;
}

void destroy_game_entities(global_t *global)
{
    for (unsigned int i = 0; global->entities[i]; ++i)
        destroy_entity(global->entities[i]);
    free(global->entities);
}