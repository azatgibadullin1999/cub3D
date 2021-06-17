/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:14:04 by larlena           #+#    #+#             */
/*   Updated: 2021/03/12 17:18:38 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_get_texture(t_all *all)
{
	int		i;

	i = -1;
	while (++i < 5)
	{
		if (!(all->texture[i].data.img = mlx_xpm_file_to_image(all->data.mlx,
		all->texture[i].way_to_texture,
		&all->texture[i].width, &all->texture[i].height)))
			ft_error_handling("ti huesos");
		all->texture[i].data.addr = mlx_get_data_addr(all->texture[i].data.img,
		&all->texture[i].data.bits_per_pixel,
		&all->texture[i].data.line_length, &all->texture[i].data.endian);
		free(all->texture[i].way_to_texture);
	}
}

int		escape(void)
{
	exit(0);
}

int		main(int argc, char **argv)
{
	t_all	all;

	if (argc > 3)
		ft_error_handling("Too many arguments");
	if (argc < 2)
		ft_error_handling("No configuration file");
	ft_get_cfg(argv[1], &all);
	ft_get_mlx_params(&all.data, &all.cfg, argc);
	ft_get_texture(&all);
	ft_render(&all);
	if (argc == 3)
		ft_screenshot(&all, argv[2]);
	mlx_put_image_to_window(all.data.mlx, all.data.mlx_win, all.data.img, 0, 0);
	mlx_hook(all.data.mlx_win, 2, 1L << 2, ft_kay_hook, &all);
	mlx_hook(all.data.mlx_win, 17, 1L << 17, escape, NULL);
	mlx_loop(all.data.mlx);
	return (0);
}
