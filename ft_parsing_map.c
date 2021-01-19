/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:54:34 by larlena           #+#    #+#             */
/*   Updated: 2021/01/19 19:40:41 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_map_parser(int fd, t_all *all)
{
	t_list	*start;
	t_list	*tmp;
	char	*str;

	while (get_next_line(fd, &str))
	{
		tmp = ft_lstnew(str);
		ft_lstadd_back(&start, tmp);

	}
}