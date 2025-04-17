#Makefile#

NAME = philo

CC = cc

CFLAGS = -pthread -Wall -Wextra -Werror

RM = rm -f

SRCS = f_initializations.c \
		f_monitor_routine.c \
		f_philo_routine.c \
		f_utils.c \
		main.c

OBJS = $(SRCS:.c=.o)

COLOR_GREEN=\033[0;32m
COLOR_END=\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	@echo "$(COLOR_GREEN)$(NAME) created.✅$(COLOR_END)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	@echo "$(COLOR_GREEN)$(NAME) cleaned.✅$(COLOR_END)"

re: fclean all

.PHONY: all clean fclean re bonus