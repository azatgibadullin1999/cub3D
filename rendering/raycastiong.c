/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastiong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:11:31 by larlena           #+#    #+#             */
/*   Updated: 2021/02/11 14:59:47 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_computation_of_direction_ray(t_ray *ray, t_player *player, int res_x, int i)
{
	player->camera = 2 * i / res_x - 1;
	ray->ray_dir_x = player->dir_x + player->plane_x * player->camera;
	ray->ray_dir_y = player->dir_y + player->plane_y * player->camera;
	ray->delta_dist_x = sqrt(1 + (ray->ray_dir_y * ray->ray_dir_y) / (ray->ray_dir_x * ray->ray_dir_x));
	ray->delta_dist_y = sqrt(1 + (ray->ray_dir_x * ray->ray_dir_x) / (ray->ray_dir_y * ray->ray_dir_y));
}

void	ft_computation_of_side(t_ray *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->y) * ray->delta_dist_y;
	}
}

void	ft_ray_iteration(t_ray *ray, int *side)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->side_dist_x;
		ray->map_x += ray->step_x;
		*side = 0;
	}
	else
	{
		ray->side_dist_y += ray->side_dist_y;
		ray->map_y += ray->step_y;
		*side = 1;
	}
}

void	ft_render(t_all *all, int x)
{
	int		y;
	int		line_height;
	int		draw_start;
	int		draw_end;

	y = -1;
	line_height = all->cfg.res_y * all->ray.perp_wall_dist;
	if (0 > (draw_start = -line_height / 2 - all->cfg.res_y / 2))
		draw_start = 0;
	if (all->cfg.res_y >= (draw_end = line_height / 2 + all->cfg.res_y / 2))
		draw_end = all->cfg.res_y - 1;
	while(all->cfg.res_y > ++y)
	{
		if (y >= draw_start && y <= draw_end)
			my_mlx_pixel_put(&all->data, y, x, 0x000000FF);
		else
			my_mlx_pixel_put(&all->data, y, x, 0x00FF0000);
	}
}

int		ft_raycastiong(t_all *all)
{
	int		x;
	int		side;
	int		hit;
	
	x = -1;
	while (all->cfg.res_x > ++x)
	{
		hit = 0;
		ft_computation_of_direction_ray(&all->ray, &all->player, all->cfg.res_x, x);
		ft_computation_of_side(&all->ray, &all->player);
		while (!hit)
		{
			ft_ray_iteration(&all->ray, &side);
			hit = all->map[all->ray.map_x][all->ray.map_y] > 0 ? 1 : 0;
		}
		all->ray.perp_wall_dist = !side ?
		(all->ray.map_x - all->player.x + (1 - all->ray.step_x) / 2) / all->ray.ray_dir_x :
		(all->ray.map_y - all->player.y + (1 - all->ray.step_y) / 2) / all->ray.ray_dir_y;
		ft_render(all, x);
	}
	return (0);
}