/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:11:37 by thflahau          #+#    #+#             */
/*   Updated: 2018/12/19 14:11:40 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int				ft_check_dimensions(int i, int j, int *bloc, int *max)
{
	if (j < 4)
		return (0);
	if (!(i % 4))
	{
		if (*bloc != 4 || *max < 2)
			return (0);
		*bloc = 0;
		*max = 0;
	}
	return (1);
}

static int				ft_check_piece_format(char ***s, int i, int j)
{
	int					num;

	num = 0;
	if (i && (*s)[i - 1][j] == '#')
		num++;
	if (j < 4 && (*s)[i][j + 1] == '#')
		num++;
	if (j && (*s)[i][j - 1] == '#')
		num++;
	if ((*s)[i + 1] && (*s)[i + 1][j] == '#')
		num++;
	return (num);
}

static int				ft_check_piece(char ***s, int i, int j, int *m)
{
	int					connections;

	if (!(connections = ft_check_piece_format(s, i, j)))
		return (0);
	if (connections > *m)
		*m = connections;
	return (1);
}

int						ft_check_data(char **s)
{
	int					i;
	int					j;
	int					bloc;
	int					connections;

	i = 0;
	bloc = 0;
	connections = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j++] == '#')
			{
				if (!(ft_check_piece(&s, i, j - 1, &connections)))
					return (0);
				bloc++;
			}
		}
		if (!(ft_check_dimensions(++i, j, &bloc, &connections)))
			return (0);
	}
	return (i % 4 ? 0 : i / 4);
}

char					*ft_get_data(int const fd)
{
	int					i;
	int					n;
	int					gnl;
	char				*str;
	char				*file;

	n = 0;
	gnl = 1;
	if (!(file = ft_strnew(1)))
		return (NULL);
	while (gnl > 0)
	{
		if ((gnl = get_next_line(fd, &str)) < 0)
			return (NULL);
		i = 0;
		if ((!(++n % 5) && str[0]) || (n % 5 && !str[0]) || n > 129)
			return (NULL);
		while (str[i++])
			if ((str[i - 1] != '.' && str[i - 1] != '#') || i > 4)
				return (NULL);
		if (!(file = ft_strjoinfree(file, str, "\n")))
			return (NULL);
	}
	return (file);
}
