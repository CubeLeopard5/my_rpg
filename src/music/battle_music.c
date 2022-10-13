/*
** EPITECH PROJECT, 2020
** battle_music.c
** File description:
** battle but with music
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "game_loop.h"
#include "entity.h"
#include "init.h"
#include "SFML/Audio.h"

void battle_music_play_stop(global_t *global, int istop)
{
    if (istop == 1) {
        sfMusic_stop(global->sound.ambiant.battle_musics);
    }
    if (istop == 0) {
        sfMusic_play(global->sound.ambiant.battle_musics);
    }
}