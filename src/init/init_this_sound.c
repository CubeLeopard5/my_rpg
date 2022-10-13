/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_this_sound
*/

#include "SFML/Audio.h"

void init_this_sound(char *path, sfSound **sound, sfSoundBuffer **buffer)
{
    *buffer =  sfSoundBuffer_createFromFile(path);
    *sound = sfSound_create();
    sfSound_setBuffer(*sound, *buffer);
}