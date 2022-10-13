/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** struct_sound
*/

#include "SFML/Audio.h"

#ifndef STRUCT_SOUND_H_
#define STRUCT_SOUND_H_

typedef struct pika_sound_t
{
    sfSoundBuffer *happy_buf;
    sfSound *happy;
    sfSoundBuffer *happy2_buf;
    sfSound *happy2;
    sfSoundBuffer *angry_buf;
    sfSound *angry;
    sfSoundBuffer *sleepy_buf;
    sfSound *sleepy;
    sfSoundBuffer *surprised1_buf;
    sfSound *surprised1;
    sfSoundBuffer *suprised2_buf;
    sfSound *surprised2;
    sfSoundBuffer *worried_buf;
    sfSound *worried;
    sfSoundBuffer *time_for_buf;
    sfSound *time_for;
    sfSoundBuffer *maybe_buf;
    sfSound *maybe;
}pika_sound_t;

typedef struct ambiant_sound_t
{
    sfMusic *battle_musics;
    sfMusic *menu_musics;
    sfMusic *building_musics;
    sfSoundBuffer *noo_buf;
    sfSoundBuffer *victorybattle_buf;
    sfSound *nooo;
    sfSound *victorybattle;
    sfSoundBuffer *bstart_buf;
    sfSound *bstart;
    sfSoundBuffer *txtspeak_buf;
    sfSound *txtspeak;
    sfSoundBuffer *oof_buf;
    sfSound *oof;
}ambiant_sound_t;

typedef struct my_sound_t
{
    pika_sound_t pika;
    ambiant_sound_t ambiant;
}my_sound_t;


#endif /* !STRUCT_SOUND_H_ */
