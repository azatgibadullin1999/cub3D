/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:03:06 by larlena           #+#    #+#             */
/*   Updated: 2021/03/12 17:05:25 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	ft_initialisation_player(t_player *player, int y, int x, int diraction)
{
	player->x = (double)x + 0.5;
	player->y = (double)y + 0.5;
	player->move_speed = 0.1;
	player->turn_speed = 0.05;
	if (diraction == 'N')
		ft_filling_struct(player, 1);
	if (diraction == 'E')
		ft_filling_struct(player, 2);
	if (diraction == 'W')
		ft_filling_struct(player, 3);
	if (diraction == 'S')
		ft_filling_struct(player, 4);
}

t_list	*ft_maplen(t_list *start, int *line_num, int *line_size)
{
	t_list	*dst;
	int		i;
	int		f;

	f = 0;
	*line_num = 1;
	*line_size = 0;
	while (start)
	{
		i = -1;
		while (((char *)start->content)[++i])
		{
			if (!f && ft_isvalid(((char *)start->content)[i]))
			{
				dst = start;
				f += 1;
			}
		}
		if (f == 1)
			ft_sub_maplen(line_num, line_size, i);
		start = start->next;
	}
	return (dst);
}

char	**ft_mapdup(t_all *all)
{
	char	**dst;
	int		i;

	i = 0;
	if (!(dst = (char **)ft_calloc(sizeof(char *), all->map_y + 2)))
		ft_error_handling("Malloc error");
	while (i < all->map_y)
	{
		if (!(dst[i] = calloc(sizeof(char), all->map_x + 2)))
			ft_error_handling("Malloc error");
		ft_memcpy(dst[i], all->map[i], all->map_x + 1);
		i++;
	}
	if (!(dst[i] = calloc(sizeof(char), all->map_x + 2)))
		ft_error_handling("Malloc error");
	return (dst);
}

void	ft_validation_sprite(t_all *all, int y, int x)
{
	t_list	*tmp;

	if (!(tmp = ft_lstnew(malloc(sizeof(t_sprite)))) || !tmp->content)
		ft_error_handling("Malloc error");
	((t_sprite *)tmp->content)->y = y + 0.5;
	((t_sprite *)tmp->content)->x = x + 0.5;
	ft_lstadd_back(&all->sprite, tmp);
}

int		ft_flood_fill(t_all *all, char **map, int y, int x)
{
	if (ft_isvalid(map[y][x]) == 0)
		return (ERROR);
	else if (ft_isvalid(map[y][x]) == 1)
		return (0);
	else if (map[y][x] == '2')
		ft_validation_sprite(all, y, x);
	map[y][x] = '.';
	if (ft_flood_fill(all, map, y, x + 1))
		return (ERROR);
	if (ft_flood_fill(all, map, y + 1, x))
		return (ERROR);
	if (ft_flood_fill(all, map, y - 1, x))
		return (ERROR);
	if (ft_flood_fill(all, map, y, x - 1))
		return (ERROR);
	return (0);
}
