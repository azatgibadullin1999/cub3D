/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 17:23:55 by larlena           #+#    #+#             */
/*   Updated: 2021/02/12 17:29:05 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
	int				scale;
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
	double			turn_speed;
	double			move_speed;
	double			x;
	double			y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}					t_player;

typedef struct		s_ray
{
	double			camera;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				wall_height;
}					t_ray;

typedef struct		s_all
{
	int				map_y;
	int				map_x;
	char			**map;
	t_data			data;
	t_cfg			cfg;
	t_player		player;
	t_ray			ray;
}					t_all;

#endif