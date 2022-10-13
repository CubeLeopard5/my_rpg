/*
** EPITECH PROJECT, 2020
** init this sprite
** File description:
** init a sprite and return it
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "function.h"

sfSprite *set_sprite_center_to_center(sfSprite *sprite)
{
    sfFloatRect gb = sfSprite_getGlobalBounds(sprite);
    sfVector2f origin;

    origin.x = gb.width/2;
    origin.y = gb.height/ 2;
    sfSprite_setOrigin(sprite, origin);
    return (sprite);
}

sfSprite *init_this_sprite(char *path, global_t *global)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();

    global->texture_array[global->text_nbr] = texture;
    global->text_nbr += 1;
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}
