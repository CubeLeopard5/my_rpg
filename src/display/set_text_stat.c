/*
** EPITECH PROJECT, 2020
** new text stat
** File description:
** rpg
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "stdio.h"
#include "function.h"

char *type_to_string_3(int type)
{
    switch (type) {
    case 16:
        return ("Steel");
    case 17:
        return ("Fairy");
    default:
        return ("Steel");
    }
}

char *type_to_string_2(int type)
{
    switch (type) {
    case 8:
        return ("Ground");
    case 9:
        return ("Fly");
    case 10:
        return ("Psy");
    case 11:
        return ("Bug");
    case 12:
        return ("Rock");
    case 13:
        return ("Ghost");
    case 14:
        return ("Dragon");
    case 15:
        return ("Dark");
    default:
        return (type_to_string_3(type));
    }
}

char *type_to_string(int type)
{
    switch (type) {
    case 0:
        return ("Normal");
    case 1:
        return ("Fire");
    case 2:
        return ("Water");
    case 3:
        return ("Electicity");
    case 4:
        return ("Grass");
    case 5:
        return ("Ice");
    case 6:
        return ("Fight");
    case 7:
        return ("Poison");
    default:
        return (type_to_string_2(type));
    }
}

void set_new_stat(global_t *global)
{
    sfVector2f cur_center = sfView_getCenter(global->main_camera);
    char *newtext[] = {"level : ", "type : ", "life : ", "atk : ", "def : ",
    "atk spe : ", "def spe : ", NULL};
    char *newstat[] = {my_nbr_to_str(global->player.pokemon.level),
    type_to_string(global->player.pokemon.type),
    my_nbr_to_str(global->player.pokemon.life),
    my_nbr_to_str(global->player.pokemon.attack),
    my_nbr_to_str(global->player.pokemon.defense),
    my_nbr_to_str(global->player.pokemon.atk_spe),
    my_nbr_to_str(global->player.pokemon.def_spe), NULL};

    for (int i = 0; newtext[i] != NULL && newstat[i] != NULL; i++) {
        global->text_stat[i].pos.x = cur_center.x - 650;
        global->text_stat[i].pos.y = cur_center.y + i * 50;
        sfText_setPosition(global->text_stat[i].text,
        global->text_stat[i].pos);
        sfText_setString(global->text_stat[i].text,
        malloc_strcat(newtext[i], newstat[i]));
    }
}