NAME = megaphone
CC	=	clang++
CFLAGE = -Wall -Wextra -Werror
RM	=	rm -f

SRCS	=	Account.cpp tests.cpp

%.o:		%.cpp
			$(CC) $(CFLAGE) -g -c $< -o $@

$(NAME): $(OBJS)

all:	$(NAME)

clean:	
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re