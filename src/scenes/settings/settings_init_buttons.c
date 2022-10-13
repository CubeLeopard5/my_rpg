/*
** EPITECH PROJECT, 2020
** init_ buttons
** File description:
** rpg
*/

#include "scenes/menu.h"

void give_function_to_sttings_button(menu_t *menu,
int i, button_action_t click[])
{
    if (i == 0)
        menu->buttons[i]->on_click = click[i];
    if (i == 1)
        menu->buttons[i]->on_click = click[i];
    if (i == 2)
        menu->buttons[i]->on_click = click[i];
    if (i == 3)
        menu->buttons[i]->on_click = click[i];
    if (i == 4)
        menu->buttons[i]->on_click = click[i];
    if (i == 5)
        menu->buttons[i]->on_click = click[i];
}

sfVector2f fixed_settings_buttons_pos(int i, sfVector2f position)
{
    if (i % 2 == 0)
        position.x += 900;
    if (position.x > 1200)
        position.x = 300;
    if (i % 2 == 1)
        position.y += 120;
    return (position);
}

sfVector2f create_settings_button(menu_t *menu,
int i, sfVector2f position, button_action_t click[])
{
    char *texts[] = {"+", "-", "-", "+", "Window size = 800x600",
    "Window size = 1920x1080", "Return Menu", NULL};

    add_button(menu, texts[i], "resources/fonts/8bit.ttf", sfGreen);
    if (texts[i + 1] == NULL) {
        menu->buttons[i]->on_click = &the_menu;
        position.x = 750;
    } else if (i < 6)
        give_function_to_sttings_button(menu, i, click);
    return (position);
}

void settings_init_buttons(menu_t *menu)
{
    sfVector2f position = {.x = 300, .y = 500};
    sfColor hover_c[] = {sfRed, sfYellow};
    button_action_t hover = &menu_handle_hover;
    button_action_t leave = &menu_handle_leave;
    button_action_t click[] = {&settings_menu_vol_plus,
    &settings_menu_vol_minus, &settings_sound_vol_plus,
    &settings_sound_vol_minus, &settings_resize_window_800x600,
    &settings_resize_window_1920x1080, &the_menu};

    for (int i = 0; i != 7; ++i) {
        position = create_settings_button(menu, i, position, click);
        menu->buttons[i]->on_hover = hover;
        menu->buttons[i]->on_leave = leave;
        button_set_position(menu->buttons[i], position);
        button_set_colors(menu->buttons[i], sfGreen, hover_c[i % 2 ? 1 : 0]);
        position = fixed_settings_buttons_pos(i, position);
    }
}