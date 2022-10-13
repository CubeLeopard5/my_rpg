/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_entities.c
*/

#include "entity.h"
#include "minilib.h"

void display_entities(global_t *global)
{
    sfRenderWindow *window = global->window.window;
    entity_t *entity = NULL;
    sfVector2f pos;

    for (unsigned long i = 0; global->entities[i]; ++i) {
        entity = global->entities[i];
        pos.x = entity->position.x * 64;
        pos.y = entity->position.y * 64;
        sfSprite_setPosition(entity->sprite, pos);
        sfRenderWindow_drawSprite(window, entity->sprite, NULL);
    }
}