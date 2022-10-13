/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_npc
*/

#include "map.h"
#include "stddef.h"
#include "struct.h"
#include "minilib.h"
#include "entity.h"
#include "stdlib.h"

void free_npc(global_t *global)
{
    for (int i = 0; global->entities[i] != NULL; i++) {
        destroy_entity(global->entities[i]);
        global->entities[i] = NULL;
    }
}

void load_npc_actions_files(global_t *global, FILE *file, int i)
{
    char *buffer = get_next_line(file);

    if (global->entities[i]->action_type == 1 ||
    global->entities[i]->action_type == 3) {
        global->entities[i]->talk_file =
        malloc(sizeof(char) * (my_strlen(buffer) + 1));
        global->entities[i]->talk_file[my_strlen(buffer)] = '\0';
        global->entities[i]->talk_file =
        my_strcpy(global->entities[i]->talk_file, buffer);
    }
    free(buffer);
    buffer = get_next_line(file);
    if (global->entities[i]->action_type == 2 ||
    global->entities[i]->action_type == 3) {
        global->entities[i]->poke_file =
        malloc(sizeof(char) * (my_strlen(buffer) + 1));
        global->entities[i]->poke_file[my_strlen(buffer)] = '\0';
        global->entities[i]->poke_file =
        my_strcpy(global->entities[i]->poke_file, buffer);
    }
}

void load_this_npc(global_t *global, FILE *file)
{
    char *buffer = get_next_line(file);
    char *sprite_path;
    sfVector2i pos;
    int i = 0;

    sprite_path = malloc_strcat(malloc_strcat("assets/NPC/", buffer), ".png");
    pos.x = my_atoi(get_next_line(file));
    pos.y = my_atoi(get_next_line(file));
    add_entity(global, sprite_path, &entity_act, pos);
    for (; global->entities[i] != NULL; i++);
    i -= 1;
    global->entities[i]->action_type = my_atoi(get_next_line(file));
    global->entities[i]->move_dir = my_atoi(get_next_line(file));
    load_npc_actions_files(global, file, i);
}

void load_npc(char *name, global_t *global)
{
    char *path = malloc_strcat(malloc_strcat("assets/map/", name), "_npc");
    FILE *file = fopen(path, "r");
    char *buffer = get_next_line(file);

    free(get_next_line(file));
    for (int i = 0; i < my_atoi(buffer); i++) {
        load_this_npc(global, file);
        free(get_next_line(file));
    }
    free(buffer);
}