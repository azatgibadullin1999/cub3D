/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:40:58 by larlena           #+#    #+#             */
/*   Updated: 2021/01/19 19:50:17 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_error_handling(int code)
{
	ft_putendl_fd("Error", 1);
	if (code == 1)
		ft_putendl_fd("File error", 1);
	else if (code == 2)
		ft_putendl_fd("Invalid config file", 1);
	
	return (ERROR);
}