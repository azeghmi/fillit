/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:42:41 by thflahau          #+#    #+#             */
/*   Updated: 2018/12/05 13:42:42 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int						main(int argc, char **argv)
{
	int					fd;
	char				*str;
	char				**ptr;
	char				**file;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit [file]");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error();
	if (!(str = ft_get_data(fd)))
		ft_error();
	if (!(ft_check_data((file = ft_strsplit_fillit(str, '\n')))))
		ft_error();
	if ((ptr = ft_call(file)))
		ft_print_solution(ptr);
	if (ptr)
		ft_free_grid(ptr);
	ft_free_grid(file);
	free((void *)str);
	if (close(fd) < 0)
		ft_error();
	return (0);
}
