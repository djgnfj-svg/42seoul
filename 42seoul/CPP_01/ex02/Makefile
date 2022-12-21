NAME = brain
CXX = clang++
CFLAGE = -Wall -Wextra -Werror -std=c++98
MAIN = main.cpp
RM	=	rm -f


$(NAME): $(MAIN)
	$(CXX) $(MAIN) $(CXXFLAGS) -o $(NAME)

all:	$(NAME)

clean:	
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re