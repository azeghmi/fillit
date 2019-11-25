/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:05:02 by azeghmi           #+#    #+#             */
/*   Updated: 2018/12/20 15:05:09 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_shape_pieces(char ***file, int num_lines, int coord[8])
{
	int			i;
	int			j;
	int			cpt;

	cpt = 0;
	i = num_lines;
	while ((*file)[i] && i < num_lines + 4)
	{
		j = 0;
		while ((*file)[i][j])
		{
			if ((*file)[i][j++] != '.')
			{
				coord[cpt] = i - num_lines;
				coord[cpt + 1] = j - 1;
				cpt += 2;
			}
		}
		i++;
	}
}

static int		ft_grid_size(char **grid)
{
	int			size;

	if (grid == NULL)
		return (0);
	size = 0;
	while (grid[size])
		size++;
	return (size);
}

static int		ft_fit_piece(char **grid, int coord[8], int x, int y)
{
	int			i;
	int			size;
	int			delta_x;
	int			delta_y;

	i = 0;
	size = ft_grid_size(grid) - 1;
	delta_x = coord[0] - x;
	delta_y = coord[1] - y;
	while (i < 8)
	{
		coord[i] -= delta_x;
		coord[i + 1] -= delta_y;
		i += 2;
	}
	i = 0;
	while (i < 8)
	{
		if (coord[i] < 0 || coord[i] > size || coord[i + 1] < 0
		|| coord[i + 1] > size || grid[coord[i]][coord[i + 1]] != '.')
			return (0);
		i += 2;
	}
	return (1);
}

static void		ft_place_piece(char **grid, int coord[8], char c)
{
	int			i;

	if (grid)
	{
		i = 0;
		while (i < 8)
		{
			grid[coord[i]][coord[i + 1]] = c;
			i += 2;
		}
	}
}

int				ft_solve(char **file, char ***grid, int num, char c)
{
	int			x;
	int			y;
	int			coord[8];

	x = 0;
	ft_shape_pieces(&file, num, coord);
	if (file[num] == NULL)
		return (1);
	while (x < ft_grid_size(*grid))
	{
		y = 0;
		while (y++ < ft_grid_size(*grid))
		{
			if (ft_fit_piece(*grid, coord, x, y - 1))
			{
				ft_place_piece(*grid, coord, c);
				if (ft_solve(file, grid, num + 4, c + 1))
					return (1);
				ft_delete_piece(grid, c);
			}
		}
		x++;
	}
	return (0);
}
