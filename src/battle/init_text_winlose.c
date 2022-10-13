/*
** EPITECH PROJECT, 2020
** text win and lose
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

sfText *init_text_win(void)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("resources/fonts/8bit.ttf");

    sfText_setString(text, "Congratulation, you won!            ");
    sfText_setFont(text, font);
    return (text);
}

sfText *init_text_lose(void)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("resources/fonts/8bit.ttf");

    sfText_setString(text, "Oh no, yous lost the match!           ");
    sfText_setFont(text, font);
    return (text);
}

sfVector2f init_pos_win(global_t *global)
{
    sfVector2f pos = sfView_getCenter(global->main_camera);

    pos.x -= 960;
    pos.y += 162;
    return (pos);
}