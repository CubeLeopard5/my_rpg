/*
** EPITECH PROJECT, 2020
** struct ui
** File description:
** struct_ui
*/

#include "SFML/Graphics.h"

#ifndef STRUCT_UI_H_
#define STRUCT_UI_H_
typedef struct settings_s settings_t;
typedef struct howtoplay_s howtoplay_t;
typedef struct button_s button_t;
typedef struct menu_s menu_t;
typedef void (*button_action_t)(menu_t *, button_t *); 
// func for menu actions

struct settings_s {
    int game_vol;
    int sound_vol;
    sfText **text;
    sfVector2f *pos_text;
    int text_count;
};

struct howtoplay_s {
    sfSprite *htp_bckgr;
    sfTexture *htp_bckgr_txture;
    sfSprite *htp_bckgr_2;
    sfTexture *htp_bckgr_txture_2;
    sfSprite *htp_bckgr_3;
    sfTexture *htp_bckgr_txture_3;
    int htp_state;
};

struct button_s {
    sfRectangleShape *shape;
    sfText *text;
    sfFont *font;
    sfColor button_color;
    sfColor hover_color;
    sfBool was_hovered;
    button_action_t on_hover;
    button_action_t on_leave;
    button_action_t on_click;
};

/*
struct button_s {
    sfRectangleShape *shape;  // button shape
    sfText *text;             // button text
    sfFont *font;             // button font
    sfColor button_color;     // button color
    sfColor hover_color;      // hover color
    sfBool was_hovered;         // was button hovered
    button_action_t on_hover; // function to call when hovering
    button_action_t on_leave; // function to call when no longer hovering
    button_action_t on_click; // function to call when clicking
};
*/

struct menu_s {
    sfTexture **textures;
    sfSprite **sprites;
    int button_count;
    int sprite_count;
    int texture_count;
    int user_choice;
    button_t **buttons;
    howtoplay_t howtoplay;
    settings_t settings;
    sfRenderWindow *window;
    sfVector2u window_size;
};

/*
struct menu_s {
    sfTexture **textures;      // textures for images to display
    sfSprite **sprites;        // sprites for images to display
    int button_count;          // button count
    int sprite_count;          // sprite count
    int texture_count;         // texture count
    int user_choice;           // user choice in the menu
    button_t **buttons;        // buttons
    howtoplay_t howtoplay;   // howtoplay
    settings_t settings;       // settings
    sfRenderWindow *window;    // render window
    sfVector2u window_size;    // render window size
};
*/

/* !STRUCT_UI_H_ */
#endif
