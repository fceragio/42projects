/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_command_execpath_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 01:11:30 by federico          #+#    #+#             */
/*   Updated: 2025/06/10 19:15:26 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_executable(char **executable, char *path, char *name)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (path[j])
	{
		(*executable)[i++] = path[j++];
	}
	(*executable)[i++] = '/';
	j = 0;
	while (name[j])
	{
		(*executable)[i++] = name[j++];
	}
	(*executable)[i] = '\0';
}

void	clean_path_dirs(char **path_dirs)
{
	int	i;

	if (path_dirs == NULL)
	{
		return ;
	}
	i = 0;
	while (path_dirs[i])
	{
		free(path_dirs[i]);
		i++;
	}
	free(path_dirs);
}

int	dir_len(char *path)
{
	int	len;

	if (path == NULL)
	{
		return (0);
	}
	len = 0;
	while (path[len] && path[len] != ':')
	{
		len++;
	}
	return (len);
}

int	dir_qnt(char *path)
{
	int	qnt;
	int	i;

	qnt = 0;
	if (path == NULL)
		return (0);
	qnt++;
	i = 0;
	while (path[i])
	{
		if (path[i] == ':')
			qnt++;
		i++;
	}
	return (qnt);
}
