/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:03:06 by larlena           #+#    #+#             */
/*   Updated: 2021/01/28 19:31:01 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

char	**ft_mapdup(char **map)
{
	char	**dst;
	size_t	line_num;
	size_t	line_size;
	size_t	i;

	i = 0;
	line_num = 0;
	while (map[line_num])
		line_num++;
	if (!(dst = (char **)ft_calloc(sizeof(char *), line_num + 1)))
		return (ERROR);
	while (i < line_num)
	{
		if (!(dst[i] = ft_strdup(map[i])))
		{
			dst[i] = NULL;
			ft_del_array(dst);
			return (ERROR);
		}
		i++;
	}
	return (dst);
}

int		ft_isvalid(int c)
{
	return (ft_isstartchar(c) || c == '0' || c == '2');
}

int		ft_iswrong(int c)
{
	return (!ft_isfreechar(c) || c != '1' || c != '.');
}

int		ft_food_fill(char **map, int y, int x)
{
	map[y][x] = '.';
	if (ft_iswrong(map[y][x + 1]) || (ft_isvalid(map[y][x + 1]) || ft_food_fill(map, y, x + 1)))
		return (ERROR);

}