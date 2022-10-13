/*
** EPITECH PROJECT, 2020
** init structs
** File description:
** init the structures
*/

#include "my.h"
#include <SFML/Graphics.h>
#include "init.h"
#include "function.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"
#include "particles.h"
#include "map.h"
#include "entity.h"
#include <stdlib.h>

void init_main_camera(global_t *global)
{
    sfFloatRect view;
    sfVector2f screen_size;

    screen_size.x = 1920;
    screen_size.y = 1080;
    view.height = 1080;
    view.left = 0;
    view.top = 0;
    view.width = 1920;
    screen_size.x /= 2;
    screen_size.y /= 2;
    global->main_camera = sfView_createFromRect(view);
    sfView_setCenter(global->main_camera, screen_size);
    sfRenderWindow_setView(global->window.window, global->main_camera);
}

void init_ui(global_t *global)
{
    init_main_camera(global);
    init_sprite_ui(global);
    init_button_ui(global);
    init_button_pause(global);
    init_text_pause(global);
    init_button_battle(global);
    init_my_rect(global);
    global->end_zone = 0;
    make_it_rain_or_snow(global, 1, 5, 1);
    global->meteo_rand = (rand() % 5);
}

void init_structs(global_t *global)
{
    global->text_nbr = 0;
    global->texture_array = malloc(sizeof(sfTexture *) * 100);
    init_environnement(global);
    init_player(&global->player, global);
    init_input(&global->input);
    init_time(&global->time);
    global->place = load_place(global, "road_1");
    init_sprite_sheet(global);
    init_rect_player(global);
    init_background_battle(global);
    init_game_entities(global);
    load_npc("road_1", global);
    global->display_battle = 0;
    global->camera_zoom = 0;
    init_types(global);
    init_sound(global);
    global->animation_battle = 0;
    load_music(global, "road_1");
    sfMusic_stop(global->music);
    init_ui(global);
}