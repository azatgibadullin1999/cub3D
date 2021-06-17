/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_sprite_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 13:02:18 by larlena           #+#    #+#             */
/*   Updated: 2021/03/12 15:37:58 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_comparison_coordinates(t_all *all)
{
	t_list	*tmp;

	tmp = all->sprite;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (((t_sprite *)tmp->content)->y == all->ray.map_y &&
		((t_sprite *)tmp->content)->x == all->ray.map_x)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_swap(t_list **begin, t_list **sprite, t_list *past)
{
	t_list	*buf;

	if (*begin == *sprite)
		*begin = (*sprite)->next;
	else
		past->next = (*sprite)->next;
	buf = (*sprite)->next;
	(*sprite)->next = buf->next;
	buf->next = (*sprite);
	(*sprite) = buf;
}

void	ft_booble_sort(t_list **sprite)
{
	int		max;
	int		i;
	t_list	*begin;
	t_list	*past;

	i = -1;
	begin = *sprite;
	max = ft_lstsize(*sprite);
	while (++i < max)
	{
		*sprite = begin;
		while ((*sprite)->next)
		{
			if (((t_sprite *)(*sprite)->content)->distance <
			(((t_sprite *)(*sprite)->next->content)->distance))
			{
				ft_swap(&begin, sprite, past);
			}
			past = *sprite;
			*sprite = (*sprite)->next;
		}
	}
	*sprite = begin;
}

void	ft_sort_sprite(t_all *all)
{
	t_list	*tmp;

	tmp = all->sprite;
	while (tmp)
	{
		((t_sprite *)tmp->content)->distance =
		((all->player.x - ((t_sprite *)tmp->content)->x) *
		(all->player.x - ((t_sprite *)tmp->content)->x) +
		(all->player.y - ((t_sprite *)tmp->content)->y) *
		(all->player.y - ((t_sprite *)tmp->content)->y));
		tmp = tmp->next;
	}
	ft_booble_sort(&all->sprite);
}

void	ft_render_sprite(t_all *all)
{
	t_list	*tmp;

	ft_sort_sprite(all);
	tmp = all->sprite;
	while (tmp)
	{
		ft_transformation_to_matrix(all, tmp);
		tmp = tmp->next;
	}
}
