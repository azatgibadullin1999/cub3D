/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastiong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:11:31 by larlena           #+#    #+#             */
/*   Updated: 2021/02/12 20:26:24 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_computation_of_direction_ray(t_ray *ray, t_player *player, int res_x, double i)
{

}

// sqrt(1 + (ray->ray_dir_y * ray->ray_dir_y) / (ray->ray_dir_x * ray->ray_dir_x))
// sqrt(1 + (ray->ray_dir_x * ray->ray_dir_x) / (ray->ray_dir_y * ray->ray_dir_y))

void	ft_calculation_of_side(t_ray *ray, t_player *player)
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
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->y) * ray->delta_dist_y;
	}
}

void	ft_ray_iteration(t_ray *ray, int *side)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		*side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		*side = 1;
	}
}

void	ft_render(t_all *all, int x)
{

}

int		ft_raycastiong(char **map, t_cfg *cfg, t_player *player, t_ray *ray)
{
	int		side;
	int		hit;
	int		x;

	x = -1;
	while (++x < cfg->res_x)
	{
		hit = 0;
		ray->map_x = player->x;
		ray->map_y = player->y;
		ray->camera = 2 * x / (double)cfg->res_x - 1;
		ray->ray_dir_x = player->dir_x + player->plane_x * ray->camera;
		ray->ray_dir_y = player->dir_y + player->plane_y * ray->camera;
		ray->delta_dist_x = ray->ray_dir_y == 0 ? 0 : (ray->ray_dir_x == 0 ? 1 : fabs(1 / ray->ray_dir_x));
		ray->delta_dist_y = ray->ray_dir_x == 0 ? 0 : (ray->ray_dir_y == 0 ? 1 : fabs(1 / ray->ray_dir_y));
		ft_calculation_of_side(ray, player);
		while (hit == 0)
		{
			ft_ray_iteration(ray, &side);
			if (map[ray->map_y][ray->map_x] != '0')
				hit = 1;
		}
	}
	return (0);
}