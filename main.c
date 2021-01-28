/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:14:04 by larlena           #+#    #+#             */
/*   Updated: 2021/01/28 18:13:26 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3D.h"

void	ft_printmap(char **map)
{
	size_t	i;

	i = 0;
	ft_putendl_fd("/", 1);
	while (map[i])
	{
		ft_putendl_fd(map[i], 1);
		i++;
	}
	ft_putendl_fd("/", 1);
}

int		main(int argc, char **argv)
{
	t_all	all;
	char	*tmp = "/Users/larlena/Documents/my_git/cub3D/cfg.cub";

	if (ft_get_cfg(tmp, &all))
		return (ERROR);

	// all.data.mlx = mlx_init();
	// all.data.mlx_win = mlx_new_window(all.data.mlx, 1920, 1080, "I love Russia!");
	// all.data.img = mlx_new_image(all.data.mlx, 1920, 1080);
	// all.data.addr = mlx_get_data_addr(all.data.img, &all.data.bits_per_pixel, &all.data.line_length,
	// 							&all.data.endian);
	// mlx_loop(all.data.mlx);
	// mlx_hook()
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

	// while (x < 100)
	// {
	// 	y = y_buf;
	// 	while (y < 200)
	// 	{
	// 		my_mlx_pixel_put(&img, x, y, 0x00FFF000);
	// 		y++;
	// 	}
	// 	x++;
	// }
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);