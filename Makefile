##
## EPITECH PROJECT, 2019
## MUL_my_rpg_2019
## File description:
## Makefile
##

CC	=	gcc
INCLUDE	=	-I./include
LIBS	=	-lcsfml-graphics -lcsfml-audio -lcsfml-system

EXTRA_FLAGS	=	-g -Wno-unused
CFLAGS	=	-Wall -Wextra -pipe $(EXTRA_FLAGS)	\
			$(INCLUDE) $(LIBS)
CRITERION_FLAGS	=	$(CFLAGS) -lcriterion --coverage
LDFLAGS	=	$(LIBS)

MINILIB_SRC	=	minilib/my_atoi.c		\
				minilib/my_itoa.c		\
				minilib/my_printf.c		\
				minilib/my_putbase.c	\
				minilib/my_putchar.c	\
				minilib/my_putnbr.c		\
				minilib/my_putptr.c		\
				minilib/my_putstr.c		\
				minilib/my_revstr.c		\
				minilib/my_strsplit.c	\
				minilib/my_strcat.c		\
				minilib/my_strcmp.c		\
				minilib/my_strcpy.c		\
				minilib/my_strdup.c		\
				minilib/my_strlen.c		\
				minilib/my_strreplace.c	\
				minilib/my_strstr.c		\
				minilib/paths.c			\
				minilib/str_op.c		\
				minilib/sflib_f.c

CRITERION_SRC	=	tests/criterion_redirect.c	\
					tests/my_atoi_tests.c		\
					tests/my_itoa_tests.c		\
					tests/my_revstr_tests.c		\
					tests/my_printf_tests.c		\
					tests/my_putbase_tests.c	\
					tests/my_putstr_tests.c		\
					tests/my_putchar_tests.c	\
					tests/my_putnbr_tests.c		\
					tests/my_putptr_tests.c		\
					tests/my_strsplit_tests.c	\
					tests/my_strcmp_tests.c		\
					tests/my_strdup_tests.c		\
					tests/my_strstr_tests.c		\
					tests/my_strcat_tests.c		\
					tests/paths_tests.c			\
					tests/my_strreplace_tests.c	\
					tests/my_strcpy_tests.c

MINILIB_OBJ	=	$(MINILIB_SRC:.c=.o)

