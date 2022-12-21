NAME = karen_filter
CC	=	clang++
CFLAGE = -Wall -Wextra -Werror
RM	=	rm -f

SRCS_DIR = ./srcs/
MAIN = main.cpp
INCLUDE = karen.hpp
SRCS	= karen.cpp

OBJS	=	$(SRCS:.cpp=.o)

$(NAME) : $(MAIN) $(OBJS)
		$(CC) $(MAIN) $(CFLAGE) -o $(NAME) $(OBJS)

$(OBJS) : $(SRCS) $(INCLUDE)
			$(CC) $(CFLAGE) -c $(SRCS)
		

all:	$(NAME)

clean:	
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re