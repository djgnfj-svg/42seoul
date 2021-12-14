NAME = replace
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror
MAIN = main.cpp

$(NAME): $(MAIN)
	$(CXX) $(MAIN) $(CXXFLAGS) -o $(NAME)

all : $(NAME)
fclean:
	rm -rf $(NAME)
re:	fclean all

.PHONY: all fclean re