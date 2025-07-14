/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:56:19 by federico          #+#    #+#             */
/*   Updated: 2025/06/10 22:53:43 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_echo(t_tree *node, t_program *shell)
{
	int	i;
	int	flag;

	flag = NO;
	i = 1;
	if (strings_are_equal("-n", node->cmd_args[i]))
	{
		flag = YES;
		i++;
	}
	while (node->cmd_args[i])
	{
		printf("%s", node->cmd_args[i]);
		if (node->cmd_args[i + 1])
		{
			printf(" ");
		}
		i++;
	}
	if (flag == NO)
	{
		printf("\n");
	}
	shell->exit_status = SUCCESS;
}
