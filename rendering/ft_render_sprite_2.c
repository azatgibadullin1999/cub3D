/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_sprite_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:32:10 by larlena           #+#    #+#             */
/*   Updated: 2021/03/12 15:38:04 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_calculate_matrix(t_all *all, t_list *sprite, t_matrix *matrix)
{
	matrix->sprite_x = ((t_sprite *)sprite->content)->x - all->player.x;
	matrix->sprite_y = ((t_sprite *)sprite->content)->y - all->player.y;
	matrix->inv_det = 1.0 / (all->player.plane_x * all->player.dir_y -
	all->player.dir_x * all->player.plane_y);
	matrix->transform_x = matrix->inv_det * (all->player.dir_y *
	matrix->sprite_x - all->player.dir_x * matrix->sprite_y);
	matrix->transform_y = matrix->inv_det * (-all->player.plane_y *
	matrix->sprite_x + all->player.plane_x * matrix->sprite_y);
	matrix->sprite_screen_x = (int)((all->cfg.res_x / 2) *
	(1 + matrix->transform_x / matrix->transform_y));
}

void	ft_calculate_hight_width(t_all *all, t_matrix *matrix)
{
	matrix->sprite_height = abs((int)(all->cfg.res_y / matrix->transform_y));
	matrix->draw_start_y = -matrix->sprite_height / 2 + all->cfg.res_y / 2;
	matrix->draw_start_y = matrix->draw_start_y < 0 ? 0 : matrix->draw_start_y;
	matrix->draw_end_y = matrix->sprite_height / 2 + all->cfg.res_y / 2;
	matrix->draw_end_y = matrix->draw_end_y >= all->cfg.res_y ?
	all->cfg.res_y - 1 : matrix->draw_end_y;
	matrix->sprite_width = abs((int)(all->cfg.res_y / matrix->transform_y));
	matrix->draw_start_x = -matrix->sprite_width / 2 + matrix->sprite_screen_x;
	matrix->draw_start_x = matrix->draw_start_x < 0 ? 0 : matrix->draw_start_x;
	matrix->draw_end_x = matrix->sprite_width / 2 + matrix->sprite_screen_x;
	matrix->draw_end_x = matrix->draw_end_x >= all->cfg.res_x ?
	all->cfg.res_x - 1 : matrix->draw_end_x;
}

void	ft_draw_sprite_norma(t_all *all, t_matrix *matrix, int y, int x)
{
	matrix->d = y * 256 - all->cfg.res_y * 128 +
	matrix->sprite_height * 128;
	all->texture[4].tex_y = ((matrix->d * all->texture[4].height) /
	matrix->sprite_height) / 256;
	my_mlx_get_pixel_color(&all->texture[4].data,
	all->texture[4].tex_y, all->texture[4].tex_x, &matrix->color);
	if ((matrix->color & 0x00FFFFFF) != 0)
		my_mlx_pixel_put(&all->data, y, x, matrix->color);
}

void	ft_draw_sprite(t_all *all, t_matrix *matrix)
{
	int		x;
	int		y;

	x = matrix->draw_start_x - 1;
	while (++x < matrix->draw_end_x)
	{
		all->texture[4].tex_x = (int)(256 *
		(x - (-matrix->sprite_width / 2 + matrix->sprite_screen_x)) *
		all->texture[4].width / matrix->sprite_width) / 256;
		if (matrix->transform_y > 0 && x > 0 && x < all->cfg.res_x &&
		matrix->transform_y < all->ray.z_buffer[x])
		{
			y = matrix->draw_start_y - 1;
			while (++y < matrix->draw_end_y)
			{
				ft_draw_sprite_norma(all, matrix, y, x);
			}
		}
	}
}

void	ft_transformation_to_matrix(t_all *all, t_list *sprite)
{
	t_matrix	matrix;

	ft_calculate_matrix(all, sprite, &matrix);
	ft_calculate_hight_width(all, &matrix);
	ft_draw_sprite(all, &matrix);
}
