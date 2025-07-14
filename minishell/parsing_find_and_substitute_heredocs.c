/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_find_and_substitute_heredocs.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:11:19 by federico          #+#    #+#             */
/*   Updated: 2025/07/13 17:36:38 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	find_and_substitute_heredocs(t_list **token_list, t_program *shell)
{
	t_list				*temp;
	struct sigaction	temp_sa;

	temp_sig_init(&temp_sa, shell->sa);
	temp = *token_list;
	while (temp)
	{
		if (temp->token_id == REDIRECT_INPUT
			&& strings_are_equal("<<", temp->content) == YES)
		{
			temp = temp->next;
			get_and_substitute_heredoc(temp, shell);
			if (g_sig == SIGINT)
				break ;
			temp->token_len = string_len(temp->content);
			translate_heredoc_envs(temp, shell);
		}
		else
			temp = temp->next;
	}
}

void	get_and_substitute_heredoc(t_list *heredoc, t_program *shell)
{
	t_queue	*new_reads;
	t_queue	*last;

	new_reads = new_reads_init(shell);
	while (found_heredoc_target(new_reads, heredoc->content, shell) == NO)
	{
		last = queue_last(new_reads);
		if (g_sig == SIGINT)
		{
			clean_heredoc_queue(new_reads);
			return ;
		}
		if (last->content == NULL)
		{
			print_error("heredoc reached EOF before could find target");
			break ;
		}
		new_reads_append_newline(new_reads, shell);
		new_reads_append_newnode(new_reads, shell);
	}
	cat_and_substitute_heredoc(new_reads, &heredoc->content, shell);
	clean_heredoc_queue(new_reads);
}

void	translate_heredoc_envs(t_list *temp, t_program *shell)
{
	int	i;

	i = 0;
	while (temp->content[i])
	{
		if (temp->content[i] == '$' && temp->content[i + 1] != '\0'
			&& temp->content[i + 1] != '\n' && temp->content[i + 1] != '\t'
			&& temp->content[i + 1] != ' ')
		{
			translate_env(temp, i, shell);
			i = 0;
		}
		i++;
	}
}

void	cat_and_substitute_heredoc(t_queue *new_reads,
			char **target, t_program *shell)
{
	int		len;
	char	*result;

	len = heredoc_len(new_reads, *target);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
	{
		manage_critical_error(MALLOC_ERR,
			"cat_and_substitute_heredoc", shell);
	}
	copy_new_heredoc(new_reads, len, result);
	free(*target);
	*target = result;
}

void	copy_till_begin_of_target(char *new_content, char *to_trim, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		new_content[i] = to_trim[i];
		i++;
	}
	new_content[i] = '\0';
}
