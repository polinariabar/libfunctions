# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leweathe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/29 14:54:48 by leweathe          #+#    #+#              #
#    Updated: 2020/05/13 12:39:39 by leweathe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = 	print_numb.c print_char_str.c help_digits.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_itoa.c modificators.c ft_strlen.c printf.c
OBJS = $(SRCS:.c=.o)

all: $(SRCS) $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

.c.o:
	gcc -c -Wall -Wextra -Werror $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:	fclean all
