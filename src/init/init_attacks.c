/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_attacks
*/

#include "minilib.h"
#include "struct.h"
#include "stdio.h"
#include "stddef.h"
#include "function.h"
#include "my.h"
#include <stdlib.h>
#include "map.h"

int add_digit_to_number(int nbr, int i)
{
    nbr *= 10;
    nbr += i;
    return (nbr);
}

attack_t parse_this_attack(char *str)
{
    attack_t attack;
    int parser = 0;

    attack.name = malloc(sizeof(char) * my_strlen(str));
    attack.power = 0;
    for (; str[parser] != ';'; parser++)
        attack.name[parser] = str[parser];
    attack.name[parser] = '\0';
    parser += 1;
    for (; str[parser] != ';'; parser++)
        attack.power = add_digit_to_number(attack.power, str[parser] - 48);
    parser += 1;
    attack.physical = str[parser] - 48;
    return (attack);
}

attack_t *init_attacks(pokehuman_t *pokehuman)
{
    char *path = malloc_strcat("assets/attacks/", pokehuman->name);
    FILE *file = fopen(path, "r");
    char *line;

    if (file == NULL)
        my_putstr("no attack file for that pokemon\n");
    for (int i = 0; i < 4;i++)
    {
        line = get_next_line(file);
        if (line == NULL)
            break;
        pokehuman->capacities[i] = parse_this_attack(line);
    }
    return (pokehuman->capacities);
}