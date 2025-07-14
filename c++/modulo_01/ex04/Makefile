#Makefile#

NAME = sed_is_for_loosers

CC = c++

CFLAGS = -std=c++98 -MMD -Wall -Wextra -Werror
#CFLAGS = -std=c++98 -MMD -DDEBUG

RM = rm -f

SRCS =	main.cpp \
		replace_file_strings.cpp

HDRS =	main.hpp

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