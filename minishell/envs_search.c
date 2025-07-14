/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 20:13:33 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 14:50:49 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*custom_get_env(char *target, char **pool)
{
	int	i;
	int	j;

	if (pool == NULL || target == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (pool[i])
	{
		j = 0;
		while (pool[i][j] && target[j] && pool[i][j] == target[j])
		{
			j++;
		}
		if (pool[i][j] == '=' && target[j] == '\0')
		{
			j++;
			return (str_copy(pool[i] + j));
		}
		i++;
	}
	return (NULL);
}

char	*find_env_in_queue(char *to_find, t_queue *queue)
{
	t_queue	*temp;
	int		i;

	temp = queue;
	if (to_find == NULL || queue == NULL)
		return (NULL);
	while (temp)
	{
		i = 0;
		while (temp->content[i] && temp->content[i] == to_find[i])
		{
			if (temp->content[i] == '=')
				return (str_copy(temp->content));
			i++;
		}
		if (temp->content[i] == '=' && to_find[i] == '\0')
		{
			return (str_copy(temp->content));
		}
		temp = temp->next;
	}
	return (NULL);
}

int	find_env(char *to_find, char **pool)
{
	int	i;
	int	j;

	if (pool == NULL || to_find == NULL)
	{
		return (-1);
	}
	i = 0;
	while (pool[i])
	{
		j = 0;
		while (pool[i][j] && pool[i][j] == to_find[j])
		{
			if (pool[i][j] == '=' && (to_find[j] == '\0' || to_find[j] == '='))
				return (i);
			j++;
		}
		if (pool[i][j] == '=' && (to_find[j] == '\0' || to_find[j] == '='))
			return (i);
		i++;
	}
	return (-1);
}
