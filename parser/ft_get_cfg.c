/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cfg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:41:12 by larlena           #+#    #+#             */
/*   Updated: 2021/03/12 15:37:28 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_check_identifier(char *str, t_all *all)
{
	if (!ft_strncmp(str, "R ", 2))
		return (ft_parsing_resolution(str, all, &all->cfg.f_r));
	else if (!ft_strncmp(str, "NO ", 3))
		return (ft_parsing_texture(str, &all->cfg.f_no, &all->texture[0]));
	else if (!ft_strncmp(str, "SO ", 3))
		return (ft_parsing_texture(str, &all->cfg.f_so, &all->texture[1]));
	else if (!ft_strncmp(str, "WE ", 3))
		return (ft_parsing_texture(str, &all->cfg.f_we, &all->texture[2]));
	else if (!ft_strncmp(str, "EA ", 3))
		return (ft_parsing_texture(str, &all->cfg.f_ea, &all->texture[3]));
	else if (!ft_strncmp(str, "S ", 2))
		return (ft_parsing_texture(str, &all->cfg.f_s, &all->texture[4]));
	else if (!ft_strncmp(str, "F ", 2))
	{
		return (ft_parsing_color(str,
				&all->cfg.color_floor, &all->cfg.f_f));
	}
	else if (!ft_strncmp(str, "C ", 2))
	{
		return (ft_parsing_color(str,
				&all->cfg.color_ceilling, &all->cfg.f_c));
	}
	if (str[0])
		ft_error_handling("Invalid config file");
	return (0);
}

int		ft_cfg_parser(int fd, t_all *all, t_cfg *cfg)
{
	char	*str;
	int		f_cfg;

	f_cfg = 0;
	while (!f_cfg)
	{
		if (!get_next_line(fd, &str))
			ft_error_handling("Invalid config file");
		ft_check_identifier(str, all);
		free(str);
		if (cfg->f_c > 1 || cfg->f_ea > 1 || cfg->f_f > 1 || cfg->f_no > 1 ||
			cfg->f_r > 1 || cfg->f_s > 1 || cfg->f_so > 1 || cfg->f_we > 1)
			f_cfg = -1;
		else if (cfg->f_c && cfg->f_ea && cfg->f_f && cfg->f_no &&
				cfg->f_r && cfg->f_s && cfg->f_so && cfg->f_we)
			f_cfg = 1;
	}
	if (f_cfg == -1)
		ft_error_handling("Invalid config file");
	return (0);
}

void	ft_inicialisation_struct(t_all *all)
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

void	ft_validate_file_extension(const char *filename)
{
	int		i;

	i = -1;
	while (filename[++i] && filename[i] != '.')
		;
	if (ft_strncmp(&filename[i], ".cub", 5))
		ft_error_handling("File extension is bad");
}

int		ft_get_cfg(const char *filename, t_all *all)
{
	int		fd;

	ft_validate_file_extension(filename);
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_error_handling("File error");
	ft_inicialisation_struct(all);
	ft_cfg_parser(fd, all, &all->cfg);
	ft_parsing_map(fd, all);
	return (0);
}
