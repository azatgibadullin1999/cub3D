/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_resolution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:43:41 by larlena           #+#    #+#             */
/*   Updated: 2021/03/12 13:45:01 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	ft_check_size(t_cfg *cfg)
{
	if (cfg->res_x > 2560)
		cfg->res_x = 2560;
	if (cfg->res_y > 1440)
		cfg->res_y = 1440;
	if (cfg->res_x <= 0 || cfg->res_y <= 0)
		ft_error_handling("Wrong Resolution");
}

int		ft_parsing_resolution(const char *str, t_all *all, int *f_any)
{
	char	*tmp;
	size_t	i;

	i = 0;
	*f_any += 1;
	if (!(tmp = ft_strtrim(&str[2], " ")))
		ft_error_handling("Malloc error");
	all->cfg.res_x = ft_atoi(tmp);
	while (ft_isdigit(tmp[i]))
		i++;
	all->cfg.res_y = ft_atoi(&tmp[i]);
	while (tmp[i] == ' ')
		i++;
	while (ft_isdigit(tmp[i]))
		i++;
	if (tmp[i] != '\0')
		ft_error_handling("Wrong Resolution");
	free(tmp);
	all->cfg.scale = 10;
	if (!(all->ray.z_buffer = malloc(sizeof(double) * all->cfg.res_x)))
		ft_error_handling("Malloc error");
	ft_check_size(&all->cfg);
	return (0);
}
