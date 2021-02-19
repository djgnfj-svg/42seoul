# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysong <ysong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/12 22:40:26 by ysong             #+#    #+#              #
#    Updated: 2021/02/20 03:12:45 by ysong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= miniRT
NAME_BONUS = miniRT_bonus
GCC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC		= camera.c color_utils.c color.c draw_rt.c error.c \
		light.c minirt_utils.c minirt.c save_bmp.c\
		free_memory/free_object.c free_memory/free_object2.c \
		object/cylinder_caps.c object/cylinder.c object/plane.c \
		object/sphere.c object/square.c object/triangle.c \
		parse/parse_element_object.c parse/parse_element.c parse/parse_file.c parse/parse_utils.c parse/parse_utils2.c \
		shadows/shadows.c \
		shadows/cylinder_shadows.c shadows/plane_shadows.c \
		shadows/sphere_shadows.c shadows/square_shadows.c shadows/triangle_shadows.c \
		vec/vec_calc.c vec/vec_utils.c vec/vec_utils2.c \

SRC_BONUS = camera.c color_utils.c color.c draw_rt_bonus.c error.c \
		light.c minirt_utils.c minirt.c save_bmp.c thread.c\
		free_memory/free_object.c free_memory/free_object2.c \
		filter_bonus/filter_bonus.c \
		object/cylinder_caps.c object/cylinder.c object/plane.c \
		object/sphere.c object/square.c object/triangle.c \
		parse/parse_element_object.c parse/parse_element.c parse/parse_file.c parse/parse_utils.c \
		parse/parse_utils2.c parse/parse_element_bonus.c parse/parse_object_bonus.c \
		shadows/shadows.c \
		shadows/cylinder_shadows.c shadows/plane_shadows.c \
		shadows/sphere_shadows.c shadows/square_shadows.c shadows/triangle_shadows.c \
		txture/color_plane_bonus.c txture/color_sphere_bonus.c txture/color_utils_bonus.c \
		vec/vec_calc.c vec/vec_utils.c vec/vec_utils2.c

MSRC	= main.c
MSRC_BONUS = main_bonus.c
INCLUDE = ./includes/

SRCDIR			= ./src/
SRCDIR_BONUS	= ./src_bonus/

SRCS	= $(addprefix $(SRCDIR), $(SRC))
MSRCS	= $(addprefix $(SRCDIR), $(MSRC))
SRCS_BONUS	= $(addprefix $(SRCDIR_BONUS), $(SRC_BONUS))
MSRCS_BONUS	= $(addprefix $(SRCDIR_BONUS), $(MSRC_BONUS))


LIBDIR	= ./libft/
LIBNAME	= libft.a
MLXDIR	= ./mlx/

OBJS	= $(SRCS:.c=.o)
MOBJS	= $(MSRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)
MOBJS_BONUS	= $(MSRCS_BONUS:.c=.o)

%.o:		%.c
			$(GCC) -g $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(NAME):	$(LIBNAME) $(MLXNAME) $(OBJS) $(MOBJS)
			$(GCC) $(CFLAG) -I$(INCLUDE) -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(MOBJS) $(LIBNAME) $(MLXNAME)

$(NAME_BONUS):	$(LIBNAME) $(MLXNAME) $(OBJS_BONUS) $(MOBJS_BONUS)
			$(GCC) $(CFLAG) -I$(INCLUDE) -L$(MLXDIR) -lpthread -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS) $(OBJS_BONUS) $(MOBJS_BONUS) $(LIBNAME) $(MLXNAME)

$(LIBNAME):
			@$(MAKE) -C $(LIBDIR) bonus
			@cp $(addprefix $(LIBDIR), $(LIBNAME)) $(LIBNAME)

$(MLXNAME):
			@$(MAKE) -C $(MLXDIR)
			@cp $(addprefix $(MLXDIR), $(MLXNAME)) $(MLXNAME)

all:		$(NAME)

bonus:		$(NAME_BONUS)

clean:
			$(RM) $(OBJS) $(MOBJS) $(OBJS_BONUS) $(MOBJS_BONUS) *.bmp

fclean:		clean
			$(RM) $(NAME) $(NAME_BONUS) $(LIBNAME) $(MLXNAME)
			@$(MAKE) -C $(LIBDIR) fclean
			@$(MAKE) -C $(MLXDIR) clean

re:			fclean $(NAME)


.PHONY:			all clean fclean re bonus