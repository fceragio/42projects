/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_identify_redirections.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:38:27 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 13:46:22 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redir_output_if(t_list **temp, int *just_redirected, int *fail);
static int	redir_input_if(t_list **temp, int *just_redirected, int *fail);
static int	redir_invalid_if(t_list **temp, int *just_redirected, int *fail);

int	identify_redirections(t_list **token_list)
{
	t_list	*temp;
	int		just_redirected;
	int		fail;

	temp = *token_list;
	just_redirected = NO;
	fail = NO;
	while (temp)
	{
		if (redir_output_if(&temp, &just_redirected, &fail))
			temp = temp->next;
		else if (redir_input_if(&temp, &just_redirected, &fail))
			temp = temp->next;
		else if (redir_invalid_if(&temp, &just_redirected, &fail))
			temp = temp->next;
		else
		{
			temp = temp->next;
			just_redirected = NO;
		}
	}
	if (fail == YES)
		return (NO);
	return (YES);
}

static int	redir_output_if(t_list **temp, int *just_redirected, int *fail)
{
	if (strings_are_equal(">", (*temp)->content) == YES
		|| strings_are_equal(">>", (*temp)->content) == YES)
	{
		if (*just_redirected == YES)
		{
			*fail = YES;
		}
		else
		{
			(*temp)->token_id = REDIRECT_OUTPUT;
			*just_redirected = YES;
		}
		return (YES);
	}
	return (NO);
}

static int	redir_input_if(t_list **temp, int *just_redirected, int *fail)
{
	if (strings_are_equal("<", (*temp)->content) == YES
		|| strings_are_equal("<<", (*temp)->content) == YES)
	{
		if (*just_redirected == YES)
		{
			*fail = YES;
		}
		else
		{
			(*temp)->token_id = REDIRECT_INPUT;
			*just_redirected = YES;
		}
		return (YES);
	}
	return (NO);
}

static int	redir_invalid_if(t_list **temp, int *just_redirected, int *fail)
{
	if (*just_redirected == YES)
	{
		if (strings_are_equal("|", (*temp)->content) == YES
			|| strings_are_equal("\n", (*temp)->content) == YES)
		{
			*just_redirected = NO;
			*fail = YES;
		}
		else
		{
			(*temp)->token_id = REDIRECTION_ARG;
			*just_redirected = NO;
		}
		return (YES);
	}
	return (NO);
}
