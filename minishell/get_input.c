/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:34:30 by federico          #+#    #+#             */
/*   Updated: 2025/06/12 00:12:53 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	queue_init(t_queue **queue, char *line_read, t_program *shell)
{
	if (invalid_pipe(line_read) == YES)
	{
		(*queue) = NULL;
		return ;
	}
	*queue = malloc(sizeof(t_queue));
	if (*queue == NULL)
	{
		free(line_read);
		manage_critical_error(MALLOC_ERR, "queue_init (queue)", shell);
	}
	(*queue)->pipe_mode = malloc(sizeof(int));
	if ((*queue)->pipe_mode == NULL)
	{
		free(line_read);
		manage_critical_error(MALLOC_ERR, "queue_init (pipe_mode)", shell);
	}
	*(*queue)->pipe_mode = NO;
	(*queue)->content = line_read;
	(*queue)->next = NULL;
}

int	invalid_pipe(char *line_read)
{
	int	i;

	if (line_read == NULL)
	{
		return (NO);
	}
	i = 0;
	while (line_read[i] && (line_read[i] == ' '
			|| line_read[i] == '\t' || line_read[i] == '\n'))
	{
		i++;
	}
	if (line_read[i] == '|')
	{
		return (YES);
	}
	return (NO);
}

static void	while_loop(t_queue **queue, int *i, int *flag, char *target)
{
	while ((*queue)->content[*i])
	{
		if ((*queue)->content[*i] == '\'' || (*queue)->content[*i] == '\"')
		{
			*target = (*queue)->content[*i];
			*flag = NO;
			wait_next_target(queue, i, *target, flag);
		}
		else if ((*queue)->content[*i] == '|')
		{
			*flag = NO;
			wait_valid_char(queue, i, flag);
		}
		else
			(*i)++;
		if (*flag == NO)
			break ;
	}
}

int	input_is_complete(t_queue *queue)
{
	int		i;
	int		flag;
	char	target;

	flag = YES;
	while (queue)
	{
		i = 0;
		while_loop(&queue, &i, &flag, &target);
		if (flag == NO)
			break ;
		queue = queue->next;
	}
	return (flag);
}
