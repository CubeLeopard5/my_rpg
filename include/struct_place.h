/*
** EPITECH PROJECT, 2020
** struct place
** File description:
** structure for place
*/

#include "SFML/Graphics.h"

#ifndef STRUCT_PLACE_H_
#define STRUCT_PLACE_H_

typedef struct tile_t
{
    sfSprite *sprite;
    int walkable;
    int is_tunnel;
    char *direction_name;
}tile_t;
//char *direction_name; Remplir uniquement si tunnel
typedef struct zone_info_s {
    sfVector2i local;
    sfVector2i dest;
    char *name;
} zone_info_t;

typedef struct place_t
{
    int type;
    int *walkables;
    int *spawn;
    tile_t **tiles;
    sfVector2i size;
    zone_info_t **zones;
}place_t;

/*
typedef struct place_t
{
    int type;  type d'environnement
    int *walkables;  types de cases walkable
    int *spawn;  types de cases où les poké peuvent spawn
    tile_t **tiles;  tiles
    sfVector2i size;  taille de la zone
    zone_info_t **zones;  zones de destination
}place_t;
*/

/* !STRUCT_PLACE_H_ */
#endif
