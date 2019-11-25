#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 15:01:24 by thflahau          #+#    #+#              #
#    Updated: 2019/01/19 17:08:12 by thflahau         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	fillit

SRCS	=	main.c tools.c parsing.c solving.c solving2.c

OBJECTS =	$(SRCS:.c=.o)

HEADER	=	fillit.h

CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@(cd libft/ && make)
	@gcc $(CFLAGS) -o fillit $(OBJECTS) -I libft -L libft/ -lft

%.o: %.c $(HEADER)
	@gcc $(CFLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJECTS)
	@(cd libft/ && make $@)

fclean:
	@rm -f $(OBJECTS)
	@rm -f $(NAME)
	@(cd libft/ && make $@)

re: fclean all

.phony: all clean fclean re
