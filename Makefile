# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysong <ysong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/19 03:59:19 by ysong             #+#    #+#              #
#    Updated: 2021/02/19 04:02:28 by ysong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libasm.a

CC		=	gcc
NASM	=	nasm
FLAGS	=	-f macho64
INC		=	libasm.h
SRC		=	ft_write.s \
			ft_strlen.s	\
			ft_read.s		\
			ft_strcmp.s	\
			ft_strcpy.s	\
			ft_strdup.s
OBJ		=	$(SRC:.s=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

%.o		:	%.s
			$(NASM) -I$(INC) $(FLAGS) $< -o $@

clean	:
			rm -rf $(OBJ) $(OBJ_BONUS)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

test	:	re
			$(CC) -o test tester.c -L. -lasm
			./test

.PHONY: all, clean, fclean, re, bonus