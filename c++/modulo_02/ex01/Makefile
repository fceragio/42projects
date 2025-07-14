#Makefile#

NAME = More_usefull_fixed_point_number_class

CC = c++

CFLAGS = -std=c++98 -MMD -Wall -Wextra -Werror

RM = rm -f

SRCS =	main.cpp \
		Fixed.cpp

HDRS = Fixed.hpp

OBJS = $(SRCS:.cpp=.o)

COLOR_GREEN=\033[0;32m
COLOR_END=\033[0m

all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	$(CC) $(OBJS) -o $(NAME)
	@echo "$(COLOR_GREEN)$(NAME) created.✅$(COLOR_END)"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS:.o=.d)

fclean: clean
	$(RM) $(NAME)
	@echo "$(COLOR_GREEN)$(NAME) cleaned.✅$(COLOR_END)"

re: fclean all

.PHONY: all clean fclean re

-include $(OBJS:.o=.d)