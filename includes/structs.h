/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 17:23:55 by larlena           #+#    #+#             */
/*   Updated: 2021/03/12 15:42:52 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct			s_data
{
	void				*mlx;
	void				*mlx_win;
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_data;

typedef struct			s_cfg
{
	int					f_r;
	int					f_no;
	int					f_so;
	int					f_we;
	int					f_ea;
	int					f_s;
	int					f_f;
	int					f_c;
	int					res_x;
	int					res_y;
	int					scale;
	int					color_floor;
	int					color_ceilling;
	char				*texture_no;
	char				*texture_so;
	char				*texture_we;
	char				*texture_ea;
	char				*texture_sprite;
}						t_cfg;

typedef struct			s_player
{
	double				turn_speed;
	double				move_speed;
	double				x;
	double				y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
}						t_player;

typedef struct			s_ray
{
	double				camera;
	int					side;
	int					map_x;
	int					map_y;
	int					step_x;
	int					step_y;
	double				ray_dir_x;
	double				ray_dir_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_wall_dist;
	int					wall_height;
	double				*z_buffer;
}						t_ray;

typedef struct			s_texture
{
	t_data				data;
	char				*way_to_texture;
	void				*img_ptr;
	int					width;
	int					height;
	int					tex_x;
	int					tex_y;
	int					tex_start;
	int					tex_end;
	double				tex_pos;
	double				step;
	double				wall_x;
}						t_texture;

typedef struct			s_sprite
{
	float				x;
	float				y;
	int					distance;
}						t_sprite;

typedef struct			s_matrix
{
	double				sprite_screen_x;
	double				transform_x;
	double				transform_y;
	double				sprite_x;
	double				sprite_y;
	double				inv_det;
	int					sprite_height;
	int					sprite_width;
	int					draw_start_y;
	int					draw_end_y;
	int					draw_start_x;
	int					draw_end_x;
	int					d;
	int					color;
}						t_matrix;

typedef struct			s_all
{
	int					map_y;
	int					map_x;
	char				**map;
	t_ray				ray;
	t_cfg				cfg;
	t_data				data;
	t_list				*sprite;
	t_player			player;
	t_texture			texture[5];
}						t_all;

#endif
