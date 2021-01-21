/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:54:34 by larlena           #+#    #+#             */
/*   Updated: 2021/01/21 17:53:40 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_del_content(void *content)
{
	free(content);
}

static int		ft_get_map_in_list(t_list **start, int fd, t_all *all)
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

static int		ft_convert_list_to_array(t_list *start, char ***map)
{
	size_t	i;
	size_t	line_num;
	size_t	line_size;

	i = 0;
	line_num = ft_lstsize(start);
	if (!(*map = (char **)malloc(sizeof(char *) * (line_num + 1))))
		return (ft_error_handling("Malloc error"));
	while (i < line_num)
	{
		line_size = ft_strlen(start->content) + 1;
		(*map)[i] = malloc(sizeof(char) * (line_size));
		ft_strlcpy((*map)[i], start->content, line_size);
		start = start->next;
		i++;
	}
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
	return (0);
}
