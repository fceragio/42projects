/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export_valid_identifier.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 22:36:29 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 22:40:04 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	valid_identifier(char *arg)
{
	int	i;

	if (arg == NULL)
		return (NO);
	i = 0;
	if (arg[i] != '_' && (arg[i] < 'A' || arg[i] > 'Z')
		&& (arg[i] < 'a' || arg[i] > 'z'))
		return (NO);
	i++;
	while (arg[i] && arg[i] != '=')
	{
		if (arg[i] != '_' && (arg[i] < '0'
				|| arg[i] > '9') && (arg[i] < 'A'
				|| arg[i] > 'Z') && (arg[i] < 'a' || arg[i] > 'z'))
			return (NO);
		i++;
	}
	if (arg[i] == '=' || arg[i] == '\0')
		return (YES);
	else
		return (NO);
}
