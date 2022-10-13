/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** intro_steps
*/

#include "struct.h"
#include "SFML/Graphics.h"
#include "SFML/Audio.h"
#include "intro.h"
#include "function.h"
#include "engine.h"
#include "init.h"

void intro_steps5(global_t *global, int *intro_state, float *time_float)
{
    switch (*intro_state)
    {
    case 8:
        if (compare_time(global->time.clock, time_float, 2000) != 1)
            return;
        *intro_state += 1;
        change_text(global->intro.text, "an new adventure!");
        sfSound_play(global->sound.pika.happy2);
        break;
    default:
        break;
    }
}

void intro_steps4(global_t *global, int *intro_state, float *time_float)
{
    switch (*intro_state)
    {
    case 6:
        if (compare_time(global->time.clock, time_float, 2000) != 1)
            return;
        *intro_state += 1;
        change_text(global->intro.text, "Or maybe");
        sfSound_play(global->sound.pika.maybe);
        break;
    case 7:
        if (compare_time(global->time.clock, time_float, 1500) != 1)
            return;
        *intro_state += 1;
        change_text(global->intro.text, "maybe, it's time for");
        sfSound_play(global->sound.pika.time_for);
        break;
    default:
        intro_steps5(global, intro_state, time_float);
    }
}

void intro_steps3(global_t *global, int *intro_state, float *time_float)
{
    switch (*intro_state)
    {
    case 4:
        if (compare_time(global->time.clock, time_float, 1500) != 1)
            return;
        *intro_state += 1;
        change_text(global->intro.text, "Am I lost?");
        sfSound_play(global->sound.pika.worried);
        break;
    case 5:
        if (compare_time(global->time.clock, time_float, 2000) != 1)
            return;
        *intro_state += 1;
        sfSound_play(global->sound.pika.angry);
        global->intro.text = change_text(global->intro.text, "HO NO NO NO!");
        break;
    default:
        intro_steps4(global, intro_state, time_float);
    }
}

void intro_steps2(global_t *global, int *intro_state, float *time_float)
{
    switch (*intro_state)
    {
    case 2:
        if (compare_time(global->time.clock, time_float, 1500) != 1)
            return;
        *intro_state += 1;
        global->intro.text = change_text(global->intro.text, NULL);
        global->intro.Pickachu = turn_pika(global->intro.Pickachu, 2);
        break;
    case 3:
        if (compare_time(global->time.clock, time_float, 1500) != 1)
            return;
        *intro_state += 1;
        global->intro.Pickachu = turn_pika(global->intro.Pickachu, 3);
        sfSound_play(global->sound.pika.surprised1);
        global->intro.text = change_text(global->intro.text, "Where am I?");
        break;
    default:
        intro_steps3(global, intro_state, time_float);
    }
}

void intro_steps(global_t *global, int *intro_state, float *time_float)
{
    switch (*intro_state)
    {
    case 0:
        sfMusic_stop(global->sound.ambiant.menu_musics);
        *intro_state += 1;
        sfSound_play(global->sound.pika.surprised2);
        break;
    case 1:
        if (compare_time(global->time.clock, time_float, 1500) != 1)
            return;
        *intro_state += 1;
        global->intro.Pickachu = turn_pika(global->intro.Pickachu, 1);
        break;
    default:
        intro_steps2(global, intro_state, time_float);
        break;
    }
}