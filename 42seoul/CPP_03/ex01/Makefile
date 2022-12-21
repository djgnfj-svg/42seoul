NAME = claptrap
CC	=	clang++
CFLAGE = -std=c++98 -Wall -Wextra -Werror
RM	=	rm -f

MAIN	=	main.cpp

INCLUDE = ClapTrap.hpp ScavTrap.hpp
SRCS	=	ClapTrap.cpp ScavTrap.cpp
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