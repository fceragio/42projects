#Makefile#

NAME = Hi_this_is_brains

CC = c++

RM = rm -f

FLAGS = -std=c++98 -MD -Werror -Wextra -Wall

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

HEADS = 

all: $(NAME)

$(NAME): $(OBJS) $(HEADS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS:.o=.d)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(OBJS:.o=.d)