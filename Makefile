NAME = cub3D

CFLAG = -Wall -Wextra -Werror

MLXFLAG = -lmlx -framework OpenGL -framework AppKit

SRC_PARS =	./parser/ft_get_cfg.c\
			./parser/ft_parsing_color.c\
			./parser/ft_parsing_map_1.c\
			./parser/ft_parsing_map_2.c\
			./parser/ft_parsing_map_3.c\
			./parser/ft_parsing_resolution.c\
			./parser/ft_parsing_texture.c

SRC_REND =	./rendering/ft_render_map.c\
			./rendering/ft_render.c\
			./rendering/raycasting.c
		
INCLUDES =	cub3D.h\
			parser.h\
			struct.h\
			libmlx.dylib\
			mlx.h

SRC_GNL =	./get_next_line/get_next_line.c

CFILES = $(SRC_GNL) $(SRC_PARS) $(SRC_REND)

OBJ = $(CFILES:.c=.o)



$(NAME):
	$(MAKE) all -C ./Libft/
	gcc $(CFLAG) $(MLXFLAG) -o $(CFILES) -I ./includes/cub3D.h ./Libft/libft.a

all: $(NAME) $(OBJ)

clean:
	rm $(OBJ)
	$(MAKE) clean -C ./Libft/

fclean: clean
	rm $(NAME)
	$(MAKE) fclean -C ./Libft/

re: fclean all
