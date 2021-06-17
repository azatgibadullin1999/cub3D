/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:57:27 by larlena           #+#    #+#             */
/*   Updated: 2021/03/12 15:37:43 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_parsing_texture(const char *str, int *f_any, t_texture *texture)
{
	int		fd;
	char	*filename;

	*f_any += 1;
	if (!(filename = ft_strtrim(&str[2], " ")))
		ft_error_handling("Malloc error");
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_error_handling("Wrong way");
	close(fd);
	texture->way_to_texture = filename;
	return (0);
}
