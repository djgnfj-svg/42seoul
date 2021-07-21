# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysong <ysong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 11:55:39 by ysong             #+#    #+#              #
#    Updated: 2021/07/21 14:27:57 by ysong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCDIR		=	src/
SRC			=	push_swap.c ft_init.c arg_check.c get_item.c  ft_utils.c \
				sort/sort_arg_five.c sort/sort_b_to_a.c sort/sort_arg_three_b.c \
				sort/under_three.c sort/sort_a_to_b.c sort/sort_arg_three_a.c \
				operations/swap.c operations/reverse_rotate.c operations/rotate.c operations/push.c
MSRC		=	src/main.c
CHECKER		=	src/check.c

INCLUDE 	= ./include/

LIBDIR = ./libft/
LIBNAME = libft.a

SRCS	= $(addprefix $(SRCDIR), $(SRC))

OBJS	= $(SRCS:.c=.o)
MOBJS	= $(MSRC:.c=.o)
CHECKEROBJS	=	$(CHECKER:.c=.o)
%.o:		%.c
			$(CC) $(CFLAGS) -g -I$(INCLUDE) -c $< -o $@

$(NAME):	$(LIBNAME) $(OBJS) $(MOBJS)
				$(CC) $(CFLAGS) -g -I$(INCLUDE) -o $(NAME) $(OBJS) $(MOBJS) $(LIBNAME)

$(LIBNAME):
				@$(MAKE) -C $(LIBDIR) bonus
				@cp $(addprefix $(LIBDIR), $(LIBNAME)) $(LIBNAME)
all:		$(NAME)

check:		$(LIBNAME) $(OBJS) $(MOBJS) $(CHECKEROBJS)
				$(CC) $(CFLAGS) -g -I$(INCLUDE) -o checker $(OBJS) $(CHECKEROBJS) $(LIBNAME)

clean:
			$(RM) $(OBJS) $(MOBJS) $(CHECKEROBJS)

fclean:		clean
			$(RM) $(NAME) $(LIBNAME) checker
			@$(MAKE) -C $(LIBDIR) fclean

re:			fclean $(NAME)


.PHONY:			all clean fclean re bonus