# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysong <ysong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 11:55:39 by ysong             #+#    #+#              #
#    Updated: 2021/07/24 00:33:37 by ysong            ###   ########.fr        #
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

OPERDIR		=	src/operations/
OPER		=	swap.c reverse_rotate.c rotate.c push.c

MSRC		=	src/main.c

CHECKER		=	src/check.c

OPERDIR_BONUS	=	src/operations_bonus/
OPER_BONUS		=	push.c reverse_rotate.c rotate.c swap.c

INCLUDE 	= ./include/

LIBDIR = ./libft/
LIBNAME = libft.a

SRCS	= $(addprefix $(SRCDIR), $(SRC))
OPRS	= $(addprefix $(OPERDIR), $(OPER))
OPRS_BONUS	= $(addprefix $(OPERDIR_BONUS), $(OPER_BONUS))

OBJS			= $(SRCS:.c=.o)
O_OPRS			= $(OPRS:.c=.o)
O_OPRS_BONUS	= $(OPRS_BONUS:.c=.o)
MOBJS			= $(MSRC:.c=.o)
CHECKEROBJS		= $(CHECKER:.c=.o)

%.o:		%.c
			$(CC) $(CFLAGS) -g -I$(INCLUDE) -c $< -o $@

$(NAME):	$(LIBNAME) $(OBJS) $(MOBJS) $(O_OPRS)
				$(CC) $(CFLAGS) -g -I$(INCLUDE) -o $(NAME) $(OBJS) $(O_OPRS) $(MOBJS) $(LIBNAME)

$(LIBNAME):
				@$(MAKE) -C $(LIBDIR) bonus
				@cp $(addprefix $(LIBDIR), $(LIBNAME)) $(LIBNAME)
all:		$(NAME)

checker:		$(LIBNAME) $(OBJS) $(O_OPRS_BONUS) $(MOBJS) $(CHECKEROBJS)
				$(CC) $(CFLAGS) -g -I$(INCLUDE) -o checker $(OBJS) $(O_OPRS_BONUS) $(CHECKEROBJS) $(LIBNAME)

clean:
			$(RM) $(OBJS) $(MOBJS) $(CHECKEROBJS) $(O_OPRS) $(O_OPRS_BONUS)

fclean:		clean
			$(RM) $(NAME) $(LIBNAME) checker
			@$(MAKE) -C $(LIBDIR) fclean

re:			fclean $(NAME)


.PHONY:			all clean fclean re bonus