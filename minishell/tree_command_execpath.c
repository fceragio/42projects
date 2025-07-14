/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_command_execpath.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:16:37 by federico          #+#    #+#             */
/*   Updated: 2025/06/12 00:00:30 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	name_is_builtin(char *name);
static int	name_is_path(char *name);
static char	*found_executable(DIR *dir,
				char *path_dirs, char *name, t_program *shell);

char	*set_command_exec_path(char *name, char **command_env, t_program *shell)
{
	if (name_is_builtin(name) == YES)
	{
		return (NULL);
	}
	if (name_is_path(name) && access(name, F_OK) == 0)
	{
		return (str_copy(name));
	}
	return (find_executable(name, command_env, shell));
}

static int	name_is_path(char *name)
{
	int	i;

	if (name == NULL)
	{
		return (NO);
	}
	i = 0;
	while (name[i])
	{
		if (name[i] == '/')
		{
			return (YES);
		}
		i++;
	}
	return (NO);
}

static int	name_is_builtin(char *name)
{
	if (strings_are_equal("exit", name) || strings_are_equal("echo", name)
		|| strings_are_equal("export", name) || strings_are_equal("unset", name)
		|| strings_are_equal("env", name) || strings_are_equal("cd", name))
	{
		return (YES);
	}
	return (NO);
}

char	*find_executable(char *name, char **command_env, t_program *shell)
{
	int		i;
	char	**path_dirs;
	DIR		*dir;
	char	*result;

	path_dirs = get_path_dirs(command_env, shell);
	if (path_dirs == NULL)
		return (NULL);
	i = 0;
	while (path_dirs[i])
	{
		dir = opendir(path_dirs[i]);
		result = found_executable(dir, path_dirs[i], name, shell);
		if (result != NULL)
		{
			closedir(dir);
			clean_path_dirs(path_dirs);
			return (result);
		}
		closedir(dir);
		i++;
	}
	clean_path_dirs(path_dirs);
	return (NULL);
}

static char	*found_executable(DIR *dir, char *path_dirs,
				char *name, t_program *shell)
{
	char			*result;
	struct dirent	*stream_next;

	if (dir == NULL)
		return (NULL);
	stream_next = readdir(dir);
	while (stream_next != NULL)
	{
		if (strings_are_equal(name, stream_next->d_name))
		{
			result = malloc(sizeof(char) * (string_len(path_dirs)
						+ string_len(name) + 2));
			if (result == NULL)
			{
				closedir(dir);
				clean_path_dirs(&path_dirs);
				manage_critical_error(MALLOC_ERR, "find_executable", shell);
			}
			set_executable(&result, path_dirs, name);
			return (result);
		}
		stream_next = readdir(dir);
	}
	return (NULL);
}
