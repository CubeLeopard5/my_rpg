/*
** EPITECH PROJECT, 2020
** function.h
** File description:
** rpg
*/

#include "SFML/Graphics.h"
#include "struct.h"

/*create_char */
int create_perso(global_t *global);

void check_what_is_it(global_t *global, int x, int y);

sfVector2f get_pos_in_inventory(global_t *gloabl, int nb);

void display(global_t *global);
void display_map(global_t *global);
void display_pause(global_t *global);
void display_ui(global_t *global);

int game_loop(global_t *global);

void init_button_pause(global_t *global);
void init_button_ui(global_t *global);
void init_environnement(global_t *global);
void init_game_menu(global_t *global);
void init_input(inputs_t *inputs);
void init_my_rect(global_t *global);
void init_player(player_t *player, global_t *global);
void init_rect_player(global_t *global);
void init_sprite_sheet(global_t *global);
void init_sprite_ui(global_t *global);
void init_structs (global_t *global);
void init_text_lp(global_t *global);
void init_text_pause(global_t *global);
void init_time(my_time_t *time);
sfSprite *init_this_sprite(char *path, global_t *global);


place_t *load_place(global_t *global, char *name);
int main_menu(global_t *global);
char *malloc_strcat(char *a, char *b);
void move_rect(global_t *global, int face, sfSprite *sprite);
void move_rect_player(global_t *global, int face, int line, sfSprite *sprite);
char *int_to_string(int i);


/*game loop*/
void display_ui(global_t *global);
void display_pause(global_t *global);
void game_scene_map(global_t *global);
void game_scene_inv(global_t *global);
void game_scene_pause(global_t *global);
void game_scene_battle(int i, global_t *global);
void game_scene_final(global_t *global);
void manage_camera(global_t *global);
void manage_display_battle(global_t *global);
void manage_display_inv(global_t *global);
void manage_display_pause(global_t *global);
void manage_display_ui(global_t *global);
void manage_inputs(global_t *global, sfKeyCode input);
void move_player_up(global_t *global);

/*utilites*/
int compare_time(sfClock *clock, float *balise, float delay);
void dezoom_camera(global_t *global);
void add_object_inv(global_t *global, char *name, int id, const char *texture);
void remove_object_inv(global_t *global, char *name);
void poke_level_up(pokehuman_t *poke);
void set_pokemon_player(global_t *global);
void set_new_stat(global_t *global);
char *my_nbr_to_str(int i);

/*init this sprite*/
sfSprite *set_sprite_center_to_center(sfSprite *sprite);
/*init this sprite*/

/*battle*/
void display_battle(pokehuman_t *a, pokehuman_t *b, global_t *global, int i);
void display_battle_elements(pokehuman_t *a, pokehuman_t *b, global_t *global);
void event_battle(global_t *global);
pokehuman_t init_pokehuman(global_t *global, char *name, int level);
void init_button_battle(global_t *global);
void init_background_battle(global_t *global);
void prepare_battle(int *i, global_t *global);
void set_battle_menu(pokehuman_t *a, pokehuman_t *b, global_t *global);
void set_pause_menu(global_t *global);
sfVector2f init_pos_win(global_t *global);
sfText *init_text_win(void);
sfText *init_text_lose(void);
void put_attack_msg(global_t *global, pokehuman_t *attacker,
pokehuman_t *defender);
