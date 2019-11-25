/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:53:15 by thflahau          #+#    #+#             */
/*   Updated: 2018/12/10 14:53:15 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int			ft_check_data(char **s);
int			ft_solve(char **file, char ***grid, int num, char c);
void		ft_error(void);
void		ft_free_grid(char **grid);
void		ft_print_solution(char **str);
void		ft_delete_piece(char ***map, char c);
void		ft_shape_pieces(char ***file, int num, int coord[8]);
char		**ft_call(char **file);
char		*ft_get_data(int const fd);
char		**ft_strsplit_fillit(char *s, char c);

#endif
