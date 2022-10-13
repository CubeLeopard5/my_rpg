/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** battle
*/

#include "struct.h"

#ifndef BATTLE_H_
#define BATTLE_H_

int battle(pokehuman_t *player, pokehuman_t *enemy, global_t *global);
pokehuman_t init_pokehuman(global_t *global, char *name, int level);
attack_t *init_attacks(pokehuman_t *pokehuman);
void poke_level_up(pokehuman_t *poke);
void put_attack_msg(global_t *global, pokehuman_t *attacker,
pokehuman_t *defender);

#endif /* !BATTLE_H_ */
