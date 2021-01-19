/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_identifier.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:43:41 by larlena           #+#    #+#             */
/*   Updated: 2021/01/19 17:32:48 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_parsing_resolution(const char *str, t_all *all, int *f_any)
{
	char	*tmp;
	size_t	i;

	i = 0;
	*f_any = 1;
	tmp = ft_strtrim(&str[2], " ");
	all->cfg.res_x = ft_atoi(tmp);
	while (ft_isdigit(tmp[i]))
		i++;
	all->cfg.res_y = ft_atoi(&tmp[i]);
	while (tmp[i] == ' ')
		i++;
	while (ft_isdigit(tmp[i]))
		i++;
	if (tmp[i] != '\0')
	{
		ft_putendl_fd("Error\nWrong Resolution", 1);
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (0);
}

int		ft_parsing_texture(const char *str, t_all *all, int *f_any)
{
	int		fd;
	char	*tmp;

	*f_any = 1;
	tmp = ft_strtrim(&str[2], " ");
	if ((fd = open(tmp, O_RDONLY)) == -1)
	{
		ft_putendl_fd("Error\nWrong way", 1);
		free(tmp);
		return (-1);
	}
	close(fd);
	free(tmp);
	return (0);
}

int		ft_parsing_color(const char *str, t_all *all, int *f_any)
{
	int		color[3];
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	*f_any = 1;
	tmp = ft_strtrim(&str[1], " ");
	while (j < 3)
	{
		color[j] = atoi(&tmp[i]);
		while (ft_isdigit(tmp[i]))
			i++;
		i += tmp[i] == ',' ? 1 : 0;
		j++;
	}
	if (!tmp[i])

	return (0);
}