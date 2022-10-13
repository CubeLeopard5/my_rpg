/*
** EPITECH PROJECT, 2020
** add object to the inv
** File description:
** rpg
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "function.h"

void remove_object_inv(global_t *global, char *name)
{
    int i = 0;

    for (i; global->object[i].id != 1; i++)
        if (i > 24)
            return;
    global->object[i].name = NULL;
    global->object[i].id = 0;
    global->object[i].tx =
    sfTexture_createFromFile("assets/images/cache.png", NULL);
    sfSprite_setTexture(global->object[i].spr, global->object[i].tx, sfTrue);
}

void add_object_inv(global_t *global, char *name, int id, const char *texture)
{
    int i = 0;

    for (i; global->object[i].name != NULL; i++)
        if (i > 24)
            return;
    global->object[i].name = name;
    global->object[i].id = id;
    global->object[i].tx = sfTexture_createFromFile(texture, NULL);
    sfSprite_setTexture(global->object[i].spr, global->object[i].tx, sfTrue);
}