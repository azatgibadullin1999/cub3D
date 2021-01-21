/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:40:58 by larlena           #+#    #+#             */
/*   Updated: 2021/01/21 17:46:30 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3D.h"

int		ft_error_handling(char *str)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(str, 1);
	return (ERROR);
}