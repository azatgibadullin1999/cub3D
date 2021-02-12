/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_resolution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:43:41 by larlena           #+#    #+#             */
/*   Updated: 2021/02/12 16:01:51 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		ft_parsing_resolution(const char *str, t_all *all, int *f_any)
{
	char	*tmp;
	size_t	i;

	i = 0;
	*f_any = 1;
	if (!(tmp = ft_strtrim(&str[2], " ")))
		return (ft_error_handling("Malloc error"));
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
		free(tmp);
		return (ft_error_handling("Wrong Resolution"));
	}
	free(tmp);
	all->cfg.scale = 50;
	return (0);
}
