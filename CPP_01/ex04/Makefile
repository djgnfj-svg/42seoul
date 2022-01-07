NAME = replace
CC	=	clang++
CFLAGE = -Wall -Wextra -Werror -std=c++98
RM	=	rm -f
MAIN = main.cpp


$(NAME) : $(MAIN) $(OBJS)
		$(CC) $(MAIN) $(CFLAGE) -o $(NAME) $(OBJS)


all:	$(NAME)

clean:	
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re