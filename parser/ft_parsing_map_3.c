/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:40:33 by larlena           #+#    #+#             */
/*   Updated: 2021/02/11 15:46:42 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		ft_isstartchar(int c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	ft_del_array(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_del_content(void *content)
{
	free(content);
}

int		ft_isvalid(int c)
{
	if (c == '1' || c == '.')
		return (1);
	if (ft_isstartchar(c) || c == '0' || c == '2')
		return (2);
	return (0);
}

void	ft_initialisation_player(t_player *player, int y, int x, int diraction)
{
	player->x = (double)x;
	player->y = (double)y;
	player->plane_x = 0;
	player->plane_y = 0.66;
	player->move_speed = 0.05;
	player->turn_speed = 0.05;
	if (diraction == 'W')
		player->dir_x = 1;
		player->dir_y = 0;
	if (diraction == 'S')
		;
	if (diraction == 'N')
		;
	if (diraction == 'E')
		;
}