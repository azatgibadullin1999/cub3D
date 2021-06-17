/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 22:20:05 by larlena           #+#    #+#             */
/*   Updated: 2021/03/12 15:37:16 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"

void		ft_render(t_all *all);

int			ft_raycastiong(t_all *all);
void		ft_side_check(t_ray *ray, t_player *player, int side);
void		ft_ray_iteration(t_ray *ray, int *side);
void		ft_calculation_of_side(t_ray *ray, t_player *player);
void		ft_calculation_of_direction_ray(t_ray *ray,
							t_player *player, t_cfg *cfg, int x);
void		ft_choice_wall(t_all *all, int x);
void		ft_render_wall(t_all *all, t_texture *texture, int x);
void		ft_calculate_tex_variables(t_all *all, t_texture *texture,
							int draw_start);
void		ft_get_wall_hight(t_ray *ray, t_cfg *cfg,
							int *draw_start, int *draw_end);
void		ft_drawing_wall(t_all *all, t_texture *texture, int x, int y);

void		ft_render_sprite(t_all *all);
void		ft_sort_sprite(t_all *all);
void		ft_booble_sort(t_list **sprite);
void		ft_swap(t_list **begin, t_list **sprite, t_list *past);
int			ft_comparison_coordinates(t_all *all);
void		ft_transformation_to_matrix(t_all *all, t_list *sprite);
void		ft_draw_sprite(t_all *all, t_matrix *matrix);
void		ft_draw_sprite_norma(t_all *all, t_matrix *matrix, int y, int x);
void		ft_calculate_hight_width(t_all *all, t_matrix *matrix);
void		ft_calculate_matrix(t_all *all, t_list *sprite, t_matrix *matrix);

int			ft_render_map(t_all *all);
int			ft_print_square(t_all *all, int y, int x, int color);

#endif
