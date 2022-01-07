NAME = zombie
CC	=	clang++
CFLAGE = -Wall -Wextra -Werror -std=c++98
RM	=	rm -f

INCLUDE_DIR = Zombie.hpp
MAIN = main.cpp
SRCS_DIR = ./srcs/
SRCS	=	newZombie.cpp randomChump.cpp Zombie.cpp

OBJS	=	$(SRCS:.cpp=.o)

$(NAME) : $(MAIN) $(OBJS)
		$(CC) $(MAIN) $(CFLAGE) -o $(NAME) $(OBJS)

$(OBJS) : $(SRCS) $(INCLUDE_DIR)
			$(CC) $(CFLAGE) -c $(SRCS)
		

all:	$(NAME)

clean:	
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re