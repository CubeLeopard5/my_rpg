/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init.c
*/

#include "scenes/menu.h"

void give_function_to_button(menu_t *menu, button_action_t click[], int i)
{
    if (i == 0)
        menu->buttons[i]->on_click = click[0];
    if (i == 1)
        menu->buttons[i]->on_click = click[1];
    if (i == 2)
        menu->buttons[i]->on_click = click[2];
}

void menu_init_buttons(menu_t *menu)
{
    sfVector2f position = {.x = 800, .y = 500};
    sfColor hover_c[] = {sfRed, sfYellow};
    button_action_t hover = &menu_handle_hover;
    button_action_t click[] = {&menu_handle_click_play,
    &menu_handle_click_settings, &menu_handle_click_howtplay};
    char *texts[] = {"Play", "Settings", "How to play",
    "Exit (close window)", NULL};

    for (int i = 0; texts[i] != NULL; ++i, position.y += 120) {
        add_button(menu, texts[i], "resources/fonts/8bit.ttf", sfGreen);
        if (menu->button_count != i + 1)
            return;
        if (texts[i + 1] == NULL) {
            menu->buttons[i]->on_click = &menu_handle_click_quit;
        } else
            give_function_to_button(menu, click, i);
        menu->buttons[i]->on_hover = hover;
        menu_init_buttons_2(menu, i, position, hover_c);
    }
}

void menu_init_sprite(menu_t *menu)
{
    char *image[] = {"assets/images/otarias_quest.png",
    "assets/images/Red_Square.png", NULL};

    menu->sprites = malloc(sizeof(sfSprite *) * menu->sprite_count);
    menu->textures = malloc(sizeof(sfTexture *) * menu->texture_count);
    for (int i = 0; image[i] != NULL; i++)
        menu->textures[i] =
        sfTexture_createFromFile(image[i], NULL);
    for (int i = 0; i < menu->sprite_count; i++)
        menu->sprites[i] = sfSprite_create();
    sfSprite_setTexture(menu->sprites[0], menu->textures[0], sfTrue);
}

void menu_init(menu_t *menu)
{
    menu->button_count = 0;
    menu->sprite_count = 1;
    menu->texture_count = 2;
    menu->buttons = NULL;
    menu->sprites = NULL;
    menu->textures = NULL;
    menu_init_sprite(menu);
    menu_init_buttons(menu);
}

void menu_destroy(menu_t *menu)
{
    for (int i = 0; i < menu->button_count; ++i)
        button_destroy(menu->buttons[i]);
    free(menu->buttons);
}