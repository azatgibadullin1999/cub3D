/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:00:27 by larlena           #+#    #+#             */
/*   Updated: 2021/02/09 16:44:00 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void	ft_move_player(t_player *player, char **map, int kay_code)
{
	if (kay_code == W)
	{
		player->y += map[(int)(player->y + player->dir_y * player->move_speed)][(int)player->x] == '0' ? player->dir_y * player->move_speed : 0;
		player->x += map[(int)player->y][(int)(player->x + player->dir_x * player->move_speed)] == '0' ? player->dir_x * player->move_speed : 0;
	}
	if (kay_code == S)
	{
		player->y -= map[(int)(player->y - player->dir_y * player->move_speed)][(int)player->x] == '0' ? player->dir_y * player->move_speed : 0;
		player->x -= map[(int)player->y][(int)(player->x - player->dir_x * player->move_speed)] == '0' ? player->dir_x * player->move_speed : 0;
	}
	if (kay_code == A)
		NULL;
	if (kay_code == D)
		NULL;
}

int		ft_turn_player(t_player *player, int kay_code)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	if (kay_code == R_T)
	{
		player->dir_x = old_dir_x * cos(-player->turn_speed) - player->dir_y * sin(-player->turn_speed);
		player->dir_y = old_dir_x * sin(-player->turn_speed) + player->dir_x * cos(-player->turn_speed);
		player->plane_x = old_plane_x * cos(-player->turn_speed) - player->plane_y * sin(-player->turn_speed);
		player->plane_y = old_plane_x * sin(-player->turn_speed) - player->plane_y * cos(-player->turn_speed);
	}
	if (kay_code == R_T)
	{
		player->dir_x = old_dir_x * cos(player->turn_speed) - player->dir_y * sin(player->turn_speed);
		player->dir_y = old_dir_x * sin(player->turn_speed) + player->dir_x * cos(player->turn_speed);
		player->plane_x = old_plane_x * cos(player->turn_speed) - player->plane_y * sin(player->turn_speed);
		player->plane_y = old_plane_x * sin(player->turn_speed) - player->plane_y * cos(player->turn_speed);
	}
	return (0);
}

int		ft_kay_hook(int kay_code, t_all *all)
{
	if (kay_code == W || kay_code == A || kay_code == S || kay_code == D)
	{
		ft_move_player(&all->player, all->map, kay_code);
		ft_render_map(all);
	}
	if (kay_code == R_T || kay_code == L_T)
	{
		ft_turn_player(&all->player, kay_code);
	}
	if (kay_code == ESC)
		exit(0);
	return (0);
}
