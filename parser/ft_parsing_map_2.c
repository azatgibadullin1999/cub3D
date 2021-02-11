/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:03:06 by larlena           #+#    #+#             */
/*   Updated: 2021/02/05 19:09:48 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

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
		while (start->content[++i])
		{
			if (!f && ft_isvalid(start->content[i]))
			{
				dst = start;
				f = 1;
			}
		}
		if (f == 1)
		{
			*line_num += 1;
			*line_size = *line_size < i ? i : *line_size;
		}
		start = start->next;
	}
	return (dst);
}

char	**ft_mapdup(t_all *all)
{
	char	**dst;
	size_t	i;

	i = 0;
	if (!(dst = (char **)ft_calloc(sizeof(char *), all->map_y + 2)))
		return (NULL);
	while (i < all->map_y)
	{
		if (!(dst[i] = calloc(sizeof(char), all->map_x + 2)))
		{
			dst[i] = NULL;
			ft_del_array(dst);
			return (NULL);
		}
		ft_memcpy(dst[i], all->map[i], all->map_x + 1);
		i++;
	}
	return (dst);
}

int		ft_flood_fill(char **map, int y, int x)
{
	if (ft_isvalid(map[y][x]) == 0)
		return (ERROR);
	if (ft_isvalid(map[y][x]) == 1)
		return (0);
	map[y][x] = '.';
	if (ft_flood_fill(map, y, x + 1))
		return (ERROR);
	if (ft_flood_fill(map, y + 1, x))
		return (ERROR);
	if (ft_flood_fill(map, y - 1, x))
		return (ERROR);
	if (ft_flood_fill(map, y, x - 1))
		return (ERROR);
	return (0);
}
