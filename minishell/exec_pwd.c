/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:01:16 by federico          #+#    #+#             */
/*   Updated: 2025/06/14 00:27:26 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_pwd(t_tree *node, t_program *shell)
{
	char	*buffer;

	(void)node;
	buffer = malloc(sizeof(char) * BUFFER_LIMIT);
	if (buffer == NULL)
	{
		manage_critical_error(MALLOC_ERR, "exec_pwd ERROR: malloc", shell);
	}
	buffer = getcwd(buffer, BUFFER_LIMIT);
	if (buffer)
	{
		printf("%s\n", buffer);
		shell->exit_status = SUCCESS;
	}
	else
	{
		manage_error(CMD_ERR, "pwd: couldn't get working directory", shell);
	}
	free(buffer);
}
