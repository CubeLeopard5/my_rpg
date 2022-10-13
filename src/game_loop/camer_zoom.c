/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** camer_zoom
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "init.h"
#include "function.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"
#include "map.h"

void dezoom_camera(global_t *global)
{
    sfVector2f size;

    if (global->camera_zoom <= 1)
        return;
    global->camera_zoom -= 1;
    size.x = 1920 / (1 + 0.5 * (global->camera_zoom - 1));
    size.y = 1080 / (1 + 0.5 * (global->camera_zoom - 1));
    sfView_setSize(global->main_camera, size);
}

void zoom_camera(global_t *global)
{
    sfVector2f size;

    size.x = 1920 / (1 + 0.5 * global->camera_zoom);
    size.y = 1080 / (1 + 0.5 * global->camera_zoom);
    if (global->camera_zoom > 2)
        return;
    global->camera_zoom += 1;
    sfView_setSize(global->main_camera, size);
}
