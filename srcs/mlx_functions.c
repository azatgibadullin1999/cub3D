/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:17:42 by larlena           #+#    #+#             */
/*   Updated: 2021/03/12 17:20:12 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_get_mlx_params(t_data *data, t_cfg *cfg, int flag)
{
	if (!(data->mlx = mlx_init()))
		ft_error_handling("mlx error");
	if (flag != 3)
	{
		data->mlx_win = mlx_new_window(data->mlx, cfg->res_x,
									cfg->res_y, "I love Russia!");
	}
	data->img = mlx_new_image(data->mlx, cfg->res_x, cfg->res_y);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
									&data->line_length, &data->endian);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int y, int x, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_get_pixel_color(t_data *data, int y, int x, int *color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*color = *(unsigned int*)dst;
}
