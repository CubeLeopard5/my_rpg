/*
** EPITECH PROJECT, 2020
** settings
** File description:
** rpg
*/

#include "scenes/menu.h"

void init_text_settings(menu_t *menu)
{
    char *text[] = {"Music volume", "Sound volume", "Window size", NULL};
    sfFont *font = sfFont_createFromFile("resources/fonts/8bit.ttf");

    menu->settings.pos_text = malloc(sizeof(sfVector2f) *
    menu->settings.text_count);
    menu->settings.text = malloc(sizeof(sfText *) * menu->settings.text_count);
    for (int i = 0; text[i] != NULL; i++) {
        menu->settings.text[i] = sfText_create();
        sfText_setString(menu->settings.text[i], text[i]);
        sfText_setFont(menu->settings.text[i], font);
        sfText_setColor(menu->settings.text[i], sfWhite);
        sfText_setCharacterSize(menu->settings.text[i], 30);
        menu->settings.pos_text[i].x = 800;
        menu->settings.pos_text[i].y = 525 + i * 120;
        sfText_setPosition(menu->settings.text[i],
        menu->settings.pos_text[i]);
    }
}

void settings_init_sprite(menu_t *menu)
{
    char *image[] = {"assets/images/otarias_quest.png", NULL};

    menu->sprites = malloc(sizeof(sfSprite *) * menu->sprite_count);
    menu->textures = malloc(sizeof(sfTexture *) * menu->texture_count);
    for (int i = 0; image[i] != NULL; i++)
        menu->textures[i] =
        sfTexture_createFromFile(image[i], NULL);
    for (int i = 0; i < menu->sprite_count; i++)
        menu->sprites[i] = sfSprite_create();
    sfSprite_setTexture(menu->sprites[0], menu->textures[0], sfTrue);
}

void init_settings(menu_t *menu)
{
    menu->button_count = 0;
    menu->sprite_count = 1;
    menu->texture_count = 1;
    menu->settings.text_count = 3;
    menu->buttons = NULL;
    menu->sprites = NULL;
    menu->textures = NULL;
    settings_init_sprite(menu);
    settings_init_buttons(menu);
    init_text_settings(menu);
}

void settings_destroy(menu_t *menu)
{
    for (int i = 0; i < menu->button_count; ++i)
        button_destroy(menu->buttons[i]);
    free(menu->buttons);
    for (int i = 0; i < menu->settings.text_count; ++i)
        sfText_destroy(menu->settings.text[i]);
    free(menu->settings.text);
    free(menu->settings.pos_text);
}