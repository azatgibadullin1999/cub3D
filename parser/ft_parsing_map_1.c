/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:54:34 by larlena           #+#    #+#             */
/*   Updated: 2021/01/28 18:57:34 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include <stdio.h>

int		ft_convert_list_to_array(t_list *start, char ***map)
{
	size_t	i;
	size_t	line_num;
	size_t	line_size;

	i = 0;
	line_num = ft_lstsize(start);
	if (!(*map = (char **)malloc(sizeof(char *) * (line_num + 1))))
		return (ft_error_handling("Malloc error"));
	(*map)[line_num] = NULL;
	while (i < line_num)
	{
		line_size = ft_strlen(start->content) + 1;
		if (!((*map)[i] = malloc(sizeof(char) * (line_size))))
		{
			ft_del_array(*map);
			return (ft_error_handling("Malloc Error"));
		}
		ft_strlcpy((*map)[i], start->content, line_size);
		start = start->next;
		i++;
	}
	return (0);
}

int		ft_get_map_in_list(t_list **start, int fd, t_all *all)
{
	t_list	*tmp;
	char	*str;

	while (get_next_line(fd, &str))
	{
		if (!(tmp = ft_lstnew(str)))
		{
			ft_lstclear(start, ft_del_content);
			return (ft_error_handling("Malloc error"));
		}
		ft_lstadd_back(start, tmp);
	}
	return (0);
}

int		ft_get_starting_point(char **map, t_all *all)
{
	int		y;
	int		x;
	int		f_start;

	y = -1;
	f_start = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_isstartchar(map[y][x]) == 1)
			{
				all->player.y = (double)y;
				all->player.x = (double)x;
				all->player.direction = map[y][x];
				f_start += 1;
			}
		}
	}
	if (f_start != 1)
		return (ft_error_handling("Wrong map"));
	return (0);
}

int		ft_map_validation(char **map, t_all *all)
{
	char	**tmp;

	if (!(tmp = ft_mapdup(map)))
		return (ft_error_handling("Malloc error"));
	if (ft_flood_fill(tmp, (int)all->player.y, (int)all->player.x))
	{
		free (tmp);
		return (ft_error_handling("Wrong map"));
	}
	free(tmp);
	return (0);
}

int		ft_parsing_map(int fd, t_all *all)
{
	t_list	*start;
	char	**map;

	start = NULL;
	if (ft_get_map_in_list(&start, fd, all))
		return (ERROR);
	if (ft_convert_list_to_array(start, &map))
	{
		ft_lstclear(&start, ft_del_content);
		return (ERROR);
	}
	ft_lstclear(&start, ft_del_content);
	if (ft_get_starting_point(map, all) || ft_map_validation(map, all))
	{
		ft_del_array(map);
		return (ERROR);
	}
	all->map = map;
	return (0);
}
