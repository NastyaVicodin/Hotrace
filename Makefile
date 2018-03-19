#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akrupski <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/17 07:47:06 by akrupski          #+#    #+#              #
#    Updated: 2017/10/17 07:47:07 by akrupski         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = hotrace

CFLAGS = -c -Wall -Wextra -Werror

SRC = main.c libft1.c libft2.c libft3.c get_next_line.c
 
BINS = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(BINS)
	gcc -o $(NAME) $(BINS)
clean : 
	rm -rf $(BINS)
fclean : clean
	rm -rf $(NAME)
re : fclean all