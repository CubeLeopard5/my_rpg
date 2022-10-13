/*
** EPITECH PROJECT, 2020
** pos in inventory
** File description:
** rpg
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "function.h"

sfVector2f get_pos_in_inventory(global_t *global, int nb)
{
    nb++;
    sfVector2f cur_center = sfView_getCenter(global->main_camera);
    sfVector2f pos;
    int x = nb % 5 - 1;
    int y = nb / 5;

    if (nb % 5 == 0) {
        x = 4;
        y--;
    }
    pos.x = x * 143;
    pos.y = y * 143;
    pos.x = pos.x + cur_center.x + 50;
    pos.y = pos.y + cur_center.y - 290;
    return (pos);
}