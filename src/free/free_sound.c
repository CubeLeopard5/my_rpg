/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** free_sound
*/

#include "free.h"
#include "struct.h"
#include "SFML/Graphics.h"
#include "particles.h"

void free_this_sound(sfSound **sound, sfSoundBuffer **buffer)
{
    sfSound_destroy(*sound);
    sfSoundBuffer_destroy(*buffer);
}

static void free_pika_sound(global_t *global)
{
    free_this_sound(&global->sound.pika.angry, &global->sound.pika.angry_buf);
    free_this_sound(&global->sound.pika.happy2,
    &global->sound.pika.happy2_buf);
    free_this_sound(&global->sound.pika.happy, &global->sound.pika.happy_buf);
    free_this_sound(&global->sound.pika.maybe, &global->sound.pika.maybe_buf);
    free_this_sound(&global->sound.pika.sleepy,
    &global->sound.pika.sleepy_buf);
    free_this_sound(&global->sound.pika.surprised2,
    &global->sound.pika.suprised2_buf);
    free_this_sound(&global->sound.pika.surprised1,
    &global->sound.pika.surprised1_buf);
    free_this_sound(&global->sound.pika.time_for,
    &global->sound.pika.time_for_buf);
    free_this_sound(&global->sound.pika.worried,
    &global->sound.pika.worried_buf);
}

void free_sound(global_t *global)
{
    free_pika_sound(global);
    free_music(global);
}

void free_music(global_t *global)
{
    sfMusic_destroy(global->sound.ambiant.battle_musics);
    sfMusic_destroy(global->sound.ambiant.menu_musics);
    sfMusic_destroy(global->music);
    free_this_sound(&global->sound.ambiant.nooo,
    &global->sound.ambiant.noo_buf);
    free_this_sound(&global->sound.ambiant.victorybattle,
    &global->sound.ambiant.victorybattle_buf);
    free_this_sound(&global->sound.ambiant.bstart,
    &global->sound.ambiant.bstart_buf);
    free_this_sound(&global->sound.ambiant.txtspeak,
    &global->sound.ambiant.txtspeak_buf);
    free_this_sound(&global->sound.ambiant.oof,
    &global->sound.ambiant.oof_buf);
}