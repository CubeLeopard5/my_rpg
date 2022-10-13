/*
** EPITECH PROJECT, 2020
** init text of attacks
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

char *my_triple_str_concat(char *str1, char *str2, char *str3)
{
    char *rtn;
    int a = my_strlen(str1);
    int b = my_strlen(str2);
    int c = my_strlen(str3);
    int i = 0;

    rtn = malloc(sizeof(char) * (a + b + c + 1));
    for (int j = 0; str1[j] != '\0'; j++, i++)
        rtn[i] = str1[j];
    for (int k = 0; str2[k] != '\0'; k++, i++)
        rtn[i] = str2[k];
    for (int l = 0; str3[l] != '\0'; l++, i++)
        rtn[i] = str3[l];
    rtn[i] = '\0';
    return (rtn);
}

char *my_init_char(char *str)
{
    char *r;

    r = malloc(sizeof(char) * my_strlen(str) + 1);
    for (int i = 0; str[i] != '\0'; i++)
        r[i] = str[i];
    return (r);
}

sfText * is_efficient(global_t *global, pokehuman_t *attacker,
pokehuman_t *defender)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("resources/fonts/8bit.ttf");
    char *str;

    if (global->type_chart[attacker->type][defender->type] == 0)
        str = my_init_char("It had no effect.              ");
    if (global->type_chart[attacker->type][defender->type] == 1)
        str = my_init_char("It's not very effective.           ");
    if (global->type_chart[attacker->type][defender->type] == 2)
        str = my_init_char("It's effective.              ");
    if (global->type_chart[attacker->type][defender->type] == 4)
        str = my_init_char("It's very effective.           ");
    sfText_setString(text, str);
    sfText_setFont(text, font);
    return (text);
}

sfText *init_text_atk(pokehuman_t *attacker, attack_t *attack)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("resources/fonts/8bit.ttf");
    char *str = my_triple_str_concat(attacker->name, " use ", attack->name);

    sfText_setString(text, str);
    sfText_setFont(text, font);
    return (text);
}

sfVector2f init_pos_atk(global_t *global)
{
    sfVector2f pos = sfView_getCenter(global->main_camera);

    if (global->animation_battle == 0) {
        pos.x += 25;
        pos.y -= 350;
    }
    if (global->animation_battle == 1) {
        pos.x -= 50;
        pos.y -= 0;
    }
    if (global->animation_battle == 1)
        global->animation_battle = 0;
    else
        global->animation_battle = 1;
    return (pos);
}