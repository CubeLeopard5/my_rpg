/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** battle
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
#include <unistd.h>

sfText * is_efficient(global_t *global, pokehuman_t *attacker,
pokehuman_t *defender);

void do_attack_animation(pokehuman_t *attacker, pokehuman_t *defender,
attack_t *attack, global_t *global)
{
    sfVector2f pos = init_pos_atk(global);
    sfVector2f pos2 = sfView_getCenter(global->main_camera);
    sfText *text = init_text_atk(attacker, attack);

    pos2.x -= 960;
    pos2.y += 162;
    move_rect(global, 1, attacker->sprite);
    display_battle(attacker, defender, global, global->pokemon_turn);
    if (attack->physical == 1) {
        bubble_text_draw_big(pos2, text, global->window.window, 100);
        sfSound_play(global->sound.ambiant.oof);
        particle_spray(pos, sfRed, global->window.window, 10);
    }
    else if (attack->physical == 0) {
        bubble_text_draw_big(pos2, text, global->window.window, 100);
        sfSound_play(global->sound.ambiant.oof);
        advanced_particle_spray(pos, sfRed, global->window.window, 100);
    }
}

void attack(pokehuman_t *attacker, pokehuman_t *defender,
attack_t *attack, global_t *global)
{
    int power;

    if (attack->physical == 1) {
        power = ((attacker->level * 0.6 + 2) * attacker->attack *
        attack->power) / (defender->defense * 50) * 1.5;
    } else {
        power = ((attacker->level * 0.6 + 2) * attacker->atk_spe *
        attack->power) / (defender->def_spe * 50) * 1.5;
    }
    if (power < 8)
        power = 8;
    power = power * global->type_chart[attacker->type][defender->type] / 2;
    do_attack_animation(attacker, defender, attack, global);
    put_attack_msg(global, attacker, defender);
    defender->life -= power;
}

int enemy_turn(pokehuman_t *player, pokehuman_t *enemy, global_t *global)
{
    attack_t chosen_atk = enemy->capacities[rand() % 5];
    sfText *text;
    sfVector2f pos;

    global->pokemon_turn = 2;
    if (!(enemy->life <= 0))
        attack(enemy, player, &chosen_atk, global);
    global->player.atk_choice = -1;
    if (player->life <= 0) {
        text = init_text_lose();
        pos = init_pos_win(global);
        sfSound_play(global->sound.ambiant.nooo);
        bubble_text_draw_big(pos, text, global->window.window, 100);
        global->pokemon_turn = 4;
        global->display_battle = 0;
        battle_music_play_stop(global, 1);
        sfMusic_play(global->music);
        global->meteo_rand = (rand() % 5);
    }
    return (0);
}

int player_turn(pokehuman_t *player, pokehuman_t *enemy, global_t *global)
{
    attack_t chosen_atk = player->capacities[global->player.atk_choice];
    sfText *text;
    sfVector2f pos;

    if (global->player.atk_choice == -1)
        return (0);
    global->pokemon_turn = 1;
    attack(player, enemy, &chosen_atk, global);
    if (enemy->life <= 0) {
        text = init_text_win();
        pos = init_pos_win(global);
        sfSound_play(global->sound.ambiant.victorybattle);
        bubble_text_draw_big(pos, text, global->window.window, 100);
        global->pokemon_turn = 3;
        global->display_battle = 0;
        battle_music_play_stop(global, 1);
        sfMusic_play(global->music);
        global->meteo_rand = (rand() % 5);
    }
    return (1);
}

int battle(pokehuman_t *player, pokehuman_t *enemy, global_t *global)
{
    global->animation_battle = 0;
    global->pokemon_turn = 1;
    for (int i = 0; i < 4; i++)
        sfText_setString(global->button_battle[i].text,
        player->capacities[i].name);
    while (sfRenderWindow_isOpen(global->window.window)
    && global->display_battle == 1) {
        move_rect(global, 2, player->sprite);
        move_rect(global, 0, enemy->sprite);
        display_battle(player, enemy, global, 1);
        if (player_turn(player, enemy, global) == 0)
            continue;
        move_rect(global, 2, player->sprite);
        move_rect(global, 0, enemy->sprite);
        display_battle(player, enemy, global, 1);
        if (enemy_turn(player, enemy, global) == 0)
            continue;
    }
    return (global->pokemon_turn);
}