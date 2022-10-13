/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** poke_level_up
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "function.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"
#include <stdlib.h>
#include "particles.h"
#include <unistd.h>

void poke_level_up(pokehuman_t *poke)
{
    poke->base_life += rand() % ((2 - 1 + 1)) + 1;
    poke->life = poke->base_life;
    poke->atk_spe += rand() % ((2 - 1 + 1)) + 1;
    poke->attack += rand() % ((2 - 1 + 1)) + 1;
    poke->def_spe += rand() % ((2 - 1 + 1)) + 1;
    poke->defense += rand() % ((2 - 1 + 1)) + 1;
    poke->level += 1;
    poke->life += rand() % ((2 - 1 + 1)) + 1;
}