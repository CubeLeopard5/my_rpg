/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main.c
*/

#include "minilib.h"
#include "scenes/menu.h"
#include "init.h"
#include "game_loop.h"
#include "free.h"
#include <time.h>
#include "intro.h"

void prepare_window(menu_t *menu)
{
    sfVector2u window_size = {.x = 1920, .y = 1080};
    sfRenderWindow *window = get_window(&window_size, sfFalse, "My_rpg", 60);

    menu->user_choice = 0;
    menu->settings.game_vol = 50;
    menu->settings.sound_vol = 50;
    menu->window = window;
    menu->window_size = window_size;
    srand(time(NULL));
}

int main(void)
{
    int choice = 0;
    menu_t menu;
    global_t global;

    prepare_window(&menu);
    global.window.window = menu.window;
    init_structs(&global);
    while (1) {
        choice = menu_scene(&menu);
        if (choice == 1)
            choice = game_loop(&global);
        if (choice == 2)
            menu_settings(&menu);
        if (choice == 3)
            how_to_play(&menu);
        if (choice == 4 || !(sfRenderWindow_isOpen(menu.window)))
            break;
    }
    free_struct(&global);
    return (0);
}
