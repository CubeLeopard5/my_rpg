/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_music
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "init.h"
#include "function.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"
#include "map.h"

void load_music(global_t *global, char *name)
{
    global->music = sfMusic_createFromFile(malloc_strcat
    (malloc_strcat("assets/music/", name), ".ogg"));
    sfMusic_play(global->music);
    sfMusic_setLoop(global->music, sfTrue);
}