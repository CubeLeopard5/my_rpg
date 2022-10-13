/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_sound
*/

#include "init.h"
#include "particles.h"

void init_sound(global_t *global)
{
    init_this_sound("assets/sounds/Pika/angry.ogg",
    &global->sound.pika.angry, &global->sound.pika.angry_buf);
    init_this_sound("assets/sounds/Pika/Happy.ogg",
    &global->sound.pika.happy, &global->sound.pika.happy_buf);
    init_this_sound("assets/sounds/Pika/Happy_2.ogg",
    &global->sound.pika.happy2, &global->sound.pika.happy2_buf);
    init_this_sound("assets/sounds/Pika/its_time_for.ogg",
    &global->sound.pika.time_for, &global->sound.pika.time_for_buf);
    init_this_sound("assets/sounds/Pika/maybe.ogg",
    &global->sound.pika.maybe, &global->sound.pika.maybe_buf);
    init_this_sound("assets/sounds/Pika/sleepy.ogg",
    &global->sound.pika.sleepy, &global->sound.pika.sleepy_buf);
    init_this_sound("assets/sounds/Pika/surprised_1.ogg",
    &global->sound.pika.surprised1, &global->sound.pika.surprised1_buf);
    init_this_sound("assets/sounds/Pika/surprised_2.ogg",
    &global->sound.pika.surprised2, &global->sound.pika.suprised2_buf);
    init_this_sound("assets/sounds/Pika/worried.ogg",
    &global->sound.pika.worried, &global->sound.pika.worried_buf);
    init_music(global);
}

void init_music(global_t *global)
{
    global->sound.ambiant.battle_musics =
    sfMusic_createFromFile("assets/sounds/Music/fight/kalinka.ogg");
    sfMusic_setLoop(global->sound.ambiant.battle_musics, sfTrue);
    sfMusic_stop(global->sound.ambiant.battle_musics);
    global->sound.ambiant.menu_musics =
    sfMusic_createFromFile("assets/sounds/Music/menu/menu_th.ogg");
    sfMusic_setLoop(global->sound.ambiant.menu_musics, sfTrue);
    sfMusic_play(global->sound.ambiant.menu_musics);
    init_this_sound("assets/sounds/Music/fight/nooo.ogg",
    &global->sound.ambiant.nooo, &global->sound.ambiant.noo_buf);
    init_this_sound("assets/sounds/Music/fight/victorybattle.ogg",
    &global->sound.ambiant.victorybattle,
    &global->sound.ambiant.victorybattle_buf);
    init_this_sound("assets/sounds/Music/fight/nani.ogg",
    &global->sound.ambiant.bstart, &global->sound.ambiant.bstart_buf);
    init_this_sound("assets/sounds/Music/fight/text_start.ogg",
    &global->sound.ambiant.txtspeak, &global->sound.ambiant.txtspeak_buf);
    init_this_sound("assets/sounds/Music/fight/oof.ogg",
    &global->sound.ambiant.oof, &global->sound.ambiant.oof_buf);
    music_sound_reduceing(global);
}

void music_sound_reduceing(global_t *global)
{
    sfMusic_setVolume(global->sound.ambiant.menu_musics, 70);
    sfMusic_setVolume(global->sound.ambiant.battle_musics, 70);
    sfSound_setVolume(global->sound.ambiant.oof, 200);
}