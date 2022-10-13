/*
** EPITECH PROJECT, 2020
** event in settings menu
** File description:
** rpg
*/

#include "scenes/menu.h"
#include "minilib.h"

void settings_menu_vol_plus(menu_t *menu, button_t *button)
{
    menu->settings.game_vol += 1;
}

void settings_menu_vol_minus(menu_t *menu, button_t *button)
{
    menu->settings.game_vol -= 1;
}

void settings_sound_vol_plus(menu_t *menu, button_t *button)
{
    menu->settings.sound_vol += 1;
}

void settings_sound_vol_minus(menu_t *menu, button_t *button)
{
    menu->settings.sound_vol -= 1;
}