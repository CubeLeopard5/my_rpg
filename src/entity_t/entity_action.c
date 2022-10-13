/*
** EPITECH PROJECT, 2020
** entity action
** File description:
** entity_action
*/

#include "map.h"
#include "stddef.h"
#include "struct.h"
#include "minilib.h"
#include "entity.h"
#include "stdlib.h"
#include "particles.h"
#include "init.h"
#include "function.h"
#include "battle.h"

void move_npc(entity_t *entity)
{
    switch (entity->move_dir)
    {
    case 1:
        entity->position.y -= 1;
        break;
    case 2:
        entity->position.x += 1;
        break;
    case 3:
        entity->position.y += 1;
        break;
    case 4:
        entity->position.x -= 1;
        break;
    default:
        break;
    }
}

void entity_attack(entity_t *entity, global_t *global)
{
    FILE *file = fopen(entity->poke_file, "r");
    char *name = get_next_line(file);
    char *str = get_next_line(file);
    int level = my_atoi(str);

    global->enemy = init_pokehuman(global,
    malloc_strcat(malloc_strcat("assets/sprite_sheet/", name), ".png"), level);
    global->entity_tmp = entity;
    manage_display_battle(global);
    free(str);
}

void entity_talk(entity_t *entity, global_t *global)
{
    FILE *file = fopen(entity->talk_file, "r");
    char *str;
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("resources/fonts/8bit.ttf");
    sfVector2f pos = {.x = 500, .y = 800};
    int space_nbr = 40;
    char *space_buffer = malloc(sizeof(char) * space_nbr);

    for (int i = 0; i < space_nbr; i++)
        space_buffer[i] = ' ';
    space_buffer[space_nbr - 1] = '\0';
    str = get_next_line(file);
    str = malloc_strcat(str, space_buffer);
    sfText_setFont(text, font);
    sfText_setString(text, str);
    sfSound_play(global->sound.ambiant.txtspeak);
    bubble_text_draw(pos,
    text, global->window.window, 50);
    free(space_buffer);
    fclose(file);
}

void entity_act(entity_t *entity, global_t *global)
{
    if (entity->action_type == 1 || entity->action_type == 3) {
        entity_talk(entity, global);
    }
    if (entity->action_type == 2 || entity->action_type == 3) {
        entity_attack(entity, global);
    }
}