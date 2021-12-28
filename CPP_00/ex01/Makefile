NAME = PhoneBook
CC	=	clang++
CFLAGE = -Wall -Wextra -Werror -std=c++98
RM	=	rm -f

INCLUDE_DIR = ./include/

SRCS_DIR = ./srcs/
SRCS	=	$(addprefix $(SRCS_DIR),\
				Friend.cpp\
				PhoneBook.cpp \
)

OBJS	=	$(SRCS:.cpp=.o)

%.o: %.cpp
			$(CC) $(CFLAGE) -g -I$(INCLUDE_DIR) -c $< -o $@

$(NAME): $(OBJS)
			$(CC) $(CFLAGE) -g -I$(INCLUDE_DIR) -o $(NAME) $(OBJS)
		

all:	$(NAME)

clean:	
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re