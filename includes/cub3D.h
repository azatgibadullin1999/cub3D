/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:13:53 by larlena           #+#    #+#             */
/*   Updated: 2021/01/28 18:51:49 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../get_next_line/get_next_line.h"
# include "../Libft/libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define ERROR -1

typedef struct		s_data
{
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct		s_cfg
{
	int				f_r;
	int				f_no;
	int				f_so;
	int				f_we;
	int				f_ea;
	int				f_s;
	int				f_f;
	int				f_c;
	int				res_x;
	int				res_y;
	int				color_floor;
	int				color_ceilling;
	char			*texture_NO;
	char			*texture_SO;
	char			*texture_WE;
	char			*texture_EA;
	char			*texture_sprite;
}					t_cfg;

typedef struct		s_player
{
	double			x;
	double			y;
	char			direction;
}					t_player;

typedef struct		s_all
{
	char			**map;
	t_data			data;
	t_cfg			cfg;
	t_player		player;
}					t_all;

int			ft_get_cfg(const char *filename, t_all *all);
int			ft_cfg_parser(int fd, t_all *all);
int			ft_check_identifier(char *str, t_all *all);
int			ft_error_handling(char *str);

# include "parser.h"

#endif