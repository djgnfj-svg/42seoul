NAME = violence
CC	=	clang++
CFLAGE = -Wall -Wextra -Werror -std=c++98
RM	=	rm -f

INCLUDE = HumanA.hpp HumanB.hpp Weapon.hpp 
MAIN = main.cpp

SRCS	= HumanA.cpp HumanB.cpp Weapon.cpp 

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