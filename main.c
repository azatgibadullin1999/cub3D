/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:14:04 by larlena           #+#    #+#             */
/*   Updated: 2021/02/12 15:45:00 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3D.h"

int		ft_get_mlx_params(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "I love Russia!");
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
								&data->endian);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int y, int x, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		main(int argc, char **argv)
{
	t_all	all;
	char	*tmp = "/Users/larlena/Documents/my_git/cub3D/cfg.cub";

	if (ft_get_cfg(tmp, &all))
		return (ERROR);
	ft_get_mlx_params(&all.data);
//	ft_render_map(&all);
	ft_putstr_fd("huita rabotaet!", 1);
	mlx_put_image_to_window(all.data.mlx, all.data.mlx_win, all.data.img, 0, 0);
	mlx_hook(all.data.mlx_win, 2, 1L<<2, ft_kay_hook, &all);
	mlx_loop(all.data.mlx);
	return (0);
}
