NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2
INCLUDES = -I./includes/ -I$(LX_DIR) -I$(LFT_DIR)
FUNC =		./srcs/cub3d.c\
			./srcs/hooks.c\
			./srcs/error_handling.c\
			./srcs/screenshot.c\
			./srcs/mlx_functions.c\
			./parser/ft_get_cfg.c\
			./parser/ft_parsing_color.c\
			./parser/ft_parsing_map_1.c\
			./parser/ft_parsing_map_2.c\
			./parser/ft_parsing_map_3.c\
			./parser/ft_parsing_resolution.c\
			./parser/ft_parsing_texture.c\
			./rendering/ft_render.c\
			./rendering/ft_render_map.c\
			./rendering/ft_render_sprite_1.c\
			./rendering/ft_render_sprite_2.c\
			./rendering/ft_render_wall.c\
			./rendering/raycasting.c\
			./get_next_line/get_next_line.c\

OBJ = $(FUNC:.c=.o)
LX_DIR = ./minilibx_opengl/
LXFLAGS = -L. -lmlx -framework OpenGL -framework AppKit
LFT_DIR = ./libft/
LFTFLAGS = -L$(LFT_DIR) -lft

.PHONY: all clean fclean re norme lft lmlx

all: $(OBJ_DIR) lmlx lft $(NAME)
	@echo "\033[32m[+] Make completed\033[0m"

$(NAME): $(OBJ)
	@$(CC)  $(OBJ) $(INCLUDES) $(LXFLAGS) $(LFTFLAGS) -lm -o $(NAME)

lmlx:
	@$(MAKE) -C $(LX_DIR) --silent
	@cp ./minilibx_opengl/libmlx.a ./includes/
	@echo  "\033[32m[+] Minilibx_mms builded\033[0m"

lft:
	@$(MAKE) -C $(LFT_DIR) --silent
	@$(MAKE) bonus -C $(LFT_DIR) --silent
	@echo  "\033[32m[+] Libft builded\033[0m"

$(OBJ): %.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f screenshot.bmp
	@rm -f libmlx.dylib

re: fclean all
