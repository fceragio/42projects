/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_find_and_substitute_heredocs_utils1        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 00:18:20 by federico          #+#    #+#             */
/*   Updated: 2025/06/15 00:28:04 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	target_is_present(char *str, char *target);

void	copy_new_heredoc(t_queue *new_reads, int len, char *new_content)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (i < len && new_reads->content[j])
		{
			new_content[i] = new_reads->content[j];
			i++;
			j++;
		}
		new_reads = new_reads->next;
	}
	new_content[i] = '\0';
}

int	found_heredoc_target(t_queue *new_reads, char *target, t_program *shell)
{
	t_queue	*temp;

	if (new_reads == NULL)
		return (NO);
	temp = new_reads;
	while (temp)
	{
		if (target_is_present(temp->content, target) == YES)
		{
			trim_after_target(temp, target, shell);
			return (YES);
		}
		temp = temp->next;
	}
	return (NO);
}

static int	target_is_present(char *str, char *target)
{
	int	i;
	int	j;

	if (str == NULL || target == NULL)
		return (NO);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && str[i] != '\n' && str[i] == target[j])
		{
			i++;
			j++;
		}
		if ((str[i] == '\0' || str[i] == '\n') && target[j] == '\0')
			return (YES);
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			i++;
	}
	return (NO);
}

void	new_reads_append_newline(t_queue *new_reads, t_program *shell)
{
	t_queue	*new_node;
	t_queue	*last_node;

	last_node = queue_last(new_reads);
	new_node = malloc(sizeof(t_queue));
	if (new_node == NULL)
	{
		manage_critical_error(MALLOC_ERR,
			"new_reads_append_newline (new_node)", shell);
	}
	new_node->pipe_mode = new_reads->pipe_mode;
	new_node->content = malloc(sizeof(char) * (1 + 1));
	if (new_node->content == NULL)
	{
		manage_critical_error(MALLOC_ERR,
			"new_reads_append_newline (new_node->content)", shell);
	}
	new_node->content[0] = '\n';
	new_node->content[1] = '\0';
	last_node->next = new_node;
	new_node->next = NULL;
}

void	new_reads_append_newnode(t_queue *new_reads, t_program *shell)
{
	t_queue	*new_node;
	t_queue	*last_node;

	last_node = queue_last(new_reads);
	new_node = malloc(sizeof(t_queue));
	if (new_node == NULL)
	{
		manage_critical_error(MALLOC_ERR, "rew_reads_append_newnode", shell);
	}
	new_node->pipe_mode = new_reads->pipe_mode;
	new_node->content = readline("> ");
	last_node->next = new_node;
	new_node->next = NULL;
}
