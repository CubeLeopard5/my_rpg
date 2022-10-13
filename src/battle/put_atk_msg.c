/*
** EPITECH PROJECT, 2020
** render message atk
** File description:
** rpg
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "function.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"
#include <stdlib.h>
#include "particles.h"

sfText * is_efficient(global_t *global, pokehuman_t *attacker,
pokehuman_t *defender);

void put_attack_msg(global_t *global, pokehuman_t *attacker,
pokehuman_t *defender)
{
    sfText *text;
    sfVector2f pos;

    text = is_efficient(global, attacker, defender);
    pos = sfView_getCenter(global->main_camera);
    pos.x -= 960;
    pos.y += 162;
    bubble_text_draw_big(pos, text, global->window.window, 100);
}