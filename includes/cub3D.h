/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:13:53 by larlena           #+#    #+#             */
/*   Updated: 2021/03/12 16:34:58 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../get_next_line/get_next_line.h"
# include "../Libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "structs.h"
# include "parser.h"
# include "render.h"

# define ERROR -1
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define R_T 124
# define L_T 123

int			ft_render_map(t_all *all);
int			ft_kay_hook(int kay_code, t_all *all);
int			ft_render_map(t_all *all);
int			ft_get_cfg(const char *filename, t_all *all);
int			ft_get_mlx_params(t_data *data, t_cfg *cfg, int flag);
int			ft_check_identifier(char *str, t_all *all);
void		ft_error_handling(char *str);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		my_mlx_get_pixel_color(t_data *data, int y, int x, int *color);
int			ft_screenshot(t_all *all, char *flag);

#endif
