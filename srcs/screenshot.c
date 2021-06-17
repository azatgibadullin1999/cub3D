/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:01:35 by larlena           #+#    #+#             */
/*   Updated: 2021/03/12 16:36:21 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		make_header(unsigned char *bmp_fheader, unsigned char
	*bmpinfheader, t_all *all)
{
	int file_size;

	file_size = 14 + 40 + all->cfg.res_y * all->cfg.res_x
		* all->data.bits_per_pixel / 8;
	bmp_fheader[0] = 'B';
	bmp_fheader[1] = 'M';
	bmp_fheader[2] = (unsigned char)(file_size);
	bmp_fheader[3] = (unsigned char)(file_size >> 8);
	bmp_fheader[4] = (unsigned char)(file_size >> 16);
	bmp_fheader[5] = (unsigned char)(file_size >> 24);
	bmp_fheader[10] = (unsigned char)(14 + 40);
	bmpinfheader[0] = (unsigned char)(40);
	bmpinfheader[4] = (unsigned char)(all->cfg.res_x);
	bmpinfheader[5] = (unsigned char)(all->cfg.res_x >> 8);
	bmpinfheader[6] = (unsigned char)(all->cfg.res_x >> 16);
	bmpinfheader[7] = (unsigned char)(all->cfg.res_x >> 24);
	bmpinfheader[8] = (unsigned char)(-all->cfg.res_y);
	bmpinfheader[9] = (unsigned char)(-all->cfg.res_y >> 8);
	bmpinfheader[10] = (unsigned char)(-all->cfg.res_y >> 16);
	bmpinfheader[11] = (unsigned char)(-all->cfg.res_y >> 24);
	bmpinfheader[12] = (unsigned char)(1);
	bmpinfheader[14] = (unsigned char)(all->data.bits_per_pixel);
	return (1);
}

int		write_in_header(unsigned char *bmp_fheader,
				unsigned char *bmpinfheader, t_all *all)
{
	int		fd;
	char	*filename;
	int		len;
	int		i;

	i = -1;
	filename = "screenshot.bmp";
	if ((fd = open(filename, O_RDWR | O_CREAT, 0755)) < 0)
		ft_error_handling("Can't open file");
	write(fd, bmp_fheader, 14);
	write(fd, bmpinfheader, 40);
	len = all->data.bits_per_pixel / 8 * all->cfg.res_x;
	while (++i < all->cfg.res_y)
		write(fd, all->data.addr + i * all->data.line_length, len);
	if (close(fd < 0))
	{
		ft_putstr_fd("Close file error!\n", 0);
		return (0);
	}
	return (1);
}

int		ft_screenshot(t_all *all, char *flag)
{
	unsigned char	bmp_fheader[14];
	unsigned char	bmpinfheader[40];

	if (ft_strncmp(flag, "--save\0", 7))
		ft_error_handling("Bad flag");
	ft_bzero(bmp_fheader, 14);
	ft_bzero(bmpinfheader, 40);
	make_header(bmp_fheader, bmpinfheader, all);
	write_in_header(bmp_fheader, bmpinfheader, all);
	exit(0);
}
