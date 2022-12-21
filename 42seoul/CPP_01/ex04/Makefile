NAME = replace
CC	=	clang++
CFLAGE = -std=c++98 -Wall -Wextra -Werror
RM	=	rm -f
MAIN = main.cpp


$(NAME) : $(MAIN)
		$(CC) $(MAIN) $(CFLAGE) -o $(NAME)

all:	$(NAME)

clean:	
		$(RM)

fclean: clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re