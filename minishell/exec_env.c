/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:03:14 by federico          #+#    #+#             */
/*   Updated: 2025/06/10 22:47:50 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_env(t_tree *node, t_program *shell)
{
	if (node->vars)
	{
		print_string_array(node->vars);
	}
	shell->exit_status = SUCCESS;
}

void	print_string_array(char **strings)
{
	int	i;

	if (strings == NULL)
	{
		return ;
	}
	i = 0;
	while (strings[i])
	{
		printf("%s\n", strings[i]);
		i++;
	}
}
