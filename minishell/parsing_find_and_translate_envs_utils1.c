/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_find_and_translate_envs_utils1.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 00:42:02 by federico          #+#    #+#             */
/*   Updated: 2025/06/12 00:05:00 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	copy_till_env(char *new_s, char *old, t_assemble_indices *idx);
static void	set_j_to_end_of_env(t_assemble_indices *idx);

void	realloc_token_content(t_list *token_node, char *clean_buffer,
			int len, t_program *shell)
{
	char	*new_content;
	int		i;

	new_content = malloc(sizeof(char) * (len + 1));
	if (new_content == NULL)
	{
		manage_critical_error(MALLOC_ERR, "realloc_token_content", shell);
	}
	i = 0;
	while (i < len)
	{
		new_content[i] = clean_buffer[i];
		i++;
	}
	new_content[i] = '\0';
	free(token_node->content);
	token_node->content = new_content;
	token_node->token_len = len;
}

void	token_substitute_env(char *env, t_list **temp, int i, t_program *shell)
{
	char				*env_value;
	char				*new_str;
	char				*str;
	t_assemble_indices	idx;

	env_value = find_env_value(env, shell);
	str = (*temp)->content;
	idx.i = i - 1 - string_len(env);
	idx.skip_len = string_len(env) + 1;
	new_str = malloc(sizeof(char) * (string_len(str)
				- (string_len(env) + 1) + string_len(env_value) + 1));
	if (new_str == NULL)
	{
		manage_critical_error(MALLOC_ERR, "token_substitute_env", shell);
	}
	assemble_new_str(new_str, env_value, str, &idx);
	free(env_value);
	free(str);
	(*temp)->content = new_str;
	(*temp)->token_len = string_len(new_str);
}

void	assemble_new_str(char *new_s, char *to_insert,
			char *old, t_assemble_indices *idx)
{
	idx->j = 0;
	idx->k = 0;
	idx->l = 0;
	copy_till_env(new_s, old, idx);
	set_j_to_end_of_env(idx);
	while (idx->l < string_len(to_insert))
	{
		new_s[idx->k++] = to_insert[idx->l++];
	}
	while (old[idx->j])
	{
		new_s[idx->k++] = old[idx->j++];
	}
	new_s[idx->k] = '\0';
}

static void	copy_till_env(char *new_s, char *old, t_assemble_indices *idx)
{
	while (old[idx->j] && idx->j < idx->i)
	{
		new_s[idx->k++] = old[idx->j++];
	}
}

static void	set_j_to_end_of_env(t_assemble_indices *idx)
{
	while (idx->skip_len > 0)
	{
		idx->j++;
		idx->skip_len--;
	}
}
