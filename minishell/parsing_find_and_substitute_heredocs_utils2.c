/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_find_and_substitute_heredocs_utils2        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 00:18:32 by federico          #+#    #+#             */
/*   Updated: 2025/06/15 00:44:59 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_queue	*new_reads_init(t_program *shell)
{
	t_queue	*result;

	result = malloc(sizeof(t_queue));
	if (result == NULL)
	{
		manage_critical_error(MALLOC_ERR, "new_reads_init", shell);
	}
	result->pipe_mode = NULL;
	result->content = readline("> ");
	result->next = NULL;
	return (result);
}

int	heredoc_len(t_queue *new_reads, char *target)
{
	int	len;

	if (new_reads == NULL)
		return (0);
	len = 0;
	while (new_reads && strings_are_equal(new_reads->content, target) == NO)
	{
		len += string_len(new_reads->content);
		new_reads = new_reads->next;
	}
	return (len);
}

void	clean_heredoc_queue(t_queue *new_reads)
{
	t_queue	*temp;

	if (new_reads == NULL)
		return ;
	while (new_reads)
	{
		temp = new_reads->next;
		free(new_reads->content);
		free(new_reads);
		new_reads = temp;
	}
}

void	trim_after_target(t_queue *temp, char *target, t_program *shell)
{
	char	*new_content;
	int		len;

	len = len_till_target(temp->content, target);
	new_content = malloc(sizeof(char) * (len + 1));
	if (new_content == NULL)
	{
		manage_critical_error(MALLOC_ERR, "trim_after_target", shell);
	}
	copy_till_begin_of_target(new_content, temp->content, len);
	free(temp->content);
	temp->content = new_content;
}

int	len_till_target(char *str, char *target)
{
	int	i;
	int	j;

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
			return (i - string_len(target));
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			i++;
	}
	return (i);
}
