/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:00:27 by larlena           #+#    #+#             */
/*   Updated: 2021/03/12 16:27:16 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_move(t_player *player, char **map, double huita_x, double huita_y)
{
	player->y +=
	ft_isvalid(map[(int)(player->y + huita_y * player->move_speed)]
	[(int)player->x]) == 2 ? huita_y * player->move_speed : 0;
	player->x +=
	ft_isvalid(map[(int)player->y][(int)(player->x +
	huita_x * player->move_speed)]) == 2 ? huita_x * player->move_speed : 0;
}

void	ft_move_player(t_player *player, char **map, int kay_code)
{
	if (kay_code == W)
		ft_move(player, map, player->dir_x, player->dir_y);
	if (kay_code == S)
		ft_move(player, map, -player->dir_x, -player->dir_y);
	if (kay_code == D)
		ft_move(player, map, player->plane_x, player->plane_y);
	if (kay_code == A)
		ft_move(player, map, -player->plane_x, -player->plane_y);
}

void	ft_turn(t_player *player, double turn_speed)
{
	double	old_dir_y;
	double	old_plane_y;

	old_dir_y = player->dir_y;
	old_plane_y = player->plane_y;
	player->dir_y = old_dir_y * cos(turn_speed) -
	player->dir_x * sin(turn_speed);
	player->dir_x = old_dir_y * sin(turn_speed) +
	player->dir_x * cos(turn_speed);
	player->plane_y = old_plane_y * cos(turn_speed) -
	player->plane_x * sin(turn_speed);
	player->plane_x = old_plane_y * sin(turn_speed) +
	player->plane_x * cos(turn_speed);
}

void	ft_turn_player(t_player *player, int kay_code)
{
	if (kay_code == R_T)
		ft_turn(player, -player->turn_speed);
	else if (kay_code == L_T)
		ft_turn(player, player->turn_speed);
}

int		ft_kay_hook(int kay_code, t_all *all)
{
	if (kay_code == ESC)
		exit(0);
	else if (kay_code == W || kay_code == A || kay_code == S || kay_code == D)
		ft_move_player(&all->player, all->map, kay_code);
	else if (kay_code == R_T || kay_code == L_T)
		ft_turn_player(&all->player, kay_code);
	ft_render(all);
	mlx_put_image_to_window(all->data.mlx,
	all->data.mlx_win, all->data.img, 0, 0);
	return (0);
}
