/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include "struct_place.h"
#include <stdio.h>
#include "struct.h"

void load_npc(char *name, global_t *global);
void load_place_walkables(FILE *file, place_t *place);
void load_place_spawns(FILE *file, place_t *place);
void load_place_size(FILE *file, place_t *place);

char *get_next_line(FILE *file);
place_t *create_place(void);
void add_zone_to_place(char *line, place_t *place);
void add_all_zones_to_place(FILE *file, place_t *place);
place_t *load_place_from_file(const char *filepath);
void switch_place(global_t *global, char *new_place, int place_nbr);
void free_npc(global_t *global);
char *malloc_strcat(char *a, char *b);

#endif /* !MAP_H_ */