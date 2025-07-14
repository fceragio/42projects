/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:07:17 by federico          #+#    #+#             */
/*   Updated: 2025/07/10 19:18:20 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_sig = 0;

int	main(int argc, char **argv, char **envp)
{
	t_program			shell;
	char				*input;
	struct sigaction	sa;

	shell_init(&shell, &argc, argv, envp);
	sig_init(&sa);
	shell.sa = &sa;
	input = get_input(&shell);
	while (input)
	{
		parsing_and_executing(input, &shell);
		input = get_input(&shell);
	}
	shell_clean(&shell);
	return (0);
}

void	shell_init(t_program *shell, int *argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	shell->exit_status = 0;
	shell->input_queue = NULL;
	shell->token_list = NULL;
	shell->execution_tree = NULL;
	shell->local_envs = NULL;
	shell->envs = NULL;
	shell->envs = copy_envp(envp, shell);
	shell->local_envs = malloc(sizeof(char *));
	if (shell->local_envs == NULL)
	{
		manage_critical_error(MALLOC_ERR, "shell init", shell);
	}
	shell->local_envs[0] = NULL;
}

char	*get_input(t_program *shell)
{
	char	*result;
	char	*line_read;
	int		tot_len;

	line_read = readline(PROMPT);
	if (!line_read)
		return (NULL);
	queue_init(&shell->input_queue, line_read, shell);
	if (shell->input_queue == NULL)
	{
		manage_error(SYNTAX_ERR, "input can not start with |", shell);
		free(line_read);
		return (NULL);
	}
	while (input_is_complete(shell->input_queue) == NO)
	{
		if (*shell->input_queue->pipe_mode == NO)
			queue_newline(&shell->input_queue, shell);
		queue_append(&shell->input_queue, shell);
	}
	tot_len = queue_len(shell->input_queue);
	queue_cat(shell->input_queue, &result, tot_len, shell);
	queue_free(&shell->input_queue);
	return (result);
}

void	parsing_and_executing(char *input, t_program *shell)
{
	if (input == NULL || input[0] == '\0')
	{
		free(input);
		return ;
	}
	if (input[0] != ' ' && input[0] != '\t')
	{
		add_history(input);
	}
	shell->token_list = tokenize(input, shell);
	shell->execution_tree = parsing(shell->token_list, shell);
	execute_tree(shell->execution_tree, shell);
}
