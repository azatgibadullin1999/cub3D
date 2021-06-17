/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:06:20 by larlena           #+#    #+#             */
/*   Updated: 2021/03/12 15:37:11 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

int			ft_parsing_resolution(const char *str, t_all *all, int *f_any);

int			ft_parsing_texture(const char *str, int *f_any, t_texture *texture);

int			ft_parsing_color(const char *str, int *color, int *f_any);
int			create_trgb(int t, int r, int g, int b);

int			ft_parsing_map(int fd, t_all *all);
int			ft_convert_list_to_array(t_list *start, t_all *all);
void		ft_initialisation_player(t_player *player, int y,
									int x, int diraciont);
int			ft_get_starting_point(t_all *all);
void		ft_validation_sprite(t_all *all, int y, int x);
int			ft_get_map_in_list(t_list **start, int fd);
void		ft_filling_struct(t_player *player, int f);
int			ft_map_validation(t_all *all);
int			ft_isstartchar(int c);
void		ft_del_content(void *content);
int			ft_flood_fill(t_all *all, char **map, int y, int x);
void		ft_sub_maplen(int *line_num, int *line_size, int i);
void		ft_del_array(char **map);
char		**ft_mapdup(t_all *all);
int			ft_isvalid(int c);
t_list		*ft_maplen(t_list *start, int *line_num, int *line_size);

#endif
