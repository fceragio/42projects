/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:44:20 by federico          #+#    #+#             */
/*   Updated: 2025/07/10 20:06:26 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tree	*parsing(t_list *token_list, t_program *shell)
{
	t_tree	*parsed_tree;

	if (assign_token_id(&token_list, shell) == NO)
	{
		list_reset(&shell->token_list);
		return (NULL);
	}
	parsed_tree = create_tree(&token_list, shell);
	list_reset(&shell->token_list);
	return (parsed_tree);
}

int	assign_token_id(t_list **token_list, t_program *shell)
{
	if (identify_pipes(token_list) == NO)
	{
		manage_error(SYNTAX_ERR, "invalid token after pipe", shell);
		return (NO);
	}
	if (identify_redirections(token_list) == NO)
	{
		manage_error(SYNTAX_ERR, "invalid token after redirection", shell);
		return (NO);
	}
	identify_assignations(token_list);
	find_and_translate_envs(token_list, shell);
	remove_quotes(token_list, shell);
	find_and_substitute_heredocs(token_list, shell);
	restore_sigaction(shell->sa);
	if (g_sig == SIGINT)
	{
		g_sig = 0;
		return (NO);
	}
	identify_commands(token_list);
	adjust_token(token_list, shell);
	return (YES);
}

t_tree	*create_tree(t_list **token_list, t_program *shell)
{
	t_tree	*root;

	root = create_tree_node(list_last(*token_list), shell);
	return (root);
}
