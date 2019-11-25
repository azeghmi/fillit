/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:37:52 by thflahau          #+#    #+#             */
/*   Updated: 2018/12/19 14:12:05 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void					ft_error(void)
{
	ft_putendl("error");
	exit(0);
}

void					ft_free_grid(char **grid)
{
	char				**ptr;

	ptr = grid;
	if (grid)
		while (*grid != NULL)
			free((void *)*grid++);
	free((void *)ptr);
}

void					ft_print_solution(char **file)
{
	if (file)
		while (*file != NULL)
			ft_putendl(*file++);
}

static int				ft_wcount(char *str, char c)
{
	int					nbr;
	char				*ptr;

	nbr = 0;
	ptr = str;
	while (*str)
	{
		if (*str != c)
		{
			nbr++;
			while (*str != c && *str)
				str++;
		}
		else if (*(str + 1) == c)
		{
			free((void *)ptr);
			ft_error();
		}
		str++;
	}
	return (nbr);
}

char					**ft_strsplit_fillit(char *s, char c)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		x;
	char				**grid;

	if (!s || !(grid = (char **)malloc(sizeof(char *) * (ft_wcount(s, c) + 1))))
		return (NULL);
	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = i;
			while (s[i] != c && s[i])
				i++;
			if (!(grid[x++] = ft_strsub(s, j, i - j)))
				return (NULL);
		}
	}
	grid[x] = NULL;
	return (grid);
}
