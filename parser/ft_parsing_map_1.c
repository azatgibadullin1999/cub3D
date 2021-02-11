/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:54:34 by larlena           #+#    #+#             */
/*   Updated: 2021/02/11 17:49:02 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		ft_convert_list_to_array(t_list *map, t_all *all)
{
	size_t	i;
	t_list	*start;

	i = 0;
	start = NULL;
	start = ft_maplen(map, &all->map_y, &all->map_x);
	if (!(all->map = (char **)calloc(sizeof(char *), all->map_y + 2)))
		return (ft_error_handling("Malloc error"));
	while (i < all->map_y)
	{
		if (!(all->map[i] = calloc(sizeof(char), all->map_x + 2)))
		{
			ft_del_array(all->map);
			return (ft_error_handling("Malloc Error"));
		}
		if (i >= 1 && i <= all->map_y)
		{
			ft_strlcpy(&all->map[i][1], start->content,
			ft_strlen(start->content) + 1);
			start = start->next;
		}
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
	if (!(tmp = ft_lstnew(str)))
	{
		ft_lstclear(start, ft_del_content);
		return (ft_error_handling("Malloc error"));
	}
	ft_lstadd_back(start, tmp);
	return (0);
}

int		ft_get_starting_point(t_all *all)
{
	int		y;
	int		x;
	int		f_start;

	y = 0;
	f_start = 0;
	while (all->map[++y])
	{
		x = 0;
		while (all->map[y][++x])
		{
			if (ft_isstartchar(all->map[y][x]) == 1)
			{
				ft_initialisation_player(&all->player, y, x, all->map[y][x]);
				all->map[y][x] = '0';
				f_start += 1;
			}
		}
	}
	if (f_start != 1)
		return (ft_error_handling("Wrong map"));
	return (0);
}

int		ft_map_validation(t_all *all)
{
	char	**tmp;

	if (!(tmp = ft_mapdup(all)))
	{
		ft_del_array(tmp);
		return (ft_error_handling("Malloc error"));
	}
	if (ft_flood_fill(tmp, (int)all->player.y, (int)all->player.x))
	{
		ft_del_array(tmp);
		return (ft_error_handling("Wrong map"));
	}
	ft_del_array(tmp);
	return (0);
}

int		ft_parsing_map(int fd, t_all *all)
{
	t_list	*start;

	start = NULL;
	if (ft_get_map_in_list(&start, fd, all))
		return (ERROR);
	if (ft_convert_list_to_array(start, all))
	{
		ft_lstclear(&start, ft_del_content);
		return (ERROR);
	}
	ft_lstclear(&start, ft_del_content);
	if (ft_get_starting_point(all) || ft_map_validation(all))
	{
		ft_del_array(all->map);
		return (ERROR);
	}
	return (0);
}
