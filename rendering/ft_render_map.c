/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:02:56 by larlena           #+#    #+#             */
/*   Updated: 2021/02/04 21:27:28 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int		ft_print_square(t_all *all, int y, int x, int color)
{
	int		buff_x;
	int		max_y;
	int		max_x;

	buff_x = x;
	max_y = y + all->cfg.scale;
	while (max_y > ++y)
	{
		x = buff_x;
		max_x = x + all->cfg.scale;
		while (max_x > ++x)
		{
			my_mlx_pixel_put(&all->data, y, x, color);
		}
	}
	return (0);
}

int		ft_render_map(t_all *all)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (all->map_y > ++y)
	{
		x = 0;
		while (all->map_x >= ++x)
		{	
			if (all->map[y][x] == '1')
				ft_print_square(all, (y * all->cfg.scale), (x * all->cfg.scale), 0x00FFF000);
		}
	}
	ft_print_square(all, (all->player.y * all->cfg.scale), (all->player.x * all->cfg.scale), 0x00000FFF);
	return (0);
}