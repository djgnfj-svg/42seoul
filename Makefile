NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCDIR		=	src/
SRC			=	 main.c philo_actions.c print.c thread.c utils.c init.c
INCLUDE 	= ./includes/

SRCS	= $(addprefix $(SRCDIR), $(SRC))

OBJS	= $(SRCS:.c=.o)
%.o:		%.c
			$(CC) $(CFLAGS) -g -I$(INCLUDE) -c $< -o $@

$(NAME):	$(OBJS)
				$(CC) $(CFLAGS) -g -I$(INCLUDE) -o $(NAME) $(OBJS) -lpthread
all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)


.PHONY:			all clean fclean re