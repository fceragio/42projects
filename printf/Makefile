#Makefile#


NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar rcs

SRCS = converter.c \
	ft_printf.c \
	print_char.c \
	print_decimal.c \
	print_else.c \
	print_exadecimal_low.c \
	print_exadecimal_upp.c \
	print_integer.c \
	print_percent.c \
	print_pointer.c \
	print_string.c \
	print_unsigned_int.c

OBJS = $(SRCS:.c=.o)

COLOR_GREEN=\033[0;32m
COLOR_END=\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
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