MAIN_SRC	=	src/main.c
SRC	=	src/engine/buttons/button_clicked.c			\
		src/engine/buttons/button_create.c			\
		src/engine/buttons/button_destroy.c			\
		src/engine/buttons/button_position.c		\
		src/engine/buttons/button_render.c			\
		src/engine/buttons/button_set_color.c		\
		src/engine/buttons/button_set_text.c		\
		src/engine/sprites/move_sprite.c			\
		src/engine/window.c							\
		src/engine/time.c							\
		src/engine/get_pos_in_inventory.c			\
		src/engine/add_object_inv.c					\
		src/engine/get_tile_from_pos.c				\
		src/engine/conversion.c						\
		src/scenes/menu/event_handler.c				\
		src/scenes/menu/events.c					\
		src/scenes/menu/init.c						\
		src/scenes/menu/init_2.c					\
		src/scenes/menu/rendering.c					\
		src/scenes/menu/scene.c						\
		src/scenes/settings/menu_settings.c			\
		src/scenes/settings/init_settings.c			\
		src/scenes/settings/render_settings.c		\
		src/scenes/settings/event_settings.c		\
		src/scenes/settings/settings_init_buttons.c	\
		src/scenes/settings/go_menu.c				\
		src/scenes/settings/event_resize.c			\
		src/init/init_structs.c						\
		src/init/init_environnement.c				\
		src/init/init_player.c						\
		src/init/init_this_sprite.c					\
		src/init/init_inputs.c						\
		src/init/init_sprite_sheet.c				\
		src/init/init_rect_sprite_sheet.c			\
		src/init/init_time.c						\
		src/init/init_sprite_ui.c					\
		src/init/init_button_ui.c					\
		src/init/init_button_pause.c				\
		src/init/init_text_pause.c					\
		src/init/init_button_battle.c				\
		src/init/init_rect_player.c                 \
		src/init/init_background_battle.c			\
		src/init/init_attacks.c						\
		src/init/init_entities.c					\
		src/init/init_types.c						\
		src/init/init_sound.c						\
		src/init/init_this_sound.c					\
		src/init/init_text_stat.c					\
		src/utilities/malloc_str_cat.c				\
		src/utilities/string_to_int.c				\
		src/utilities/my_nbr_to_str.c				\
		src/map/switch_place.c						\
		src/map/parser.c							\
		src/map/parser_static.c						\
		src/map/load_npc.c							\
		src/display/display.c						\
		src/display/display_map.c					\
		src/display/display_ui.c					\
		src/display/display_pause.c					\
		src/display/display_battle.c				\
		src/display/set_pause_menu.c				\
		src/display/set_battle_menu.c				\
		src/display/set_text_stat.c					\
		src/display/set_pokemon_player.c			\
		src/display/display_entities.c				\
		src/game_loop/game_loop.c					\
		src/game_loop/manage_events.c				\
		src/game_loop/manage_inputs.c				\
		src/game_loop/manage_camera.c				\
		src/game_loop/game_scenes.c					\
		src/game_loop/entity_events.c				\
		src/game_loop/player_collision.c			\
		src/game_loop/manage_place.c				\
		src/game_loop/camer_zoom.c					\
		src/create_char/create_char.c				\
		src/create_char/my_str_event_is_validated.c	\
		src/create_char/finish_char.c				\
		src/battle/init_pokehuman.c					\
		src/battle/battle.c							\
		src/battle/init_text_atk.c					\
		src/battle/init_text_winlose.c				\
		src/battle/put_atk_msg.c					\
		src/entity_t/init.c							\
		src/intro/intro.c							\
		src/intro/init_intro.c						\
		src/intro/intro_steps.c						\
		src/intro/intro_events.c					\
		src/free/free_struct.c 						\
		src/free/free_sound.c						\
		src/free/free_environnement.c				\
		src/how_to_play/display_howtoplay.c			\
		src/how_to_play/init_howtoplay.c			\
		src/animation/advanced_particle.c			\
		src/animation/animation_destroy.c			\
		src/animation/animation.c					\
		src/animation/particle.c					\
		src/animation/scalination.c					\
		src/animation/bubble_text.c					\
		src/animation/bubble_text_tweaks.c			\
		src/animation/bubble_text_big.c				\
		src/animation/bubble_text_big_tweaks.c		\
		src/music/battle_music.c					\
		src/music/map_music.c						\
		src/music/menu_music.c						\
		src/animation/rain_snow.c					\
		src/entity_t/entity_action.c				\
		src/battle/poke_level_up.c					\
		src/music/load_music.c						\
		src/outro/outro.c							\
		src/outro/outro_steps.c						\



MINILIB_OBJ	=	$(MINILIB_SRC:.c=.o)

OBJ	=	$(SRC:.c=.o)	\
		$(MAIN_SRC:.c=.o)

BINARY_NAME	=	my_rpg

all:	$(BINARY_NAME)

$(BINARY_NAME):	$(MINILIB_OBJ) $(OBJ)
	$(CC) -o $(BINARY_NAME) $(MINILIB_OBJ) $(OBJ) $(LDFLAGS)

tests_run:	clean
	@$(CC) -o unit_tests $(MINILIB_SRC) $(SRC) $(CRITERION_SRC)	\
	 $(CRITERION_FLAGS)
	@./unit_tests
	@gcovr --exclude tests
	@gcovr --exclude tests --branches

clean:
	@rm -f *.gcno *.gcda vgcore.*

fclean:	clean
	@rm -f $(MINILIB_OBJ) $(OBJ) unit_tests $(BINARY_NAME)

re:	fclean	all
