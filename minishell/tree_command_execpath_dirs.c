/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_command_execpath_dirs.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 01:19:15 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 18:39:57 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	copy_sngl_path(char *path, char ***path_dirs, t_path_indices *idx);

char	**get_path_dirs(char **command_env, t_program *shell)
{
	char	**path_dirs;
	char	*path;
	int		dir_num;

	path = custom_get_env("PATH", command_env);
	if (path == NULL)
	{
		return (NULL);
	}
	dir_num = dir_qnt(path);
	if (dir_num <= 0)
	{
		free(path);
		return (NULL);
	}
	path_dirs = malloc(sizeof(char *) * (dir_num + 1));
	if (path_dirs == NULL)
	{
		manage_critical_error(MALLOC_ERR, "get_path_dirs", shell);
	}
	split_path_dirs(&path_dirs, path, dir_num, shell);
	free(path);
	return (path_dirs);
}

void	split_path_dirs(char ***path_dirs,
			char *path, int qnt, t_program *shell)
{
	int				len;
	t_path_indices	idx;

	idx.i = 0;
	idx.j = 0;
	while (idx.i < qnt)
	{
		idx.k = 0;
		len = dir_len(path + idx.j);
		(*path_dirs)[idx.i] = malloc(sizeof(char) * (len + 1));
		if ((*path_dirs)[idx.i] == NULL)
		{
			clean_path_dirs(*path_dirs);
			manage_critical_error(MALLOC_ERR, "split_path_dirs", shell);
		}
		copy_sngl_path(path, path_dirs, &idx);
	}
	(*path_dirs)[idx.i] = NULL;
}

static void	copy_sngl_path(char *path, char ***path_dirs, t_path_indices *idx)
{
	while (path[idx->j] && path[idx->j] != ':')
	{
		(*path_dirs)[idx->i][idx->k++] = path[idx->j++];
	}
	(*path_dirs)[idx->i++][idx->k] = '\0';
	if (path[idx->j] == ':')
		idx->j++;
}
