/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_find_and_translate_envs_exitcode.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 00:48:57 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 19:07:54 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fill_index_struct(t_assemble_indices *idx, char *env, int i)
{
	idx->i = i - 1 - string_len(env);
	idx->skip_len = string_len(env) + 1;
	idx->j = 0;
	idx->k = 0;
	idx->l = 0;
}

void	token_substitute_with_last_exit_code(char *env,
		t_list **temp, int i, t_program *shell)
{
	char				*env_value;
	char				*new_str;
	char				*str;
	t_assemble_indices	idx;

	env_value = int_to_str(shell->exit_status, shell);
	str = (*temp)->content;
	fill_index_struct(&idx, env, i);
	new_str = malloc(sizeof(char) * (string_len(str)
				- (string_len(env) + 1) + string_len(env_value) + 1));
	if (new_str == NULL)
	{
		manage_critical_error(MALLOC_ERR,
			"token_substitute_with_last_exit_code", shell);
	}
	assemble_new_str(new_str, env_value, str, &idx);
	free(env_value);
	free(str);
	(*temp)->content = new_str;
	(*temp)->token_len = string_len(new_str);
}

int	int_len(int x)
{
	long	num;
	int		len;

	num = x;
	len = 0;
	if (num <= 0)
	{
		len++;
		num = -num;
	}
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*int_to_str(int x, t_program *shell)
{
	char	*result;
	long	num;
	int		len;
	int		minus;

	len = int_len(x);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		manage_critical_error(MALLOC_ERR, "int_to_str", shell);
	num = x;
	minus = 0;
	if (num < 0)
	{
		result[minus++] = '-';
		num = -num;
	}
	result[len--] = '\0';
	while (len >= minus)
	{
		result[len--] = (num % 10) + '0';
		num = num / 10;
	}
	return (result);
}
