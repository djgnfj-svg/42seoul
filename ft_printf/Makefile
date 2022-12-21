# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djgnfj <djgnfj@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 08:26:41 by djgnfj            #+#    #+#              #
#    Updated: 2020/11/16 17:24:24 by djgnfj           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft

SRCS		= ./ft_printf.c ./utils.c\
			  ./ft_print_char.c ./ft_print_num.c ./ft_print_string.c
OBJS		= $(SRCS:.c=.o)

RM			= rm -f
AR			= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

$(NAME) : $(OBJS)
		make all -C $(LIBFT)
		cp $(LIBFT)/$(LIBFT).a $(NAME)
		$(AR) $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re : fclean all