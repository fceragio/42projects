/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export_raw_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:16:12 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 14:04:42 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	append_in_order(char *content, t_queue **queue, t_program *shell)
{
	t_queue	*new;
	t_queue	*temp;

	new = malloc(sizeof(t_queue));
	if (new == NULL)
	{
		manage_critical_error(SYS_ERR, "append_in_order", shell);
	}
	new->content = str_copy(content);
	new->pipe_mode = NULL;
	if (*queue == NULL || higher(new->content, (*queue)->content))
	{
		new->next = (*queue);
		*queue = new;
		return ;
	}
	temp = *queue;
	while (temp->next && higher(temp->next->content, new->content))
	{
		temp = temp->next;
	}
	new->next = temp->next;
	temp->next = new;
}

int	higher(char *str1, char *str2)
{
	int	i;

	if (str1 == NULL)
	{
		return (YES);
	}
	if (str2 == NULL)
	{
		return (NO);
	}
	i = 0;
	while (str1[i] && str1[i] == str2[i])
	{
		i++;
	}
	if ((str1[i] - str2[i]) >= 0)
	{
		return (NO);
	}
	return (YES);
}
