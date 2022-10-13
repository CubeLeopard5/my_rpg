/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_howtoplay.c
*/

#include "minilib.h"
#include "scenes/menu.h"
#include "init.h"
#include "game_loop.h"
#include "free.h"
#include <time.h>
#include "scenes/menu.h"

void init_howtoplay(menu_t *menu)
{
    menu->howtoplay.htp_bckgr = sfSprite_create();
    menu->howtoplay.htp_bckgr_txture =
    sfTexture_createFromFile("assets/hwt/rpg_htw_1.png", NULL);
    sfSprite_setTexture(menu->howtoplay.htp_bckgr,
    menu->howtoplay.htp_bckgr_txture, sfTrue);
    menu->howtoplay.htp_bckgr_2 = sfSprite_create();
    menu->howtoplay.htp_bckgr_txture_2 =
    sfTexture_createFromFile("assets/hwt/mein_rpg_fight.png", NULL);
    sfSprite_setTexture(menu->howtoplay.htp_bckgr_2,
    menu->howtoplay.htp_bckgr_txture_2, sfTrue);
    menu->howtoplay.htp_bckgr_3 = sfSprite_create();
    menu->howtoplay.htp_bckgr_txture_3 =
    sfTexture_createFromFile("assets/hwt/mein_rpg_inventory.png", NULL);
    sfSprite_setTexture(menu->howtoplay.htp_bckgr_3,
    menu->howtoplay.htp_bckgr_txture_3, sfTrue);
    menu->howtoplay.htp_state = 0;
}

void destroy_howtoplay(menu_t *menu)
{
    sfTexture_destroy(menu->howtoplay.htp_bckgr_txture);
    sfSprite_destroy(menu->howtoplay.htp_bckgr);
    sfTexture_destroy(menu->howtoplay.htp_bckgr_txture_2);
    sfSprite_destroy(menu->howtoplay.htp_bckgr_2);
    sfTexture_destroy(menu->howtoplay.htp_bckgr_txture_3);
    sfSprite_destroy(menu->howtoplay.htp_bckgr_3);
}