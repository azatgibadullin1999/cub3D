/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:06:20 by larlena           #+#    #+#             */
/*   Updated: 2021/02/06 16:12:05 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3D.h"

int			ft_parsing_resolution(const char *str, t_all *all, int *f_any);

int			ft_parsing_texture(const char *str, t_all *all, int *f_any);

int			ft_parsing_color(const char *str, t_all *all, int *color, int *f_any);
int			create_trgb(int t, int r, int g, int b);

int			ft_parsing_map(int fd, t_all *all);
int			ft_convert_list_to_array(t_list *start, t_all *all);
int			ft_get_starting_point(t_all *all);
int			ft_get_map_in_list(t_list **start, int fd, t_all *all);
int			ft_map_validation(t_all *all);
int			ft_isstartchar(int c);
int			ft_flood_fill(char **map, int y, int x);
int			ft_isvalid(int c);
void		ft_initialisation_player(t_player *player, int y, int x, int diraciont);
t_list		*ft_maplen(t_list *start, int *line_num, int *line_size);
char		**ft_mapdup(t_all *all);
void		ft_del_content(void *content);
void		ft_del_array(char **map);

#endif