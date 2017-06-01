##
## Makefile for make in /home/debrau_c/bin/new_repo
## 
## Made by debrau_c
## Login   <debrau_c@epitech.net>
## 
## Started on  Tue Jan 19 16:56:30 2016 debrau_c
## Last update Thu May  4 22:24:04 2017 debrau_c
##

NAME	= tekisland

SRC	= srcs/main.c			\
	  srcs/catch_debug_mode.c	\
	  srcs/my_string.c		\
	  srcs/my_string2.c		\
	  srcs/my_string3.c		\
	  srcs/tekpixel.c		\
	  srcs/load_bmp.c		\
	  srcs/my_bunny_fill.c		\
	  srcs/tekline.c		\
	  srcs/my_getnbr.c		\
	  srcs/zone_gest.c		\
	  srcs/my_alpha_blit.c		\
	  srcs/perso_gest.c		\
	  srcs/perso_gest_ext.c		\
	  srcs/init.c			\
	  srcs/init_ext.c		\
	  srcs/node_gest.c		\
	  srcs/change_zone.c		\
	  srcs/change_zone_ext.c	\
	  srcs/my_ini_ress.c		\
	  srcs/interface_gest.c		\
	  srcs/action_ouvrir.c		\
	  srcs/drawing.c		\
	  srcs/drawing_ext.c		\
	  srcs/mouse_set.c		\
	  srcs/action.c			\
	  srcs/tekzoom.c		\
	  srcs/my_get_float.c		\
	  srcs/tektext.c		\
	  srcs/message_game.c		\
	  srcs/message_game_ext.c	\
	  srcs/draw_player_ress.c	\
	  srcs/zone_load.c		\
	  srcs/zone_load_ext.c		\
	  srcs/editeur.c		\
	  srcs/edit_loops.c		\
	  srcs/edit_draw.c		\
	  srcs/edit_draw_ext.c		\
	  srcs/edit_init.c		\
	  srcs/edit_node_gest.c		\
	  srcs/edit_save_ini.c		\
	  srcs/my_itoa.c		\
	  srcs/edit_gest_menu.c		\
	  srcs/teksquare.c		\
	  srcs/my_realloc.c		\
	  srcs/edit_save_zone.c		\
	  srcs/edit_save_zone_ext.c	\
	  srcs/edit_loop_mouse.c	\
	  srcs/edit_gest_save.c

OBJ	= $(SRC:.c=.o)

RM	= rm -rf

CC	= gcc

FLAGS	= -I/home/$(USER)/.froot/include	\
	  -L/home/$(USER)/.froot/lib		\
	  -llapin				\
	  -lsfml-audio				\
	  -lsfml-graphics			\
	  -lsfml-window				\
	  -lsfml-system				\
	  -lstdc++				\
	  -ldl					\
	  -lm

CFLAGS	= -Iinc/	\

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FLAGS)

all:	$(NAME)

fclean:	clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJ)

re:	fclean all
