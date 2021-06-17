/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:40:33 by larlena           #+#    #+#             */
/*   Updated: 2021/03/12 17:07:51 by larlena          ###   ########.fr       */
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

void	ft_sub_maplen(int *line_num, int *line_size, int i)
{
	*line_num += 1;
	*line_size = i > *line_size ? i : *line_size;
	if (!i)
		ft_error_handling("Map error");
}

int		ft_isvalid(int c)
{
	if (c == '1' || c == '.')
		return (1);
	if (ft_isstartchar(c) || c == '0' || c == '2')
		return (2);
	return (0);
}

void	ft_filling_struct(t_player *player, int f)
{
	if (f == 1 || f == 4)
	{
		player->dir_x = 0;
		player->dir_y = f == 1 ? -1 : 1;
		player->plane_y = 0;
		player->plane_x = f == 1 ? 0.66 : -0.66;
	}
	else if (f == 2 || f == 3)
	{
		player->dir_x = f == 2 ? 1 : -1;
		player->dir_y = 0;
		player->plane_y = f == 2 ? 0.66 : -0.66;
		player->plane_x = 0;
	}
}
