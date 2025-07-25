NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar rcs

SRCS = ft_isalpha.c \
    ft_isdigit.c \
    ft_isprint.c \
    ft_isalnum.c \
    ft_isascii.c \
    ft_strlen.c \
    ft_memset.c \
    ft_bzero.c \
    ft_memcpy.c \
    ft_memmove.c \
    ft_strlcpy.c \
    ft_strlcat.c \
    ft_toupper.c \
    ft_tolower.c \
    ft_strchr.c \
    ft_strrchr.c \
    ft_strncmp.c \
    ft_memchr.c \
    ft_memcmp.c \
    ft_strnstr.c \
    ft_atoi.c \
    ft_calloc.c \
    ft_strdup.c \
    ft_substr.c \
    ft_strjoin.c \
    ft_strtrim.c \
    ft_split.c \
    ft_itoa.c \
    ft_strmapi.c \
    ft_striteri.c \
    ft_putchar_fd.c \
    ft_putstr_fd.c \
    ft_putendl_fd.c \
    ft_putnbr_fd.c 

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ft_lstnew.c \
    ft_lstadd_front.c \
    ft_lstsize.c \
    ft_lstlast.c \
    ft_lstadd_back.c \
    ft_lstdelone.c \
    ft_lstclear.c \
    ft_lstiter.c \
    ft_lstmap.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)
COLOR_GREEN=\033[0;32m
COLOR_END=\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "$(COLOR_GREEN)$(NAME) created.✅$(COLOR_END)"

bonus: $(OBJS_BONUS)
	@if [ ! -f $(NAME) ] || ar t $(NAME) | grep $(OBJS_BONUS); then \
        $(AR) $(NAME) $(OBJS_BONUS); \
        echo "$(COLOR_GREEN)$(NAME) updated with bonus objects.✅$(COLOR_END)"; \
    else \
        echo "$(COLOR_GREEN)$(NAME) already contains bonus objects.✅$(COLOR_END)"; \
    fi

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)
	@echo "$(COLOR_GREEN)$(NAME) cleaned.✅$(COLOR_END)"

re: fclean all

.PHONY: all clean fclean re bonus