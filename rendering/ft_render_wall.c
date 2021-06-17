/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:59:45 by larlena           #+#    #+#             */
/*   Updated: 2021/03/12 15:38:08 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_drawing_wall(t_all *all, t_texture *texture, int x, int y)
{
	int		color;

	texture->tex_y = (int)texture->tex_pos & (texture->height - 1);
	my_mlx_get_pixel_color(&texture->data, texture->tex_y,
							texture->tex_x, &color);
	my_mlx_pixel_put(&all->data, y, x, color);
	texture->tex_pos += texture->step;
}

void	ft_get_wall_hight(t_ray *ray, t_cfg *cfg,
						int *draw_start, int *draw_end)
{
	ray->wall_height = (int)(cfg->res_y / ray->perp_wall_dist);
	*draw_start = -ray->wall_height / 2 + cfg->res_y / 2;
	*draw_end = ray->wall_height / 2 + cfg->res_y / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	if (*draw_end >= cfg->res_y)
		*draw_end = cfg->res_y - 1;
}

void	ft_calculate_tex_variables(t_all *all, t_texture *texture,
									int draw_start)
{
	if (all->ray.side == 0)
		texture->wall_x = all->player.y +
							all->ray.perp_wall_dist * all->ray.ray_dir_y;
	else
		texture->wall_x = all->player.x +
							all->ray.perp_wall_dist * all->ray.ray_dir_x;
	texture->wall_x -= floor(texture->wall_x);
	texture->tex_x = (int)(texture->wall_x * (double)texture->width);
	texture->step = 1.0 * texture->height / all->ray.wall_height;
	texture->tex_pos =
	(draw_start - all->cfg.res_y / 2 + all->ray.wall_height / 2) *
	texture->step;
}

void	ft_render_wall(t_all *all, t_texture *texture, int x)
{
	int		draw_start;
	int		draw_end;
	int		y;

	y = -1;
	ft_get_wall_hight(&all->ray, &all->cfg, &draw_start, &draw_end);
	ft_calculate_tex_variables(all, texture, draw_start);
	while (++y < all->cfg.res_y)
	{
		if (y >= draw_start && y <= draw_end)
			ft_drawing_wall(all, texture, x, y);
		else if (y < draw_start)
			my_mlx_pixel_put(&all->data, y, x, all->cfg.color_ceilling);
		else if (y > draw_end)
			my_mlx_pixel_put(&all->data, y, x, all->cfg.color_floor);
	}
}

void	ft_choice_wall(t_all *all, int x)
{
	if (all->ray.side == 0)
	{
		if (all->ray.ray_dir_x < 0)
			ft_render_wall(all, &all->texture[2], x);
		else
			ft_render_wall(all, &all->texture[3], x);
	}
	else
	{
		if (all->ray.ray_dir_y < 0)
			ft_render_wall(all, &all->texture[0], x);
		else
			ft_render_wall(all, &all->texture[1], x);
	}
}
