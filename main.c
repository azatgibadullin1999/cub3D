/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:14:04 by larlena           #+#    #+#             */
/*   Updated: 2021/02/19 17:45:02 by larlena          ###   ########.fr       */
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

void	my_mlx_get_pixel_color(t_data *data, int y, int x, int *color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*color = *(unsigned int*)dst;
}

void	ft_get_texture(t_all *all)
{
	int		i;

	i = -1;
	while (++i < 5)
	{
		all->texture[i].data.img = mlx_xpm_file_to_image(all->data.mlx,
		all->texture[i].way_to_texture, &all->texture[i].width, &all->texture[i].height);
		all->texture[i].data.addr = mlx_get_data_addr(all->texture[i].data.img,
		&all->texture[i].data.bits_per_pixel, &all->texture[i].data.line_length, &all->texture[i].data.endian);
		free (all->texture[i].way_to_texture);
	}
}

int		main(int argc, char **argv)
{
	t_all	all;
	char	*tmp = "/Users/larlena/Documents/my_git/cub3D/cfg.cub";

	ft_get_cfg(tmp, &all);
	ft_get_mlx_params(&all.data);
	ft_get_texture(&all);
	ft_render_map(&all);
//	ft_putstr_fd("huita rabotaet!", 1);
//	mlx_put_image_to_window(all.data.mlx, all.data.mlx_win, all.data.img, 0, 0);
	mlx_hook(all.data.mlx_win, 2, 1L<<2, ft_kay_hook, &all);
	mlx_loop(all.data.mlx);
	return (0);
}
