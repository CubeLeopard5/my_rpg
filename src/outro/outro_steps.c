/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** outro_steps
*/

#include "struct.h"
#include "SFML/Graphics.h"
#include "SFML/Audio.h"
#include "intro.h"
#include "function.h"
#include "engine.h"

void outro_steps2(global_t *global, int *intro_state, float *time_float)
{
    switch (*intro_state)
    {
    case 2:
        if (compare_time(global->time.clock, time_float, 1800) != 1)
            return;
        *intro_state += 1;
        change_text(global->outro.text, "You took drugs" );
        break;
    case 3:
        if (compare_time(global->time.clock, time_float, 1800) != 1)
            return;
        change_text(global->outro.text, "and you're acting weird since");
        *intro_state += 1;
        break;
    case 4:
        if (compare_time(global->time.clock, time_float, 1800) != 1)
            return;
        *intro_state += 1;
        change_text(global->outro.text, "Let's go to the hospital");
    }
}

void outro_steps(global_t *global, int *intro_state, float *time_float)
{
    switch (*intro_state)
    {
    case 0:
        sfMusic_stop(global->music);
        *intro_state += 1;
        change_text(global->outro.text, "I'm not Otaria");
        break;
    case 1:
        if (compare_time(global->time.clock, time_float, 1800) != 1)
            return;
        change_text(global->outro.text, "It's me John, your friend!");
        *intro_state += 1;
        break;
    default:
        outro_steps2(global, intro_state, time_float);
        break;
    }
}