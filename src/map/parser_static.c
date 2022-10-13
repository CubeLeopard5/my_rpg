/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** parser_static.c
*/

#include "minilib.h"
#include "struct_place.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "map.h"

void load_place_walkables(FILE *file, place_t *place)
{
    char *line = get_next_line(file);
    char **params = my_strsplit(line, ';');
    unsigned int count = count_list(params);

    place->walkables = malloc(sizeof(int) * (count + 1));
    for (unsigned int i = 0; i < count; ++i)
        place->walkables[i] = my_atoi(params[i]);
    place->walkables[count] = -1;
    destroy_list(params);
    free(line);
}

void load_place_spawns(FILE *file, place_t *place)
{
    char *line = get_next_line(file);
    char **params = my_strsplit(line, ';');
    unsigned int count = count_list(params);

    place->spawn = malloc(sizeof(int) * (count + 1));
    for (unsigned int i = 0; i < count; ++i)
        place->spawn[i] = my_atoi(params[i]);
    place->spawn[count] = -1;
    destroy_list(params);
    free(line);
}

void load_place_size(FILE *file, place_t *place)
{
    char *line = get_next_line(file);
    char **params = my_strsplit(line, ';');

    place->size.x = my_atoi(params[0]);
    place->size.y = my_atoi(params[1]);
    destroy_list(params);
    free(line);
}