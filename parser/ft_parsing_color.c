/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:55:32 by larlena           #+#    #+#             */
/*   Updated: 2021/03/12 15:37:38 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		ft_create_color(char **tmp)
{
	int		trgb[3];
	int		i;
	int		j;

	j = 0;
	while (tmp[j] != NULL && j <= 3)
	{
		i = 0;
		trgb[j] = ft_atoi(tmp[j]);
		while (ft_isdigit(tmp[j][i]))
			i++;
		if (!i || (trgb[j] > 255 || trgb[j] < 0))
			ft_error_handling("Wrong color");
		j++;
	}
	if (j != 3)
		ft_error_handling("wrong color");
	return (create_trgb(0, trgb[0], trgb[1], trgb[2]));
}

int		ft_parsing_color(const char *str, int *color, int *f_any)
{
	char	*buf;
	char	**tmp;

	*f_any += 1;
	if (!(buf = ft_strtrim(&str[1], " ")))
		ft_error_handling("Malloc error");
	if (!(tmp = ft_split(buf, ',')))
		ft_error_handling("Malloc error");
	free(buf);
	*color = ft_create_color(tmp);
	ft_del_array(tmp);
	return (0);
}
