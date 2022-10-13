/*
** EPITECH PROJECT, 2020
** switch place
** File description:
** function for going to one place from another
*/

#include <SFML/Graphics.h>
#include "function.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "stdio.h"
#include "unistd.h"
#include "minilib.h"
#include "map.h"
#include "engine.h"
#include "entity.h"
#include "init.h"

void set_tunnel(tile_t *tile, place_t *place, int i, int j)
{
    for (int n = 0; place->zones[n] == NULL; n++) {
        if (place->zones[n]->local.y == i && place->zones[n]->local.x == j) {
            tile->is_tunnel == 1;
            tile->direction_name == place->zones[n]->name;
        }
    }
}

void fill_this_tile(global_t *global, tile_t *tile, place_t *place, char *buff)
{
    int type = (int)my_atoi(buff);

    tile->sprite = global->env_spr[1][type];
    for (int i = 0; place->walkables[i] != -1; i++) {
        if (place->walkables[i] == type) {
            tile->walkable = 1;
            break;
        }
        tile->walkable = 0;
    }
}

place_t *load_place(global_t *global, char *name)
{
    char *path = malloc_strcat(malloc_strcat("assets/map/", name), "_info");
    place_t *place = load_place_from_file(path);
    int fd = open(malloc_strcat("assets/map/", name), O_RDONLY);
    char *buffer = malloc(sizeof(char) * 2);

    buffer[1] = '\0';
    place->tiles = malloc(sizeof(tile_t *) * (place->size.y + 1));
    for (int i = 0; i < place->size.y ; i++) {
        place->tiles[i] = malloc(sizeof(tile_t) * (place->size.x + 1));
        for (int j = 0; j < place->size.x; j++) {
            read(fd, buffer, 1);
            fill_this_tile(global, &place->tiles[i][j], place, buffer);
            set_tunnel(&place->tiles[i][j], place, i, j);
        }
        read(fd, buffer, 1);
        place->tiles[i][place->size.x].sprite = NULL;
    }
    place->tiles[place->size.y] = NULL;
    free(buffer);
    return (place);
}

void free_place(place_t *place)
{
    free(place->spawn);
    for (int i = 0; place->tiles[i] != NULL; i++)
        free(place->tiles[i]);
    free(place->walkables);
    for (int i = 0; place->zones[i] != NULL; i++)
        free(place->zones[i]);
    free(place);
}

void switch_place(global_t *global, char *new_place, int place_nbr)
{
    global->player.pos = vector_int_to_float
    (global->place->zones[place_nbr]->dest);
    global->player.pos.x = global->player.pos.x * 64 + 32;
    global->player.pos.y = global->player.pos.y * 64 + 32;
    free_place(global->place);
    free_npc(global);
    if (my_strcmp(new_place, "road_3") == 0) {
        global->end_zone = 1;
    }
    global->place = load_place(global, new_place);
    load_npc(new_place, global);
    sfMusic_destroy(global->music);
    load_music(global, new_place);
}