/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:55:32 by larlena           #+#    #+#             */
/*   Updated: 2021/01/21 17:56:21 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int			ft_parsing_color(const char *str, t_all *all, int *color, int *f_any)
{
	int		buff[3];
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	*f_any = 1;
	if (!(tmp = ft_strtrim(&str[1], " ")))
		return (ft_error_handling("Malloc error"));
	while (j < 3 && tmp[i])
	{
		buff[j] = atoi(&tmp[i]);
		while (ft_isdigit(tmp[i]))
			i++;
		i += tmp[i] == ',' ? 1 : 0;
		j++;
	}
	free(tmp);
	if (j < 3)
		return (ft_error_handling("Wrong color"));
	*color = create_trgb(0, buff[0], buff[1], buff[2]);
	return (0);
}
