/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:00:27 by larlena           #+#    #+#             */
/*   Updated: 2021/02/12 20:24:46 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void	ft_move_player(t_player *player, char **map, int kay_code)
{
	if (kay_code == W)
	{
		player->y += ft_isvalid(map[(int)(player->y + player->dir_y * player->move_speed)][(int)player->x]) == 2 ? player->dir_y * player->move_speed : 0;
		player->x += ft_isvalid(map[(int)player->y][(int)(player->x + player->dir_x * player->move_speed)]) == 2 ? player->dir_x * player->move_speed : 0;
	}
	if (kay_code == S)
	{
		player->y -= ft_isvalid(map[(int)(player->y - player->dir_y * player->move_speed)][(int)player->x]) == 2 ? player->dir_y * player->move_speed : 0;
		player->x -= ft_isvalid(map[(int)player->y][(int)(player->x - player->dir_x * player->move_speed)]) == 2 ? player->dir_x * player->move_speed : 0;
	}
	if (kay_code == A)
		NULL;
	if (kay_code == D)
		NULL;
}

int		ft_turn_player(t_player *player, int kay_code)
{
	double	old_dir_y;
	double	old_plane_y;

	old_dir_y = player->dir_y;
	old_plane_y = player->plane_y;
	if (kay_code == R_T)
	{
		player->dir_y = old_dir_y * cos(-player->turn_speed) - player->dir_x * sin(-player->turn_speed);
		player->dir_x = old_dir_y * sin(-player->turn_speed) + player->dir_x * cos(-player->turn_speed);
		player->plane_y = old_plane_y * cos(-player->turn_speed) - player->plane_x * sin(-player->turn_speed);
		player->plane_x = old_plane_y * sin(-player->turn_speed) - player->plane_x * cos(-player->turn_speed);
	}
	else if (kay_code == L_T)
	{
		player->dir_y = old_dir_y * cos(player->turn_speed) - player->dir_x * sin(player->turn_speed);
		player->dir_x = old_dir_y * sin(player->turn_speed) + player->dir_x * cos(player->turn_speed);
		player->plane_y = old_plane_y * cos(player->turn_speed) - player->plane_x * sin(player->turn_speed);
		player->plane_x = old_plane_y * sin(player->turn_speed) - player->plane_x * cos(player->turn_speed);
	}
	return (0);
}

int		ft_kay_hook(int kay_code, t_all *all)
{
	if (kay_code == W || kay_code == A || kay_code == S || kay_code == D)
		ft_move_player(&all->player, all->map, kay_code);
	if (kay_code == R_T || kay_code == L_T)
		ft_turn_player(&all->player, kay_code);
	printf("%lf\n", all->player.x);
	printf("%lf\n", all->player.y);
	ft_render_map(all);
	ft_raycastiong(all->map, &all->cfg, &all->player, &all->ray);
	mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->data.img, 0, 0);
	if (kay_code == ESC)
		exit(0);
	return (0);
}
