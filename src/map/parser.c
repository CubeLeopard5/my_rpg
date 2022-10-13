/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** parser.c
*/

#include "minilib.h"
#include "struct_place.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "map.h"

char *get_next_line(FILE *file)
{
    char *input = NULL;
    size_t n = 0;
    ssize_t rbytes = getline(&input, &n, file);

    if (rbytes <= 0) {
        free(input);
        input = NULL;
    } else {
        input[rbytes - 1] = '\0';
    }
    return input;
}

place_t *create_place(void)
{
    place_t *place = malloc(sizeof(place_t));

    if (!place)
        return NULL;
    place->size = (sfVector2i) {.x = 0, .y = 0};
    place->spawn = NULL;
    place->tiles = NULL;
    place->type = -1;
    place->walkables = NULL;
    place->zones = NULL;
    return place;
}

void add_zone_to_place(char *line, place_t *place)
{
    unsigned int count = 0;
    char **params = my_strsplit(line, ';');
    zone_info_t **arr = NULL;

    for (; place->zones[count]; ++count);
    arr = malloc(sizeof(zone_info_t *) * (count + 2));
    for (unsigned int i = 0; place->zones[i]; ++i)
        arr[i] = place->zones[i];
    arr[count] = malloc(sizeof(zone_info_t));
    arr[count]->local.x = my_atoi(params[0]);
    arr[count]->local.y = my_atoi(params[1]);
    arr[count]->dest.x = my_atoi(params[2]);
    arr[count]->dest.y = my_atoi(params[3]);
    arr[count]->name = my_strdup(params[4]);
    arr[count + 1] = NULL;
    free(place->zones);
    place->zones = arr;
}

void add_all_zones_to_place(FILE *file, place_t *place)
{
    char *line = get_next_line(file);

    place->zones = malloc(sizeof(zone_info_t *));
    place->zones[0] = NULL;
    while (line) {
        if (my_strlen(line) > 0)
            add_zone_to_place(line, place);
        free(line);
        line = get_next_line(file);
    }
}

place_t *load_place_from_file(const char *filepath)
{
    FILE *file = fopen(filepath, "r");
    place_t *place = create_place();

    if (!file || !place) {
        my_putstr("didn't opened file\n");
        return NULL;
    }
    place->type = my_atoi(get_next_line(file));
    load_place_walkables(file, place);
    load_place_spawns(file, place);
    load_place_size(file, place);
    add_all_zones_to_place(file, place);
    fclose(file);
    return place;
}
