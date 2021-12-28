NAME = account
CC	=	clang++
CFLAGE = -Wall -Wextra -Werror -std=c++98
RM	=	rm -f

SRCS	=	Account.cpp tests.cpp
OBJS	=	$(SRCS:.cpp=.o)

%.o:		%.cpp
			$(CC) $(CFLAGE) -g -c $< -o $@

$(NAME): $(OBJS)
			@ $(CC) $(CFLAGE) -g -o $(NAME) $(OBJS)
all:	$(NAME)

clean:	
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re