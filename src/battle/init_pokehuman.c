/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_pokehuman
*/

#include "battle.h"
#include "init.h"
#include <SFML/Graphics.h>
#include "minilib.h"
#include "stdio.h"
#include "stddef.h"
#include "function.h"
#include "my.h"
#include <stdlib.h>

char *get_next_line(FILE *file);

int init_poke_types(char *name)
{
    FILE *file = fopen("assets/pokemon_types", "r");
    char *buffer = get_next_line(file);
    int type;

    while (buffer != NULL) {
        buffer = get_next_line(file);
        if (my_strcmp(name, buffer) == 0) {
            buffer = get_next_line(file);
            type = my_atoi(buffer);
            break;
        } else {
            buffer = get_next_line(file);
        }
    }
    type = my_atoi(buffer);
    fclose(file);
    free(buffer);
    return (type);
}

char remove_extension(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            str[i] = '\0';
            return (str[i]);
        }
    }
    return ('\0');
}

char *get_pokehum_name(char *str)
{
    char *name = malloc(sizeof(char) * my_strlen(str));
    int i = 0;
    int n = 0;

    for (int counter = 0; counter < 2; i++) {
        if (str[i] == '/') {
            counter++;
        }
    }
    for (; str[i] != '.'; i++) {
        name[n] = str[i];
        n++;
    }
    name[n] = '\0';
    return (name);
}

pokehuman_t init_pokehuman(global_t *global, char *name, int level)
{
    pokehuman_t poke;

    poke.sprite = init_this_sprite(name, global);
    poke.atk_spe = level + 10 + rand () % level;
    poke.attack = level + 10 + rand () % level;
    poke.def_spe = level + 10 + rand () % level;
    poke.defense = level + 10 + rand () % level;
    poke.life = level + 10 + rand () % level;
    poke.base_life = poke.life;
    poke.level = level;
    poke.name = get_pokehum_name(name);
    poke.type = 0;
    poke.pos.x = 0;
    poke.pos.y = 0;
    poke.scale.x = 1;
    poke.scale.y = 1;
    init_attacks(&poke);
    poke.type = init_poke_types(poke.name);
    return (poke);
}
