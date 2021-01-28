/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:06:20 by larlena           #+#    #+#             */
/*   Updated: 2021/01/28 18:57:43 by larlena          ###   ########.fr       */
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
int			ft_convert_list_to_array(t_list *start, char ***map);
int			ft_get_starting_point(char **map, t_all *all);
int			ft_get_map_in_list(t_list **start, int fd, t_all *all);
int			ft_map_validation(char **map, t_all *all);
int			ft_isstartchar(int c);
char		**ft_mapdup(char **map);
void		ft_del_content(void *content);
void		ft_del_array(char **map);

#endif