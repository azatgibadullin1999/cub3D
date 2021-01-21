/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:57:27 by larlena           #+#    #+#             */
/*   Updated: 2021/01/21 17:57:46 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int		ft_parsing_texture(const char *str, t_all *all, int *f_any)
{
	int		fd;
	char	*tmp;

	*f_any = 1;
	if (!(tmp = ft_strtrim(&str[2], " ")))
		return (ft_error_handling("Malloc error"));
	if ((fd = open(tmp, O_RDONLY)) == -1)
	{
		free(tmp);
		return (ft_error_handling("Wrong way"));
	}
	close(fd);
	free(tmp);
	return (0);
}
