/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_list_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:47:16 by federico          #+#    #+#             */
/*   Updated: 2025/06/14 00:27:38 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	list_check_redirect(t_list *list)
{
	t_list	*last_node;

	last_node = list_last(list);
	if (last_node == NULL)
		return (NO);
	if (strings_are_equal(">", last_node->content)
		|| strings_are_equal(">>", last_node->content)
		|| strings_are_equal("<", last_node->content)
		|| strings_are_equal("<<", last_node->content))
	{
		return (YES);
	}
	else
		return (NO);
}

static char	*copy_token(char *str, int i, int len, t_program *shell)
{
	char	*result;
	int		j;

	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
	{
		manage_critical_error(MALLOC_ERR, "copy_token", shell);
	}
	j = 0;
	while (j < len)
	{
		result[j] = str[i];
		j++;
		i++;
	}
	result[j] = '\0';
	return (result);
}

void	list_add(t_list **list, char *str, t_token_info *info, t_program *shell)
{
	char	*token;
	t_list	*new_node;

	token = copy_token(str, info->i, info->len, shell);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		manage_critical_error(MALLOC_ERR, "list_add", shell);
	}
	new_node->token_len = info->len;
	list_append(list, new_node, token);
	info->i += info->len;
}
