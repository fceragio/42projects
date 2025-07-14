/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:31:19 by federico          #+#    #+#             */
/*   Updated: 2025/06/08 02:04:35 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//remove extra newlines in the program please

void	print_error(char *error)
{
	char	new_line;

	new_line = '\n';
	if (error != NULL)
	{
		write(2, error, string_len(error));
		write(2, &new_line, 1);
	}
}

void	manage_error(int er_type, char *error, t_program *shell)
{
	print_error(error);
	shell->exit_status = er_type;
}

void	manage_critical_error(int er_type, char *error, t_program *shell)
{
	perror(error);
	shell->exit_status = er_type;
	shell_clean(shell);
	exit(er_type);
}
