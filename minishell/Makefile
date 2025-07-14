# Makefile

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline -lhistory
RM = rm -f

HEADER = minishell.h

SRCS = main.c \
	signals.c \
	envs_copy.c \
	envs_search.c \
	envs_manipulation.c \
	pipe_execution.c \
	command_execution_builtin.c \
	command_execution_executable.c \
	redirection_execution.c \
	redirection_execution_input.c \
	redirection_execution_output.c \
	exec_exit.c \
	exec_echo.c \
	exec_env.c \
	exec_cd.c \
	exec_pwd.c \
	exec_export.c \
	exec_export_valid_identifier.c \
	exec_export_raw.c \
	exec_export_raw_utils.c \
	exec_unset.c \
	get_input.c \
	get_input_utils.c \
	get_input_list_utils.c \
	get_input_queue_utils.c \
	tokenize.c \
	tokenize_list_utils.c \
	tokenize_measuring_utils.c \
	tokenize_measuring_utils2.c \
	parsing.c \
	parsing_identify_assignations.c \
	parsing_identify_commands.c \
	parsing_identify_pipes.c \
	parsing_identify_redirections.c \
	parsing_find_and_substitute_heredocs.c \
	parsing_find_and_substitute_heredocs_utils1.c \
	parsing_find_and_substitute_heredocs_utils2.c \
	parsing_find_and_translate_envs.c \
	parsing_find_and_translate_envs_utils1.c \
	parsing_find_and_translate_envs_utils2.c \
	parsing_find_and_translate_envs_exitcode.c \
	parsing_remove_quotes.c \
	parsing_adjust_token.c \
	parsing_adjust_token_utils.c \
	tree.c \
	tree_command_args.c \
	tree_command_assignations.c \
	tree_command_execpath.c \
	tree_command_execpath_dirs.c \
	tree_command_execpath_utils.c \
	tree_command_redirections.c \
	tree_command_vars.c \
	tree_cleaning.c \
	executing.c \
	utils.c \
	errors.c \
	cleaning.c

OBJS = $(SRCS:.c=.o)

COLOR_GREEN = \033[0;32m
COLOR_END = \033[0m

DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	@echo "$(COLOR_GREEN)$(NAME) created.✅$(COLOR_END)"

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)
	@echo "$(COLOR_GREEN)$(NAME) cleaned.✅$(COLOR_END)"

re: fclean all

.PHONY: all clean fclean re