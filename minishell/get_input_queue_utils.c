/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_queue_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:04:04 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 14:46:36 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	queue_append(t_queue **queue, t_program *shell)
{
	t_queue	*new_node;
	t_queue	*last_node;

	new_node = malloc(sizeof(t_queue));
	if (new_node == NULL)
	{
		manage_critical_error(MALLOC_ERR, "queue_append", shell);
	}
	last_node = queue_last(*queue);
	last_node->next = new_node;
	new_node->content = readline("> ");
	new_node->pipe_mode = last_node->pipe_mode;
	new_node->next = NULL;
	return ;
}

void	queue_newline(t_queue **queue, t_program *shell)
{
	t_queue	*new_node;
	t_queue	*last_node;
	char	*newline;

	new_node = malloc(sizeof(t_queue));
	if (new_node == NULL)
	{
		manage_critical_error(MALLOC_ERR, "queue_newline (new_node)", shell);
	}
	last_node = queue_last(*queue);
	last_node->next = new_node;
	new_node->next = NULL;
	new_node->pipe_mode = last_node->pipe_mode;
	newline = malloc(sizeof(char) * (1 + 1));
	if (newline == NULL)
	{
		manage_critical_error(MALLOC_ERR, "queue_append (newline)", shell);
	}
	newline[0] = '\n';
	newline[1] = '\0';
	new_node->content = newline;
}

void	queue_cat(t_queue *queue, char **target, int tot_len, t_program *shell)
{
	int	i;
	int	j;

	*target = malloc(sizeof(char) * (tot_len + 1));
	if (*target == NULL)
	{
		manage_critical_error(MALLOC_ERR, "queue_cat", shell);
	}
	i = 0;
	while (queue)
	{
		j = 0;
		while (queue->content[j])
		{
			(*target)[i] = queue->content[j];
			i++;
			j++;
		}
		queue = queue->next;
	}
	(*target)[i] = '\0';
}

int	queue_len(t_queue *queue)
{
	int	len;
	int	i;

	len = 0;
	if (queue == NULL)
		return (len);
	while (queue)
	{
		i = 0;
		while (queue->content[i])
		{
			i++;
			len++;
		}
		queue = queue->next;
	}
	return (len);
}

t_queue	*queue_last(t_queue *queue)
{
	while (queue->next)
	{
		queue = queue->next;
	}
	return (queue);
}
