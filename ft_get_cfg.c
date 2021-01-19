/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cfg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:41:12 by larlena           #+#    #+#             */
/*   Updated: 2021/01/19 16:21:21 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_check_identifier(char *str, t_all *all)
{
	if (!ft_strncmp(str, "R ", 2))
		return (ft_parsing_resolution(str, all, &all->cfg.f_r));
	if (!ft_strncmp(str, "NO ", 3))
		return (ft_parsing_texture(str, all, &all->cfg.f_no));
	if (!ft_strncmp(str, "SO ", 3))
		return (ft_parsing_texture(str, all, &all->cfg.f_so));
	if (!ft_strncmp(str, "WE ", 3))
		return (ft_parsing_texture(str, all, &all->cfg.f_we));
	if (!ft_strncmp(str, "EA ", 3))
		return (ft_parsing_texture(str, all, &all->cfg.f_ea));
	if (!ft_strncmp(str, "S ", 2))
		return (ft_parsing_texture(str, all, &all->cfg.f_s));
	if (!ft_strncmp(str, "F ", 2))
		return (ft_parsing_color(str, all, &all->cfg.f_f));
	if (!ft_strncmp(str, "C ", 2))
		return (ft_parsing_color(str, all, &all->cfg.f_c));
	return (0);
}

int		ft_cfg_parser(int fd, t_all *all)
{
	char	*str;
	int		f_cfg;

	f_cfg = 0;
	while (!f_cfg)
	{
		if (!get_next_line(fd, &str))
		{
			ft_putendl_fd("Error\nNot all parameters", 1);
			return (-1);
		}
		if (ft_check_identifier(str, all))
			return (-1);
		free(str);
		f_cfg = all->cfg.f_c && all->cfg.f_ea && all->cfg.f_f &&
				all->cfg.f_no && all->cfg.f_r && all->cfg.f_s &&
				all->cfg.f_so && all->cfg.f_we;
	}
	return (0);
}

void	ft_flags_to_zero(t_all *all)
{
	all->cfg.f_r = 0;
	all->cfg.f_c = 0;
	all->cfg.f_f = 0;
	all->cfg.f_s = 0;
	all->cfg.f_no = 0;
	all->cfg.f_ea = 0;
	all->cfg.f_so = 0;
	all->cfg.f_we = 0;
}

int		ft_get_cfg(const char *filename, t_all *all)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	ft_flags_to_zero(all);
	ft_cfg_parser(fd, all);
	return (0);
}