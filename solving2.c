/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:39:55 by thflahau          #+#    #+#             */
/*   Updated: 2018/12/27 16:56:37 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_delete_piece(char ***map, char c)
{
	int			i;
	int			j;

	if (*map != NULL)
	{
		i = 0;
		while ((*map)[i])
		{
			j = 0;
			while ((*map)[i][j])
				if ((*map)[i][j++] == c)
					(*map)[i][j - 1] = '.';
			i++;
		}
	}
}

static char		**ft_new_grid(void)
{
	int			i;
	int			j;
	char		**grid;

	if (!(grid = (char **)malloc(sizeof(char *) * 3)))
		return (NULL);
	i = 0;
	while (i < 2)
	{
		if (!(grid[i] = (char *)malloc(sizeof(char) * 3)))
			return (NULL);
		j = 0;
		while (j < 2)
			grid[i][j++] = '.';
		grid[i++][j] = 0;
	}
	grid[i] = NULL;
	return (grid);
}

static void		ft_fill_map(char ***map, char **grid, int size)
{
	int			i;
	int			j;

	i = 0;
	while ((*map)[i] != NULL)
	{
		j = 0;
		while (j++ < size)
		{
			if (i < size - 1 && j < size)
				(*map)[i][j - 1] = grid[i][j - 1];
			else
				(*map)[i][j - 1] = '.';
		}
		(*map)[i++][j - 1] = 0;
	}
}

static char		**ft_increase_grid_size(char ***map)
{
	int			i;
	int			size;
	char		**grid;

	i = 0;
	while ((*map)[i])
		size = ++i + 1;
	if (!(grid = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(grid[i++] = (char *)malloc(sizeof(char) * size)))
			return (NULL);
	}
	grid[i] = NULL;
	ft_fill_map(&grid, *map, size);
	return (grid);
}

char			**ft_call(char **file)
{
	char		**ptr;
	char		**grid;

	if (!(grid = ft_new_grid()))
		return (NULL);
	while (!ft_solve(file, &grid, 0, 'A'))
	{
		ptr = grid;
		if (!(grid = ft_increase_grid_size(&ptr)))
			return (NULL);
		ft_free_grid(ptr);
	}
	return (grid);
}
