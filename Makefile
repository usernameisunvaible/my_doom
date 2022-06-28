##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

NAME	=	my_doom
CFLAGS	+=	-g
FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system 



SRC	=	engine/sprite.c	\
		engine/sprite_infos.c	\
		engine/textures.c	\
		engine/my_strlen.c	\
		engine/time.c	\
		engine/define_rect.c	\
		engine/init.c	\
		engine/button.c	\
		engine/define_vector.c	\
		engine/button_infos.c	\
		engine/str_comp.c	\
		engine/slide_bar.c	\
		engine/slide_bar_infos.c	\
		engine/text.c	\
		engine/framebuffer.c	\
		engine/drawing.c	\
		engine/define_vertex.c	\
		engine/square.c	\
		engine/text_infos.c	\
		sources/main.c	\
		sources/read_map.c	\
		sources/get_textures.c	\
		sources/utils/ope.c	\
		sources/init_player.c	\


OBJ	=	$(SRC:.c=.o)


$(NAME):	$(OBJ)
	gcc $(OBJ) $(FLAGS) -o $(NAME)
	
all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
