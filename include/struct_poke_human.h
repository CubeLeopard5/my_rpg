/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** struct_poke_human
*/

#include "SFML/Graphics.h"

#ifndef STRUCT_POKE_HUMAN_H_
#define STRUCT_POKE_HUMAN_H_

typedef struct attack_t
{
    char *name;
    int type;
    sfBool physical;
    int power;
}attack_t;

typedef struct pokehuman_t
{
    char *name;
    int type;
    int life;
    int base_life;
    int level;
    int attack;
    int defense;
    int atk_spe;
    int def_spe;
    attack_t capacities[4];
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
}pokehuman_t;

#endif /* !STRUCT_POKE_HUMAN_H_ */
