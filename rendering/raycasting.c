/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:11:31 by larlena           #+#    #+#             */
/*   Updated: 2021/03/12 15:38:16 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_calculation_of_direction_ray(t_ray *ray,
										t_player *player, t_cfg *cfg, int x)
{
	ray->map_x = player->x;
	ray->map_y = player->y;
	ray->camera = 2 * x / (double)cfg->res_x - 1;
	ray->ray_dir_x = player->dir_x + player->plane_x * ray->camera;
	ray->ray_dir_y = player->dir_y + player->plane_y * ray->camera;
	if (ray->ray_dir_y == 0)
		ray->delta_dist_x = 0;
	else if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_x == 0)
		ray->delta_dist_y = 0;
	else if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

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

void	ft_side_check(t_ray *ray, t_player *player, int side)
{
	if (side == 0)
		ray->perp_wall_dist = (ray->map_x - player->x +
								(1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - player->y +
								(1 - ray->step_y) / 2) / ray->ray_dir_y;
}

int		ft_raycastiong(t_all *all)
{
	int		hit;
	int		x;

	x = -1;
	while (++x < all->cfg.res_x)
	{
		hit = 0;
		ft_calculation_of_direction_ray(&all->ray, &all->player, &all->cfg, x);
		ft_calculation_of_side(&all->ray, &all->player);
		while (hit == 0)
		{
			ft_ray_iteration(&all->ray, &all->ray.side);
			if (all->map[all->ray.map_y][all->ray.map_x] == '1')
				hit = 1;
		}
		ft_side_check(&all->ray, &all->player, all->ray.side);
		all->ray.z_buffer[x] = all->ray.perp_wall_dist;
		ft_choice_wall(all, x);
	}
	return (0);
}
